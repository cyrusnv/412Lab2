#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ir.h"

// Function Declarations
void rename_registers(struct Instruction *ir);
void print_allocated_code(struct Instruction *ir);
int handleThree(struct Instruction *currOp, int VRName, int index);
int handleStore(struct Instruction *currOp, int VRName, int index);
int handleLoad(struct Instruction *currOp, int VRName, int index);
int handleLoadI(struct Instruction *currOp, int VRName);
void print_renamed_code(struct Instruction *ir);
void reallocate_registers(struct Instruction *ir);
void push(int pr);
int pop();
void clearMarks();
int spill(struct Instruction* op, int vir_reg, int phys_reg);
int restore(struct Instruction* op, int vir_reg, int phys_reg);
int pickPRtospill();
int freepr(int pr);


void allocHandleThree(struct Instruction *op);
void allocHandleLoadI(struct Instruction *op);
void allocHandleLoad(struct Instruction *op);
void allocHandleStore(struct Instruction *op);


// Global Maps
int *SRtoVR = NULL;
int *LU = NULL;

int *VRtoPR = NULL;
int *VRtoSpillLoc = NULL;
int *PRtoVR = NULL;
int *PRNU = NULL;

int *PRmarker = NULL;

/* Global Variables */
// Keep track of the # of PRs available and MAXLIVE accounting.
int maxlive = 0;
int livecount = 0;
int prcount;
int usableprcount;
bool reserveregister = false;
// Keep track of your PR stack for allocation.
int *prstack = NULL;
int stacktop = 0;
// Address for where the next value will be spilled to, if necessary.
int next_spill_loc = 32768;

int main(int argc, char **argv)
{
    // Handle -h flag
    if (argc > 1 && strcmp(argv[1], "-h") == 0)
    {
        printf("Command Syntax:\n");
        printf("    ./412alloc k filename\n");
        printf("    k is the number of registers to use (3-64)\n");
        return 0;
    }
    else if (argc > 1 && strcmp(argv[1], "-x") != 0)
    {
        // Check arguments
        if (argc != 3)
        {
            fprintf(stderr, "Usage: 412alloc k filename\n");
            return 1;
        }
    } else if (argc > 1) {

        // Parse k value
        prcount = atoi(argv[1]);
        if (prcount < 3 || prcount > 64)
        {
            fprintf(stderr, "ERROR: k must be between 3 and 64\n");
            return 1;
        }
    }

    // Build IR using your Lab 1 code
    // Cyrus you'll need to check to make sure the file is valid here...
    struct Instruction *ir = buildIR(argv[2]);
    if (ir == NULL)
    {
        return 1; // Error already printed by buildIR
    }

    // Perform register renaming
    rename_registers(ir);

    // Perform register allocation.
    reallocate_registers(ir);

    // Print out the new IR!
    printIR2(ir);

    // Print the renamed code
    print_renamed_code(ir);

    // Print the transformed code
    // print_allocated_code(ir);

    // Clean up
    // TODO: Add cleanup code for IR

    return 0;
}

// Function to perform register allocation
void rename_registers(struct Instruction *ir)
{

    // Your counter for VRnames
    int VRName = 0;
    // Set up your renaming maps...
    int mapsize = opcount * 3;
    SRtoVR = malloc(mapsize * sizeof(int));
    LU = malloc(mapsize * sizeof(int));
    for (int i = 0; i < mapsize; i++)
    {
        SRtoVR[i] = -1;
        LU[i] = -1;
    }

    // Main loop over the operations, bottom to top
    struct Instruction *currOp = ir->prev->prev;
    int index = (currOp->line) - 1;
    while (currOp->line != 0)
    {
        int currCode = currOp->opcode;
        // printf("line: %d\n", currOp->line);
        // printf("currCode: %d\n\n", currCode);

        // There are basically five versions that I'm going to do, based on the operand.
        if (currCode == ADD || currCode == SUB || currCode == MULT || currCode == LSHIFT || currCode == RSHIFT)
        {
            VRName = handleThree(currOp, VRName, index);
        }
        else if (currCode == STORE)
        {
            VRName = handleStore(currOp, VRName, index);
        }
        else if (currCode == LOAD)
        {
            VRName = handleLoad(currOp, VRName, index);
        }
        else if (currCode == LOADIL)
        {
            VRName = handleLoadI(currOp, VRName);
        }

        currOp = currOp->prev;
        index--;

        if (livecount > maxlive)
        {
            maxlive = livecount;
        }
    }
}

