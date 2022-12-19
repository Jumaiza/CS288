#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

double rand_uniform(int* seed){
    return ((double)rand_r(seed)/(double)RAND_MAX)*2-1.0; 
}
int is_in_circle(double x, double y){
    return x*x + y*y <= 1; 
}

int main(){
    int globalIn =0, globalOut=0; double pi; 
    #pragma omp parallel num_threads(2) default(shared)
    {
        int id = omp_get_thread_num(), i=0; 
        int inCircle=0, outCircle=0; 
        for(i=0; i < 100000000; i++){
            if(is_in_circle(rand_uniform(&id), rand_uniform(&id))) inCircle++;
            else outCircle++; 
        }

        #pragma omp critical
        {
            globalIn+=inCircle; 
            globalOut+=outCircle; 
        }
    }
    pi= (double)globalIn/(globalIn+globalOut)*4; 
    printf("%lf", pi);
    return 0; 
}