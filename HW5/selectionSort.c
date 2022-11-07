#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selectionSort(int *a, int size){

    int i,j,min_pos;

    for(i = 0; i<size-1; i++){

        min_pos = i;
        for(j=i+1; j<size; j++){
            if(a[j]<a[min_pos]){
                min_pos = j;
            }
        }
        if(min_pos!=i){

            swap(a + i, a + min_pos);
        }

    }
}

void arrToSting(int *a,int n){
    int i;
    for(i = 0; i<n; i++){
        printf("%d, ",*(a+i));
    }
    printf("\n");
}

int main(){

    clock_t start, end;
    double executionTime;
    int size = 1000000;
    int* a = (int*) malloc(size*sizeof(int));
    int i;
    printf("Data Set Size: %d\n",size);

    for(i = 0; i<size; i++){
        *(a + i) = rand();
    }
    
    start = clock();
    selectionSort(a,size);
    end = clock();
    free(a);

    executionTime = (((double) (end - start)) / CLOCKS_PER_SEC)*1000;
    printf("Execution Time: %f\n",executionTime);

    return 0;

}
