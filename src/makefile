default: shell

all: clean shell

shell: shell.o stringLib.o IORedirect.o BackgroundJob.o pipes.o commandHistory.o
	gcc shell.o stringLib.o IORedirect.o BackgroundJob.o pipes.o commandHistory.o -o shell

shell.o: shell.c shell.h
	gcc -c shell.c

stringLib.o: stringLib.c stringLib.h
	gcc -c stringLib.c 

IORedirect.o: IORedirect.c IORedirect.h 
	gcc -c IORedirect.c

BackgroundJob.o: BackgroundJob.c BackgroundJob.h
	gcc -c BackgroundJob.c

pipes.o: pipes.c pipes.h
	gcc -c pipes.c 

commandHistory.o: commandHistory.c commandHistory.h
	gcc -c commandHistory.c


clean: 
	rm *.o shell