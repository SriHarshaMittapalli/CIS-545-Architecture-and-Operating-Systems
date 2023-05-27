#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

// creating a struct to store thread index,starting of thread, ending of thread
struct threadDetails
{
    int thread_index, thread_start, thread_end;
};

// assigning as global value so that it can add Gregory-Leibniz terms.
double *totalGregoryLeibnizSeriesSum;

pthread_t *root_threads;
double gregoryLeibnizSeries(int number)
{
    double series = 0;
    series = series + 4 * pow(-1, number + 1) / (2 * number - 1);
    return series;
}

// declaring m and n values
int m = 0, n = 0, lengthOfThreadPerBatch = 0;

void *computingSumInParallel(void *t)
{
    // This function is called by pthread_create
    long threadIndex = (long)t;
    double totalGregoryLeibnizSeriesSumPerThread = 0.0;
    int i = (threadIndex * lengthOfThreadPerBatch) + 1;
    // calculating sum from thread start to end for each thread
    while (i <= (threadIndex + 1) * lengthOfThreadPerBatch)
    {
        totalGregoryLeibnizSeriesSumPerThread = totalGregoryLeibnizSeriesSumPerThread + gregoryLeibnizSeries(i);
        i++;
    }

    totalGregoryLeibnizSeriesSum[threadIndex] = totalGregoryLeibnizSeriesSumPerThread;

    i = 1;
    while (threadIndex > m - (m / (int)pow(2, i)) - 1)
    {
        int val1 = ((int)(pow(2.0, log(m) / log(2) - i)));
        int val2 = (int)threadIndex, partner = val1 ^ val2;
        pthread_join(root_threads[partner], NULL);
        totalGregoryLeibnizSeriesSum[threadIndex] = totalGregoryLeibnizSeriesSum[threadIndex] + totalGregoryLeibnizSeriesSum[partner];
        i++;
    }

    // printing last element in array
    if (threadIndex == m - 1)
    {
        for (int i = 0; i < m; i++)
        {
            printf("middle result %d: %lf \n ", i, totalGregoryLeibnizSeriesSum[i]);
        }
        printf("pi value: %lf\n", totalGregoryLeibnizSeriesSum[threadIndex]);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    // storing m and n  values
    m = atoi(argv[1]), n = atoi(argv[2]);

    lengthOfThreadPerBatch = (n / m);

    // initialising start and end as given
    int thread_start = 1, thread_end = lengthOfThreadPerBatch;

    totalGregoryLeibnizSeriesSum = malloc(sizeof(double) * m);
    struct threadDetails args[m];
    root_threads = malloc(sizeof(pthread_t) * m);
    long i;
    i = 0;
    for (i = 0; i < m; i++)
    {
        args[i].thread_index = i;
        args[i].thread_start = thread_start;
        args[i].thread_end = thread_end;
        thread_start = thread_end + 1;
        thread_end = thread_end + (n / m);
        if (pthread_create(&root_threads[i], NULL, computingSumInParallel, (void *)i) != 0)
        {
            printf("Thread is not created\n");
        }
    }
    pthread_exit(NULL);
}
