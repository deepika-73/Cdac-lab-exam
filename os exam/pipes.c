#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;

	int fd[2];
//	0, 1, 2 are standard FD's that corresponds to STDIN_FILENO, 
//	STDOUT_FILENO and STDERR_FILENO (defined in unistd.h) opened by default on behalf of shell when the program starts.
	//int pipe(int fds[2]);

//Parameters :
//fd[0] will be the fd(file descriptor) for the 
//read end of pipe.
//fd[1] will be the fd for the write end of pipe.
//Returns : 0 on Success.
//-1 on error.

	int ret = pipe(fd);
	
	if (ret < 0)
	{
		printf("pipe command failed\n");
		return -2;
	}

	pid = fork();

	if (pid < 0)
	{
		return -1; // fork failed
	}

	if (pid > 0) //parent
	{
		char str1[100];
		close(fd[0]);

		printf("Enter your name\n");
		scanf("%s", str1);

		write(fd[1], str1, strlen(str1)+1);
		close(fd[1]);
	}
	else //child
	{
//		waitpid(pid, NULL, 0);
		char str2[100];
		close(fd[1]);
		read(fd[0], str2, sizeof(str2));
		printf("Child has passed: %s\n", str2);
		close(fd[0]);
	}

	return 0;

}