void reallocate_registers(struct Instruction *ir) {
    // Initialize VRtoPR and VRtoSpillLoc
    int mapsize = opcount * 3;
    VRtoPR = malloc(mapsize * sizeof(int));
    VRtoSpillLoc = malloc(mapsize * sizeof(int));
    for (int i = 0; i < mapsize; i++) {
        VRtoPR[i] = -1;
        VRtoSpillLoc[i] = -1;
    }

    // Know whether or not you're going to reserve the last register
    // Initialize the pr stack
    if (maxlive > prcount) {
        reserveregister = true;
        prstack = malloc((prcount - 1) * sizeof(int));
        usableprcount = prcount - 1;
    } else {
        prstack = malloc(prcount * sizeof(int));
        usableprcount = prcount;
    }

    // Initialize PRtoVR, PRNU
    PRtoVR = malloc(usableprcount * sizeof(int));
    PRNU = malloc(usableprcount * sizeof(int));
    for (int i = 0; i < usableprcount; i++) {
        PRtoVR[i] = -1;
        PRNU[i] = -1;
        push(i);
    }

    // Initialize your marking list
    PRmarker = malloc(usableprcount *sizeof(int));

    // Now the fun stuff: you gotta iterate over the block
    struct Instruction *op = ir->next;
    while (op->line != -1) {
        // clear the mark in each PR
        clearMarks();

        int currCode = op->opcode;
        // printf("line: %d\n", op->line);
        // printf("currCode: %d\n\n", currCode);

        // There are basically five versions that I'm going to do, based on the operand.
        if (currCode == ADD || currCode == SUB || currCode == MULT || currCode == LSHIFT || currCode == RSHIFT)
        {
            allocHandleThree(op);
        }
        else if (currCode == STORE)
        {
            allocHandleStore(op);
        }
        else if (currCode == LOAD)
        {
            allocHandleLoad(op);
        }
        else if (currCode == LOADIL)
        {
            allocHandleLoadI(op);
        }
    }
}

void clearMarks() {
    for(int i = 0; i < usableprcount; i++) {
        PRmarker[i] = 0;
    }
}

/* Inputs
 *  vir_reg: the virtual register we are trying to assign a physical register to.
 *  next_use: the instruction in which vir_reg is next used.
 *  op: the current instruction we are attempting to allocate.
 */
int getPR(struct Instruction* op, int vir_reg, int next_use) {
    // If the PR is free... (you should have a stack)
    int pr;
    if (stacktop > 0) {
        pr = pop();
    } else {
        pr = pickPRtospill();
        spill(op, vir_reg, pr);
    }

    // Update your maps
    VRtoPR[vir_reg] = pr;
    PRtoVR[pr] = vir_reg;
    PRNU[pr] = next_use;

    return(pr);
}

/*
 * Frees the PR given—in essence, it updates values in the appropriate maps. Nothing crazy.
 *
 * Inputs:
 *  pr: the physical register (an int) that will be freed.
 * 
 */
int freepr(int pr) {
    VRtoPR[PRtoVR[pr]] = -1;
    PRtoVR[pr] = -1;
    PRNU[pr] = -1;
    push(pr);

    return (1);
}


// Helper function that performs the search for a a PR to spill.
int pickPRtospill() {
    int currPR = -1;
    int currNU = -1;
    for (int i = 0; i < prcount; i++) {
        if (PRNU[i] > currNU) {
            currPR = i;
            currNU = PRNU[i];
        }
    }
    return(currPR);
}

/* Inputs
 *  op: the current instruction being reallocated.
 *  vir_reg: the virtual register we wish to assign a physical register to.
 *  phys_reg: the physcial register being freed / reallocated. At the time it's called, it is occupied.
 */
