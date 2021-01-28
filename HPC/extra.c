#include<stdio.h>
#include<omp.h>

int main() {
    int arr[100000], sum = 0, i, tid, numt;
    double t1, t2;
    //initialize array
    for(i = 0; i < 100000; i++) 
        arr[i] = 1;

    //Sum of the array

    t1 = omp_get_wtime();

    #pragma omp parallel default(shared) private(i, tid)
    {
        tid = omp_get_thread_num();
        numt = omp_get_num_threads();
        for(i = 0; i < 100000; i++) 
            sum += arr[i];
    }
    
    t2 = omp_get_wtime();

    printf("Sum : %d   Time: %g", sum, t2-t1);
    return 0;
}