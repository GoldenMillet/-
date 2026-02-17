#include <stdio.h>  
#include <unistd.h>  
  
int main(int args,char *argv[])  
{  
	if(fork()==0)
	{ 
       printf("I'm a new process to execute %s....\n", argv[1]);  
       execv(argv[1],NULL); 
       printf("execl failed to run ls\n");  //can not execute
	}
    return 0;  
}  
