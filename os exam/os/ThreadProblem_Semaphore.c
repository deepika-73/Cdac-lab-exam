#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int sum;                   // shared data
void *runner(void *param); // the thread
sem_t numberedlock; 

int main(int argc, char *argv[])
{
    pthread_t tid[2];       // the thread identifier
    pthread_attr_t attr; // set of thread attributes
    /*   get the default attributes   */
    pthread_attr_init(&attr);

    // 1st argument = semaphore
    // 2nd argument = 0 if the semaphore is public
    // 3rd argument = Total threads that can be active at any point in time.
    sem_init(&numberedlock, 0, 1); 
 
    /*   create the threads    */
    pthread_create(&tid[0], &attr, runner, argv[1]);
    printf("Thread 1 started");
    
    pthread_create(&tid[1], &attr, runner, argv[1]);
    printf("Thread 2 started");

    /*   wait for the thread to exit    */
    printf("Waiting for threads to join");
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    
    // Print the value of sum (computed by the thread) and quit
    printf("SUM = % d\n\n", sum);
}
/*   The thread will begin control in this function   */
void *runner(void *param)
{
    pid_t tid = gettid();
    int i = 0 ; 
    while(i < 100){
        i++;
        sem_wait(&numberedlock); 
        sum = sum + 2;
        printf("%d : Sum = %d\n", tid, sum);
        sem_post(&numberedlock);
        sleep(2);
    }
/*
    int i, upper = atoi(param);
    sum = 0;
    for (i = 1; i <= upper; i++)
        sum += i;
    sleep(1);
*/    
    pthread_exit(0);
}
