#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int ret = mkfifo("mypipe2", O_CREAT | 0666);

	if (ret < 0)
	{
		printf("mkfifo command failed\n");
		return -2;
	}

	printf("mkfifo success... \n");
	char str1[100];

	int fd = open("mypipe2", O_WRONLY);

	printf("Enter your name\n");
	scanf("%s", str1);

	write(fd, str1, strlen(str1)+1);
	close(fd);
	
	return 0;

}
