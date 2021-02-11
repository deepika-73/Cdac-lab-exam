#include <pthread.h>
#include <stdio.h>

int sum;                   // shared data
void *runner(void *param); // the thread

int main(int argc, char *argv[])
{
    pthread_t tid;       // the thread identifier
    pthread_attr_t attr; // set of thread attributes
    /*   get the default attributes   */
    pthread_attr_init(&attr);
    /*   create the thread    */
    pthread_create(&tid, &attr, runner, argv[1]);
    /*   wait for the thread to exit    */
    pthread_join(tid, NULL);
    // Print the value of sum (computed by the thread) and quit
    printf("SUM = % d\n\n", sum);
}
/*   The thread will begin control in this function   */
void *runner(void *param)
{
    int i, upper = atoi(param);
    sum = 0;
    for (i = 1; i <= upper; i++)
        sum += i;
    sleep(1);
    pthread_exit(0);
}
