#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int sum;                   // shared data
void *runner(void *param); // the thread

sem_t numberedlock; 

int main(int argc, char *argv[])
{
    pthread_t tid[4];       // the thread identifier
    pthread_attr_t attr; // set of thread attributes
    /*   get the default attributes   */
    pthread_attr_init(&attr);

    // 1st argument = semaphore
    // 2nd argument = 0 if the semaphore is public
    // 3rd argument = Total threads that can be active at any point in time.
    sem_init(&numberedlock, 0, 1); 
 
    /*   create the threads    */
    pthread_create(&tid[0], &attr, runner, argv[1]);
    printf("Thread 1 started\n");
    pthread_create(&tid[1], &attr, runner, argv[1]);
    printf("Thread 2 started\n");
    pthread_create(&tid[3], &attr, runner, argv[1]);
    printf("Thread 3 started\n");
    pthread_create(&tid[4], &attr, runner, argv[1]);
    printf("Thread 4 started\n");

    /*   wait for the thread to exit    */
    printf("Waiting for threads to join\n");
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    
    // Print the value of sum (computed by the thread) and quit
    // printf("SUM = % d\n\n", sum);
}
/*   The thread will begin control in this function   */
void *runner(void *param)
{
    sleep(2);
    pid_t tid = gettid();
    int i = 0 ; 
    while(i < 100){
        i++;    
        sem_wait(&numberedlock); 
        sum = sum + 2;
        sleep(4);
        printf("%d : Sum = %d\n", tid, sum);
        // printf("I am posting from thread : %d\n", tid);
        sem_post(&numberedlock);
    }
    pthread_exit(0);
}
