#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid, pid1, pid2;
	sleep(1);
	pid1 = fork();
	pid2 = fork();
	
	int parent_call_counter = 0;

	if (pid1 < 0 || pid2 < 0 )
	{
		printf("Fork is failed\n");
		return -1;
	}

	if (pid1 > 0 && pid2 > 0){
		// This is the parent code
		sleep(5);
		printf("%d : It is a parent process\n", getpid());
		printf("%d : parent's own id: %d\n",getpid(), getpid());

		while (parent_call_counter != 4) // wait till all the children exits
		{
			printf("%d : I am parent, waiting for my children to exit , counter : %d \n", getpid(), parent_call_counter);
			pid = wait(NULL);	
			// RETURNS ONLY HIS CHILDREN, GRAND CHILDREN WILL NOT BE ACCOUNTED FOR
			parent_call_counter++;
			printf("%d : Received one of my children, id : %d \n", getpid(), pid );
			printf("%d : parent's parent (terminal) id: %d\n", getpid(), getppid());
		}
		sleep(30);
	}
	else if (pid1 == 0 && pid2 > 0)
	{
		sleep(2);
		printf("%d : It is a 1st child process: %d\n",getpid(), getpid());
		printf("%d : 1st Child's parent process: %d\n",getpid(), getppid());
		sleep(20);
	}
	else if (pid1 > 0 && pid2 == 0 )
	{
		sleep(3);
		printf("%d : It is a 2nd child process: %d\n",getpid(), getpid());
		printf("%d : 2nd Child's parent process: %d\n",getpid(), getppid());
		sleep(20);
	}
	else
	{
		sleep(3);
		printf("%d : It is a Grand child process: %d\n",getpid(), getpid());
		printf("%d : Grand Child's parent process: %d\n",getpid(), getppid());
		sleep(20);		
	}

	printf("%d : Bye Bye \n",getpid());

	return 0;
}


/*
// Place this code at line no. 9, to make it work correctly
	if ( pid1 != 0 ){
		pid2 = fork();
	}
*/
