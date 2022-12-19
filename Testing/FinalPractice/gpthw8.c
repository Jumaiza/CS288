#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// #define N 250000 // number of random points

int main(int argc, char *argv[])
{
    int i;
    double x, y, z, pi;
    int count = 0; // number of points inside the circle
    int N = 250000;

    #pragma omp parallel
    {
        for (i = 0; i < N; i++){
        
            x = (double)rand()/RAND_MAX; // generate random x coordinate
            y = (double)rand()/RAND_MAX; // generate random y coordinate
            z = sqrt((x*x) + (y*y)); // distance from the origin
            if (z <= 1)
            {
                // #pragma omp atomic
                // count++; // increment count atomically
                #pragma omp critical
                {
                    count++;
                }
            }
        }

    }

    pi = (double)count/N*4; // estimate pi
    printf("Estimated value of pi: %f\n", pi);

    return 0;
}
