#include<stdio.h>
#include<pthread.h>
#include<errno.h>
#include <semaphore.h>
//Note :1 and :2 should be used together(you can use them individually to experiment)
/*	:2 thread 1 I am using condition to let the thread execute the statements first time and
	 unlock 's' so that thread 2 can go inside 
	Then in next iteration first thread wait for thread 2 to unlock 's1' so that it can
	 go inside
	This will create a alternate execution of statements of both threads
*/
/*
	Use :1 if you want to use only first thread to execute first and then second thread
*/


int count =0;
sem_t s,s1;

void *func1(int *a){
	int i=1;

	while(i<10){
		if(i>1)
			sem_wait(&s1);//Use this wait for thread 2 to execute its statement:2
		i++;
		
		count++;
		printf("Thread1=%d\n",count);
		sem_post(&s); //Use this so that thread 2 can go inside :2
		sleep(1);
		
	}
//	sem_post(&s); Use this to unlock :1
}

void *func2(int *b){
	int i=0;
//	sem_wait(&s); Use this to wait :1
	  while(i<10){
		sleep(2);
		sem_wait(&s); //Use this to wait for first thread to execute :2
              	i++;
                count--;
		printf("Thread2=%d\n",count);
		sem_post(&s1); //Use this to unlock so that first thread can now go inside :2
		sleep(1);
        }


}


int main(){
	
	sem_init(&s,0,0);
	sem_init(&s1,0,0);
	int a=2,b=3;
	pthread_t id,tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&id,&attr,func1,&a);
	pthread_create(&tid,&attr,func2,&b);
	
	pthread_join(id,NULL);
	pthread_join(tid,NULL);
	printf("%d\n",count);
	sem_destroy(&s);
	printf("End");
	return 0;
}
