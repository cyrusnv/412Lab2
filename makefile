EXECUTABLE = 412fe
TARNAME = csn2.tar
FILES = scanner.c makefile README

all: build

build: $(EXECUTABLE)

$(EXECUTABLE): scanner.c
	gcc -o $(EXECUTABLE) scanner.c

clean:
	rm -f $(EXECUTABLE) *.o *~ core core.* vgcore.* $(TARNAME)

tar: $(FILES)
	tar -cvf $(TARNAME) $(FILES)

.PHONY: all build clean tar