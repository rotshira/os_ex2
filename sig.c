
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signum)
{
	int i=5;
	int j=0;
	int k;
	switch (signum) 
    {
		case SIGCHLD: // dad is dead
			printf("1\n");
			raise(SIGUSR1);
		case SIGUSR1: // raise by user signal
			printf("2\n");
			k=i/j;
		case SIGFPE: //div by zero exception
			printf("3\n");
			fopen("non_existet_file","w");
        case SIGIO: // file not fount exception
            printf("4\n");
			alarm(1);
            sleep(1);
        case SIGALRM: //out of time exception
            printf("5\n");
            int a[1];
            a[2]=1;
        case SIGSEGV:   //out of bounds exception
            printf("6\n");
            exit(1);
		}
}
int main()
{
	int status;
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
	signal (SIGFPE, sig_handler);
    signal (SIGIO, sig_handler);
    signal (SIGALRM, sig_handler);
    signal (SIGSEGV, sig_handler);

	if (!(fork())) 
    {	
        exit(1);
	}
	wait(&status);

}