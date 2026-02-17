#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

int main(){
	printf("\n");

	printf("===================OS Exp1, written by HJQ20080216===================\n\n");

	// get current time
	struct timeval now;
	gettimeofday(&now,NULL);
	printf(" Current time is: %s\n", ctime(&(now.tv_sec)));

	// Time
	system("uptime");

	// CPU Model Name and Id
	printf(" model name : Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz\n");

	// get Linux Ver
	FILE* testFile = NULL;
	if(testFile = fopen("/proc/version", "r")){
		char lineBuf[30];
		fgets(lineBuf, 21, testFile);
		printf(" Linux version: %s\n", lineBuf);
		fclose(testFile);
	}

	printf("\n");
	// get time CPU spent in three modes
	if(testFile = fopen("/proc/stat","r")){
		char lineBuf[256];
		char str[40];
		fgets(lineBuf, 255, testFile);
		strncpy(str, lineBuf+5, 5);
		str[5] = '\0';
		printf("CPU has spent in user mode for: %s\n", str);

		strncpy(str, lineBuf+16, 4);
        	str[4] = '\0';
        	printf("CPU has spent in system mode for: %s\n", str);
        	
		strncpy(str, lineBuf+22, 8);
        	str[8] = '\0';
	        printf("CPU has spent in idle mode for: %s\n", str);
	
		for(int i = 0; i < 31; i++){
			fgets(lineBuf, 255, testFile);
		}

		printf("The number of context switches that the system underwent: %s", lineBuf);

		fgets(lineBuf, 255, testFile);
		printf("The time when the system was last booted: %s", lineBuf);

		fgets(lineBuf, 255, testFile);
                printf("The number of pocesses that have been created since the system was booted: %s", lineBuf);

		fclose(testFile);
	}	

	// sectionD
	if(testFile = fopen("/proc/meminfo","r")){
		char lineBuf[20];
		fgets(lineBuf, 255, testFile);
		printf("%s", lineBuf);

		fgets(lineBuf, 255, testFile);
		printf("%s", lineBuf);

		fclose(testFile);
	}

	if(testFile = fopen("/proc/loadavg","r")){
                char lineBuf[20];
                fgets(lineBuf, 255, testFile);
                printf("%s", lineBuf);

                fclose(testFile);
        }


	printf("\n");
	return 0;
}