int spill(struct Instruction* op, int vir_reg, int phys_reg) {
    // Get the next memory value
    int memval;
    if (VRtoSpillLoc[PRtoVR[phys_reg]] == -1) {
        memval = next_spill_loc;
        next_spill_loc += 4;
        VRtoSpillLoc[PRtoVR[phys_reg]] = memval;

    } else {
        memval = VRtoSpillLoc[PRtoVR[phys_reg]];
    }
    

    // Do a general-purpose spill: insert LOADI and STORE.
    struct Instruction *loadIInstr = malloc(sizeof(struct Instruction));
    struct Instruction *storeInstr = malloc(sizeof(struct Instruction));

    loadIInstr->opcode = LOADIL;
    loadIInstr->vr1 = memval;
    loadIInstr->pr1 = memval;
    loadIInstr->pr3 = prcount - 1;

    storeInstr->opcode = STORE;
    storeInstr->vr1 = PRtoVR[phys_reg];
    storeInstr->pr1 = phys_reg;
    storeInstr->pr3 = prcount - 1;

    if (insert_instr_after(loadIInstr, op->prev) != 0) {
        printf("Error with IR insertion in spill (LOADI). Uh oh.\n");
    }

    if (insert_instr_after(storeInstr, op->prev) != 0) {
        printf("Error with IR insertion in spill (STORE). Uh oh.\n");
    } 
    
    // I believe these updates are necessary based on the textbook—but
    // it's possible that these are already taken care of immediately following the spill
    // function, no?
    // These might need work, but you can think it through. Not now though.
    VRtoPR[PRtoVR[phys_reg]] = -1;
    PRtoVR[phys_reg] = -1;
    PRNU[phys_reg] = -1;

    //TODO: some error control flow, yeah?
    return (1);

}


/* Inputs
 *  op: the current instruction being reallocated
 *  vir_reg: the virtual register whose value we want back (the one we try to restore).
 *  phys_reg: the physical register we're going to attempt to store the virtual register into, now that we can.
 * 
 */
int restore(struct Instruction* op, int vir_reg, int phys_reg) {
    
    // Do a general-purpose restore: insert LOADI and LOAD.
    struct Instruction *loadIInstr = malloc(sizeof(struct Instruction));
    struct Instruction *loadInstr = malloc(sizeof(struct Instruction));

    int memval = VRtoSpillLoc[vir_reg];

    loadIInstr->opcode = LOADIL;
    loadIInstr->vr1 = memval;
    loadIInstr->pr1 = memval;
    loadIInstr->pr3 = prcount - 1;

    loadInstr->opcode = LOAD;
    loadInstr->pr1 = prcount - 1;
    loadInstr->pr3 = phys_reg;

    if (insert_instr_after(loadIInstr, op->prev) != 0) {
        printf("Error with IR insertion in restore (LOADI). Uh oh.\n");
    }

    if (insert_instr_after(loadInstr, op->prev) != 0) {
        printf("Error with IR insertion in restore (LOAD). Uh oh.\n");
    } 

    // I believe these updates are necessary based on the textbook—but
    // it's possible that these are already taken care of immediately following the restore
    VRtoPR[vir_reg] = phys_reg;
    PRtoVR[phys_reg] = vir_reg;

    // Actually, I don't know exactly what this should be. Awesome.
    //PRNU[phys_reg] = ;

    // TODO: Error handling. You should probably do it now, even.
    return (1);

}

// Helper function for reallocation pass on an operation with three operands.
void allocHandleThree(struct Instruction *op) {
    /* Used operand 1 */
    if (VRtoPR[op->sr1] == -1) {
        op->pr1 = getPR(op, op->vr1, op->nu1);
        restore(op, op->vr1, op->pr1);
    } else {
        op->pr1 = VRtoPR[op->sr1];
    }
    // Set the mark.
    PRmarker[op->pr1] = 1;

    /* Used operatnd 2 */
    if (VRtoPR[op->sr2] == -1) {
        op->pr2 = getPR(op, op->vr2, op->nu2);
        restore(op, op->vr2, op->pr2);
    } else {
        op->pr2 = VRtoPR[op->sr2];
    }
    // Set the mark.
    PRmarker[op->pr2] = 1;


    /* Free used operands if last use */
    if (op->nu1 == -1 && PRtoVR[op->pr1] != -1) {
        freepr(op->pr1);
    } else if (op->nu2 == -1 && PRtoVR[op->pr2] != -1) {
        freepr(op->pr2);
    }

    /* Clear marks in each PR */
    clearMarks();

    /* Allocate defs! */
    op->pr3 = getPR(op, op->vr3, op->nu3);
    // Set the mark for pr3, or something. I don't like how they use "in", though...
    PRmarker[op->pr3] = 1;
}

