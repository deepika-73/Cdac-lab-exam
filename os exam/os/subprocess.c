#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	/*
	Create identifier
	Create child process using fork
	Decide code section of parent and child
	wait of child using waitpid
	*/
	pid_t pid[5];
	int wstatus;
	int i=0;
	int flag=0;
	for(i=0;i<5;i++){
		pid[i]=fork();
		
	
		int a= 10;
		if(pid[i]<0){
			printf("Process creation failed\n");
		}
		if(pid[i]==0){
		//sleep(10);
			printf("this is child\n");
			flag=0;
			sleep(1);
			break;
		//Child task goes here
		}

		if(pid[i]>0){
			flag=1;

		//	printf("This is parent\n");
		//parent task goes here
		//waitpid(pid,&wstatus,0);
		//if (wstatus==WIFEXITED){
		//	printf("the child terminated normally");
		//}
		}
	}

	if(flag==1){
		printf("this is parent\n");
	}

	 waitpid(-1,&wstatus,0);
//                if (wstatus==WEXITED){
//                        printf("Wait for children that have terminated\n");
//                }
		if(WIFEXITED(wstatus)){
			printf("Child exited normally\n");
		}	
		

	//Comman task
//#	execl("/usr/local/bin/firefox","www.youtube.com");
	return 0;
}
