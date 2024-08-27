#include<stdio.h>
#include<omp.h>

int main() {
    int tot_threads;

    printf("Enter the number of threads: ");
    scanf("%d", &tot_threads);
    double start_time, end_time, Tseq, Tparallel;
    printf("Sequential Execution:\n");
    start_time = omp_get_wtime();
    for (int i = 0; i < tot_threads; i++) {
        printf("Hello, World! (Thread %d)\n", i);
    }
    end_time = omp_get_wtime();
    Tseq = end_time - start_time;
    printf("Time taken for Sequential Execution: %f seconds\n", Tseq);
    printf("\nParallel Execution:\n");
    start_time = omp_get_wtime();
    #pragma omp parallel num_threads(tot_threads)
    {
        int thread_id = omp_get_thread_num();
        printf("Hello, World! (Thread %d)\n", thread_id);
    }
    end_time = omp_get_wtime();
    Tparallel = end_time - start_time;
    printf("Time taken for Parallel Execution: %f seconds\n", Tparallel);
    double speedup = Tseq / Tparallel;
    printf("\nSpeedup achieved: %f\n", speedup);

    return 0;
}
