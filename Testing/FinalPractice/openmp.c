#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

void main() {

    clock_t start, end;
    double executionTime;
    start = clock();

    const int num_steps = 1000;
    double step = 1.0 / num_steps;
    double area = 0;
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        // printf("Thread %d\n",id);
        int nthreads = omp_get_num_threads();
        double length = 0;
        int i;
        for (i = id; i < num_steps; i += nthreads) {
            double x = (i + 0.5) * step;
            double y = 4 / (1 + (x * x));
            length += y;
        }
        #pragma omp critical
        {
            area += length * step;
        }
    }
    printf("PI with %d steps is %f\n", num_steps, area);

    end = clock();
    executionTime = 1000*(((double) (end - start)) / CLOCKS_PER_SEC);
    printf("Execution Time: %f\n",executionTime);
}