/*
 * Helper function for reallocation pass that handles a loadI instruction.
 * 
 * Inputs:
 *  - op: the loadI operation being allocated.
 *
 * Output:
 *  - None. You're getting nothing out of this guy—it just does it's job.
 */
void allocHandleLoadI(struct Instruction *op) {
    
    /* Clear marks in each PR */
    // I don't think I need this, but I don't think it hurts.
    clearMarks();

    /* Allocate defs! */
    op->pr3 = getPR(op, op->vr3, op->nu3);
    // Set the mark for pr3
    PRmarker[op->pr3] = 1;
}

/*
 * Helper function for reallocation pass that handles a load instruction.
 * 
 * Inputs:
 *  - op: the loadI operation being allocated.
 *
 * Output:
 *  - None. You're getting nothing out of this guy—it just does it's job.
 */
void allocHandleLoad(struct Instruction *op) {
    /* Used operand 1 */
    if (VRtoPR[op->sr1] == -1) {
        op->pr1 = getPR(op, op->vr1, op->nu1);
        restore(op, op->vr1, op->pr1);
    } else {
        op->pr1 = VRtoPR[op->sr1];
    }
    // Set the mark.
    PRmarker[op->pr1] = 1;

    /* Free used operands if last use */
    if (op->nu1 == -1 && PRtoVR[op->pr1] != -1) {
        freepr(op->pr1);
    }

    /* Clear marks in each PR */
    clearMarks();

    /* Allocate defs! */
    op->pr3 = getPR(op, op->vr3, op->nu3);
    // Set the mark for pr3
    PRmarker[op->pr3] = 1;
}

/*
 * Helper function for reallocation pass that handles a store instruction.
 * 
 * Inputs:
 *  - op: the loadI operation being allocated.
 *
 * Output:
 *  - None. You're getting nothing out of this guy—it just does it's job.
 */
void allocHandleStore(struct Instruction *op) {
    /* Used operand 1 */
    if (VRtoPR[op->sr1] == -1) {
        op->pr1 = getPR(op, op->vr1, op->nu1);
        restore(op, op->vr1, op->pr1);
    } else {
        op->pr1 = VRtoPR[op->sr1];
    }
    // Set the mark.
    PRmarker[op->pr1] = 1;

    /* Used operand 2 */
    if (VRtoPR[op->sr2] == -1) {
        op->pr2 = getPR(op, op->vr2, op->nu2);
        restore(op, op->vr2, op->pr2);
    } else {
        op->pr2 = VRtoPR[op->sr2];
    }
    // Set the mark.
    PRmarker[op->pr2] = 1;


    /* Free used operands if last use */
    if (op->nu1 == -1 && PRtoVR[op->pr1] != -1) {
        freepr(op->pr1);
    } else if (op->nu2 == -1 && PRtoVR[op->pr2] != -1) {
        freepr(op->pr2);
    }

    /* Clear marks in each PR */
    clearMarks();
}

/* HELPER FUNCTIONS FOR RENAMING */

int handleThree(struct Instruction *currOp, int VRName, int index)
{
    /* Defined operand */
    if (SRtoVR[currOp->sr3] == -1)
    {
        SRtoVR[currOp->sr3] = VRName;
        VRName++;
        livecount++;
    }
    currOp->vr3 = SRtoVR[currOp->sr3];
    currOp->nu3 = LU[currOp->sr3];
    SRtoVR[currOp->sr3] = -1;
    LU[currOp->sr3] = -1;
    // livecount--;

    /* used operand 1 */
    if (SRtoVR[currOp->sr1] == -1)
    {
        SRtoVR[currOp->sr1] = VRName;
        VRName++;
    }
    currOp->vr1 = SRtoVR[currOp->sr1];
    currOp->nu1 = LU[currOp->sr1];
    // livecount++;

    /* used operand 2 */
    if (SRtoVR[currOp->sr2] == -1)
    {
        SRtoVR[currOp->sr2] = VRName;
        VRName++;
    }
    currOp->vr2 = SRtoVR[currOp->sr2];
    currOp->nu2 = LU[currOp->sr2];
    if (currOp->sr2 != currOp->sr1)
    {
        livecount++;
    }

    /* reset last uses for operands 1 and 2 to be index */
    LU[currOp->sr1] = index;
    LU[currOp->sr2] = index;

    return VRName;
}

