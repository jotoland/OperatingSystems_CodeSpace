// include the necessary header files for code use
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
/*  Author: John G. Toland
	Class: CS 4352, Date: 04/15/17
	Project Description: 
		1) “Please enter an integer: ” to ask the users to input an integer number 
		   n (no checking, assume that users input a valid integer from 0 to 10).
		2) The parent process creates n children processes. It should print out an error
		   message if creation fails.
		3) Each child process print out a “my id: ” message together its PID and the
		   Fibonacci result on modulo 20 of its PID then exit.
		4) The parent process waits for all children processes to finish, print a message
		   “All child processes are now done!” and then exit.
*/
void  ChildProcess(void);
void  ParentProcess(void);
int   Fibonacci(int);

int main()
{
	// number of requested child processes
	int N;
	while (true){
		// message form parent with parent pid
		printf("[ello]: I am the parent... *PARENT* PID := %d \n",getpid());
		// prompt user for input
		printf("Enter the number of child process for me to create: \n");
		printf("Enter a integer: \n");
		// scan in the input
		scanf("%d", &N);
		// check if N is from 0 to 10
		if(N > -1 && N < 11){
			// if so then break from input loop and continue to for loop below
			break;
		}else{
			// input was not from 0 to 10, print error message and stay in input loop until input is excepted
			printf("\n[ello]: ERROR! Invalid input...\n");
			printf("[ello]: ...please enter an integer from 0 to 10.\nTry again...\n\n");
		}
	}
	// input has been excepted and now we can create N child processes
	printf("\n[ello]: Input excepted. %d Children to create.\nCreating...\n\n", N);
	for( int childCnt = 0; childCnt < N; childCnt ++ ){
		pid_t pid=fork();
		if( pid == 0 ){
			// now in child process, perfrom jobs for child
			ChildProcess();
			// break out of parents loop, child process do not iterate here.
			break;
		}else if(pid < 0){
			// error message when fork returns a negative value (fork fails)
			printf("\n[ello]: Error! Failed to Fork.\n");
		}else{
			// now in the parent proccess have the parent wait for the children process to finish before continuing
			int returnStatus;    
			waitpid(pid, &returnStatus, 0);	
		}
	}
	// all child process have been created and finished working their jobs.
	ParentProcess();
	// return out of main with 0;
	return 0;
}


void  ChildProcess(void){
	// send message from child with child pid and parent pid then exit the child process
	// calculate Fibonacci(PID%20) and print it out with the message
	printf("[ello]: *CHILD* PID := %d *FIBONACCI(%d%%20)* := %d *PARENT* PID := %d\n", getpid(), getpid(), Fibonacci(getpid()%20), getppid() );
	exit(0);
}

void  ParentProcess(void){
	// send message from parent process with parent pid saying all child process are finished
	printf("[ello]: *PARENT* PID := %d \n[MESSAGE]: All child processes are now done!\n",getpid());
}

//Fibonacci series using recursive function
int Fibonacci(int n){
	if (n <= 1){
		return n;
	}
	return Fibonacci(n-1) + Fibonacci(n-2);
}
//finito


