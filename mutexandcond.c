#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>   // header file in C that provides the definitions and declarations necessary for using POSIX threads (pthreads).
#include<unistd.h> //for sleep function

#define num_threads 3
#define count_limit 10

int counter=0;
pthread_mutex_t mutex;  //mutex(synchroniztion tool)
pthread_cond_t cond_var;   //condition variable
int reached_limit=0;

void *increment_counter(void *thread_id)
{
    long tid=(long) thread_id;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(reached_limit)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        counter++;
        printf("Thread %ld incremented the counter to %d\n",tid,counter);
        if(counter>=count_limit)
        {
            reached_limit=1;
            printf("thread %ld has reached the limit.Signalling condition.\n",tid);
            pthread_cond_broadcast(&cond_var);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *monitor_counter(void *thread_id)
{
    long tid=(long) thread_id;
    pthread_mutex_lock(&mutex);
    while(!reached_limit)
    {
        printf("monitor thread %ld is waiting for condtion...\n",tid);
        pthread_cond_wait(&cond_var, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    printf("Monitor Thread %ld condition signaled. Counter reached %d.\n", tid, counter);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[num_threads];
    pthread_t monitor_thread; //monitor thread creation
    int rc;
    long t;

    //initialize the mutex and condition variable
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond_var,NULL);
     //create threads for increment counter
      for (t = 0; t < num_threads; t++) {
        rc = pthread_create(&threads[t], NULL, increment_counter, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    //create threads for monitor counter
     rc = pthread_create(&monitor_thread, NULL, monitor_counter, (void *)t);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);}

        // Join threads to wait for their completion
    for (t = 0; t < num_threads; t++) {
        pthread_join(threads[t], NULL);
         // Join monitor thread last
    pthread_join(monitor_thread, NULL);

    // Clean up mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);
    return 0;
    }
    }