int handleStore(struct Instruction *currOp, int VRName, int index)
{
    // NOTE: Treat both operands as uses here!
    /* used operand 1 */
    if (SRtoVR[currOp->sr1] == -1)
    {
        SRtoVR[currOp->sr1] = VRName;
        VRName++;
    }
    currOp->vr1 = SRtoVR[currOp->sr1];
    currOp->nu1 = LU[currOp->sr1];
    livecount++;

    /* used operand 2 */
    if (SRtoVR[currOp->sr3] == -1)
    {
        SRtoVR[currOp->sr3] = VRName;
        VRName++;
    }
    currOp->vr3 = SRtoVR[currOp->sr3];
    currOp->nu3 = LU[currOp->sr3];

    if (currOp->sr1 != currOp->sr3)
    {
        livecount++;
    }

    /* reset last uses for operands 1 and 2 to be index */
    LU[currOp->sr1] = index;
    LU[currOp->sr3] = index;

    return VRName;
}

int handleLoad(struct Instruction *currOp, int VRName, int index)
{
    /* Defined operand */
    if (SRtoVR[currOp->sr3] == -1)
    {
        SRtoVR[currOp->sr3] = VRName;
        VRName++;
        livecount++;
    }
    currOp->vr3 = SRtoVR[currOp->sr3];
    currOp->nu3 = LU[currOp->sr3];
    SRtoVR[currOp->sr3] = -1;
    LU[currOp->sr3] = -1;
    // livecount--;

    /* used operand 1 */
    if (SRtoVR[currOp->sr1] == -1)
    {
        SRtoVR[currOp->sr1] = VRName;
        VRName++;
    }
    currOp->vr1 = SRtoVR[currOp->sr1];
    currOp->nu1 = LU[currOp->sr1];
    // livecount++;

    /* reset last uses for operand 1 to be index */
    LU[currOp->sr1] = index;

    return VRName;
}

int handleLoadI(struct Instruction *currOp, int VRName)
{
    /* Defined operand */
    if (SRtoVR[currOp->sr3] == -1)
    {
        SRtoVR[currOp->sr3] = VRName;
        VRName++;
        livecount++;
    }
    currOp->vr3 = SRtoVR[currOp->sr3];
    currOp->nu3 = LU[currOp->sr3];
    SRtoVR[currOp->sr3] = -1;
    LU[currOp->sr3] = -1;

    livecount--;

    return VRName;
}

void print_renamed_code(struct Instruction *ir)
{
    struct Instruction *curr = ir->next; // Skip dummy head

    while (curr->line != -1)
    { // Until we hit end sentinel
        switch (curr->opcode)
        {
        case LOAD:
            printf("load r%d => r%d\n",
                   curr->vr1, curr->vr3);
            break;

        case STORE:
            printf("store r%d => r%d\n",
                   curr->vr1, curr->vr3);
            break;

        case LOADIL:
            printf("loadI %d => r%d\n",
                   curr->sr1, curr->vr3);
            break;

        case ADD:
            printf("add r%d, r%d => r%d\n",
                   curr->vr1, curr->vr2, curr->vr3);
            break;

        case SUB:
            printf("sub r%d, r%d => r%d\n",
                   curr->vr1, curr->vr2, curr->vr3);
            break;

        case MULT:
            printf("mult r%d, r%d => r%d\n",
                   curr->vr1, curr->vr2, curr->vr3);
            break;

        case LSHIFT:
            printf("lshift r%d, r%d => r%d\n",
                   curr->vr1, curr->vr2, curr->vr3);
            break;

        case RSHIFT:
            printf("rshift r%d, r%d => r%d\n",
                   curr->vr1, curr->vr2, curr->vr3);
            break;

        case OUTPUTL:
            printf("output %d\n", curr->sr1);
            break;

        case NOPL:
            printf("nop\n");
            break;
        }
        curr = curr->next;
    }
}


/* Stack operations. I'll be pissed if what I messed up was here. */

// Helper to push a new number onto the top of an array-based stack.
void push(int pr) {

    if (stacktop >= prcount) {
        printf("stacktop >= prcount. That's bad.\n");
        return;
    }

    prstack[stacktop] = pr;
    stacktop++;
}

int pop() {

    if (stacktop <= 0) {
        printf("stacktop <= 0. You probably shouldn't have called pop.\n");
        return(-1);
    }

    stacktop--;
    return prstack[stacktop];
}