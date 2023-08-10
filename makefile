all: showMemery

showMemery: showMemery.c
	gcc-13 -o showMemery showMemery.c || gcc -o showMemery showMemery.c 
clean:
	rm -f showMemery