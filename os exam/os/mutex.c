#include<stdio.h>
#include<pthread.h>
#include<errno.h>
//Note :1 and :2 should be used together(you can use them individually to experiment)
/*      :2 thread 1 I am using condition to let the thread execute the statements first time and
         unlock 's' so that thread 2 can go inside 
        Then in next iteration first thread wait for thread 2 to unlock 's1' so that it can
         go inside
        This will create a alternate execution of statements of both threads
*/


pthread_mutex_t m1,m2;

int count =0;
void *func1(int *a){
	int i=1;
	//pthread_mutex_lock(&m1); //:1
	while(i<10){
	pthread_mutex_lock(&m1);//:2
		i++;
		count++;
		printf("Thread1=%d\n",count);
//		sleep(1);
	pthread_mutex_unlock(&m2);//:2
//		sleep(1);
	}
	//pthread_mutex_unlock(&m1);// :1
}

void *func2(int *b){
	int i=0;
//pthread_mutex_lock(&m1); //:1
	  while(i<10){
	pthread_mutex_lock(&m2);//:2
              i++;
                count--;
		printf("Thread2=%d\n",count);
	pthread_mutex_unlock(&m1);//:2
//		sleep(1);
        }
//pthread_mutex_unlock(&m1);//:1

}


int main(){
	pthread_mutex_init(&m1,NULL);
	pthread_mutex_init(&m2,NULL);
	pthread_mutex_lock(&m2);
	int a=2,b=3;
	pthread_t id,tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int s1 = pthread_create(&id,&attr,func1,&a);
	int s2=pthread_create(&tid,&attr,func2,&b);
	int ret=pthread_join(id,NULL);
	pthread_join(tid,NULL);
	printf("%d\n",count);
	pthread_mutex_destroy(&m1);
	return 0;
}
