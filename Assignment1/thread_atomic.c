#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>

// creating a struct to store thread index,starting of thread, ending of thread
struct threadDetails
{
    int thread_index, thread_start, thread_end;
};

// assigning as global value so that it can add Gregory-Leibniz terms.
double totalGregoryLeibnizSeriesSum = 0;
pthread_barrier_t thread_barrier;
pthread_mutex_t count_mutex;

void *gregoryLeibnizSeries(void *t)
{
    double gregoryLeibnizSeriesSumForSingleThread = 0;
    struct threadDetails *thread_details = t;

    // summing values of Gregory-Leibniz terms from start to end of thread
    double thread_start = thread_details->thread_start;
    while (thread_start <= thread_details->thread_end)
    {
        gregoryLeibnizSeriesSumForSingleThread = gregoryLeibnizSeriesSumForSingleThread + pow(-1, thread_start + 1) / (2 * thread_start - 1);
        thread_start++;
    }

    // print thread id and quadruple of that thread
    printf("thread %d: %f\n", thread_details->thread_index, gregoryLeibnizSeriesSumForSingleThread);

    // LOCK HERE
    pthread_mutex_lock(&count_mutex);
    // adding the above calculated sum to totalGregoryLeibnizSeriesSum
    totalGregoryLeibnizSeriesSum = totalGregoryLeibnizSeriesSum + gregoryLeibnizSeriesSumForSingleThread;
    pthread_mutex_unlock(&count_mutex);

    pthread_barrier_wait(&thread_barrier);
    return NULL;
}

int main(int argc, char *argv[])
{
    // declaring m and n  values
    int m = atoi(argv[1]), n = atoi(argv[2]);

    // initialising start and end as given
    int thread_start = 1, thread_end = (n / m);
    // declaring thread_details array with size m
    struct threadDetails thread_details[m];

    pthread_t thread_id[m];

    pthread_barrier_init(&thread_barrier, NULL, m + 1);

    int thread;
    for (thread = 0; thread < m; thread++)
    {
        // Assigning thread start,end,id's
        thread_details[thread].thread_index = thread;
        thread_details[thread].thread_start = thread_start;
        thread_details[thread].thread_end = thread_end;

        int next_start = thread_end + 1;
        int next_end = thread_end + (n / m);

        thread_start = next_start, thread_end = next_end;

        // creation of thread
        pthread_create(&thread_id[thread], NULL, gregoryLeibnizSeries, (void *)&thread_details[thread]);
    }

    pthread_barrier_wait(&thread_barrier);
    // printing the final value
    totalGregoryLeibnizSeriesSum = 4 * totalGregoryLeibnizSeriesSum;
    printf("Pi value is: %f\n", totalGregoryLeibnizSeriesSum);
    // thread barrier destroying
    pthread_barrier_destroy(&thread_barrier);
    return 0;
}