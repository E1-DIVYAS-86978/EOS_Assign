s
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main() {
	int signal, ret;
	printf("Enter the PID:\n");
	scanf("%d", &ret);

	printf("Enter the signal number:\n");
	scanf("%d", &signal);
	
        int p;
	p = kill(ret,signal);
	if(p == 0)
	{
		printf("Succes\n");
	}else{
		perror("Failed :");
	}
       return 0;
}       
