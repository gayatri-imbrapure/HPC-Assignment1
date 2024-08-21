#include<stdio.h>
#include<omp.h>
int main(){
    int tot_threads;

    printf("Enter the number of threads: ");
    scanf("%d", &tot_threads);

    printf("Sequential Execution:\n");
    for (int i = 0; i < tot_threads; i++) {
        printf("Hello, World! (Thread %d)\n", i);
    }

    printf("\nParallel Execution:\n");
    #pragma omp parallel num_threads(tot_threads)
    {
        int thread_id = omp_get_thread_num();
        printf("Hello, World! (Thread %d)\n", thread_id);
    }
    return 0;
}