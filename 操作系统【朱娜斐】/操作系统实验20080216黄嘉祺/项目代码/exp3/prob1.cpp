#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>

int main(int argv, char** argc){

	printf("I'm original process %d... I'm going to create 4 new processes!\n", getpid());

	if(getppid() == 8763){
		printf("I'm original process %d, and father of %d\n", getpid(), fork());
	} else {
		printf("I'm a new process. My id is %d, My father is %d\n", getpid(), getppid());
	}

	if(getppid() == 8763){
		printf("I'm original process %d, and father of %d\n", getpid(), fork());
	} else {
		printf("I'm a new process. My id is %d, My father is %d\n", getpid(), getppid());
	}

	if(getppid() == 8763){
		printf("I'm original process %d, and father of %d\n", getpid(), fork());
	} else {
		printf("I'm a new process. My id is %d, My father is %d\n", getpid(), getppid());
	}

	if(getppid() == 8763){
		printf("I'm original process %d, and father of %d\n", getpid(), fork());
	} else {
		printf("I'm a new process. My id is %d, My father is %d\n", getpid(), getppid());
	}

	return 0;
}
