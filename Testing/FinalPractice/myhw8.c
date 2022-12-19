#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main(){

    double pi;
    int inCircleCount = 0;
    int pointCount = 250000;

    #pragma omp parallel
    {
        double x, y, r;
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        int i;

        for(i = id; i<pointCount; i+=nthreads){
            
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;
            r = sqrt((x*x) + (y*y));

            if(r <= 1){
                #pragma omp critical
                {
                    inCircleCount++;
                }
            }
        }
    }

    pi = (double)inCircleCount/pointCount * 4;
    printf("PI Estimation: %f\n",pi);
    return 0;

}