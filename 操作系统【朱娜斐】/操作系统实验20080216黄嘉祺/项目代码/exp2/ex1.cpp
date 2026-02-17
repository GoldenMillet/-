#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits.h>
#define BUFSZ 150

void err_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
int main(int argc, char *argv[]) {

start:
	FILE* fp;
	int count;
	char buf[BUFSZ];
	char command[150];
	sprintf(command, "ps -ef | grep vim | grep -v grep | wc -l" );
	
	if((fp = popen(command,"r")) == NULL)
		err_quit("popen");

	if( (fgets(buf,BUFSZ,fp))!= NULL ) {
		count = atoi(buf);
		
		if(count == 0) {
			printf("未查找到进程，即将组织运行\n");

			system("shell");
		}
		else printf("进程已经运行 %d\n",count);
	}
	
	pclose(fp);
	system("sleep 3");
	goto start;

	exit(EXIT_SUCCESS);

}
