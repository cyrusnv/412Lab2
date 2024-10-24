#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ir.h"


// Function Declarations
void rename_registers(struct Instruction* ir);
void print_allocated_code(struct Instruction* ir);
int handleThree(struct Instruction* currOp, int VRName);
int handleStore(struct Instruction* currOp, int VRName);
int handleLoad(struct Instruction* currOp, int VRName);
int handleLoadI(struct Instruction* currOp, int VRName);

// Global Maps
int* SRtoVR = NULL;
int* LU = NULL;

// Global Variables


int main(int argc, char **argv) {
    // Handle -h flag
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        printf("Command Syntax:\n");
        printf("    ./412alloc k filename\n");
        printf("    k is the number of registers to use (3-64)\n");
        return 0;
    }
    
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: 412alloc k filename\n");
        return 1;
    }
    
    // Parse k value
    int k = atoi(argv[1]);
    if (k < 3 || k > 64) {
        fprintf(stderr, "ERROR: k must be between 3 and 64\n");
        return 1;
    }
    
    // Build IR using your Lab 1 code
    struct Instruction* ir = buildIR(argv[2]);
    if (ir == NULL) {
        return 1; // Error already printed by buildIR
    }
    
    // Perform register renaming
    rename_registers(ir);

    // Print out the new IR!
    printIR2(ir);
    
    // Print the transformed code
    //print_allocated_code(ir);
    
    // Clean up
    // TODO: Add cleanup code for IR
    
    return 0;
}

// Function to perform register allocation
void rename_registers(struct Instruction* ir) {

    // Your counter for VRnames
    int VRName = 0;
    // Set up your renaming maps...
    int mapsize = opcount * 3;
    SRtoVR = malloc(mapsize * sizeof(int));
    LU = malloc(mapsize * sizeof(int));
    for (int i = 0; i < mapsize; i++) {
        SRtoVR[i] = -1;
        LU[i] = -1;
    }

    // Main loop over the operations, bottom to top
    struct Instruction* currOp = ir->prev->prev;
    while (currOp->line != 0) {
        int currCode = currOp->opcode;
        // printf("line: %d\n", currOp->line);
        // printf("currCode: %d\n\n", currCode);

        // There are basically five versions that I'm going to do, based on the operand.
        if(currCode == ADD || currCode == SUB || currCode == MULT || currCode == LSHIFT || currCode == RSHIFT) {
            VRName = handleThree(currOp, VRName);
        } else if (currCode == STORE) {
            VRName = handleStore(currOp, VRName);
        } else if (currCode == LOAD) {
            VRName = handleLoad(currOp, VRName);
        } else if (currCode == LOADIL) {
            VRName = handleLoadI(currOp, VRName);
        }

        currOp = currOp->prev;
    }

}

int handleThree(struct Instruction* currOp, int VRName) {
    /* Defined operand */
    if(SRtoVR[currOp->sr3] == -1) {
        SRtoVR[currOp->sr3] = VRName;
        VRName++;
    }
    currOp->vr3 = SRtoVR[currOp->sr3];
    currOp->nu3 = LU[currOp->sr3];
    SRtoVR[currOp->sr3] = -1;
    LU[currOp->sr3] = -1;

    /* used operand 1 */
    if(SRtoVR[currOp->sr1] == -1) {
        SRtoVR[currOp->sr1] = VRName;
        VRName++;
    }
    currOp->vr1 = SRtoVR[currOp->sr1];
    currOp->nu1 = LU[currOp->sr1];

    /* used operand 2 */
    if(SRtoVR[currOp->sr2] == -1) {
        SRtoVR[currOp->sr2] = VRName;
        VRName++;
    }
    currOp->vr2 = SRtoVR[currOp->sr2];
    currOp->nu2 = LU[currOp->sr2];

    /* reset indexes for operands 1 and 2 */
    LU[currOp->sr1] = currOp->line;
    LU[currOp->sr2] = currOp->line;

    return VRName;
}

int handleStore(struct Instruction* currOp, int VRName) {
    // NOTE: Treat both operands as uses here!
    /* used operand 1 */
    if(SRtoVR[currOp->sr1] == -1) {
        SRtoVR[currOp->sr1] = VRName;
        VRName++;
    }
    currOp->vr1 = SRtoVR[currOp->sr1];
    currOp->nu1 = LU[currOp->sr1];

    /* used operand 2 */
    if(SRtoVR[currOp->sr3] == -1) {
        SRtoVR[currOp->sr3] = VRName;
        VRName++;
    }
    currOp->vr3 = SRtoVR[currOp->sr3];
    currOp->nu3 = LU[currOp->sr3];

    /* reset indexes for operands 1 and 2 */
    LU[currOp->sr1] = currOp->line;
    LU[currOp->sr3] = currOp->line;

    return VRName;
}

int handleLoad(struct Instruction* currOp, int VRName) {
    /* Defined operand */
    if(SRtoVR[currOp->sr3] == -1) {
        SRtoVR[currOp->sr3] = VRName;
        VRName++;
    }
    currOp->vr3 = SRtoVR[currOp->sr3];
    currOp->nu3 = LU[currOp->sr3];
    SRtoVR[currOp->sr3] = -1;
    LU[currOp->sr3] = -1;

    /* used operand 1 */
    if(SRtoVR[currOp->sr1] == -1) {
        SRtoVR[currOp->sr1] = VRName;
        VRName++;
    }
    currOp->vr1 = SRtoVR[currOp->sr1];
    currOp->nu1 = LU[currOp->sr1];

    /* reset indexes for operand 1 */
    LU[currOp->sr1] = currOp->line;

    return VRName;
}

int handleLoadI(struct Instruction* currOp, int VRName) {
    /* Defined operand */
    printf("At least I'm here?\n");
    if(SRtoVR[currOp->sr3] == -1) {
        printf("Boom I'm here\n");
        SRtoVR[currOp->sr3] = VRName;
        VRName++;
    }
    currOp->vr3 = SRtoVR[currOp->sr3];
    currOp->nu3 = LU[currOp->sr3];
    SRtoVR[currOp->sr3] = -1;
    LU[currOp->sr3] = -1;

    return VRName;
}