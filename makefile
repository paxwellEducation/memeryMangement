all: showMemory

showMemory: showMemory.c
	gcc-13 -o showMemory showMemory.c || gcc -o showMemory showMemory.c 
clean:
	rm -f showMemory