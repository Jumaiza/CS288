#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main(){

    int i, id;
    double x, y, r, pi;
    int inCircleCount = 0;
    int pointCount = 250000;
    int iterations = 0;

    #pragma omp parallel num_threads(4)
    {

        for(i = 0; i<pointCount; i++){
            
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;
            r = sqrt((x*x) + (y*y));

            #pragma omp critical
            {
                if(r <= 1){
                    inCircleCount++;
                }
                iterations++;
            }
        }
    }

    pi = (double)inCircleCount/pointCount * 4;
    printf("PI Estimation: %f\n",pi);
    printf("Iteration Count: %d", iterations);
    return 0;

}