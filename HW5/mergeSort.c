#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void merge(int *a, int l, int r, int n){
    int *b = (int *)malloc(n * sizeof(int)); /* REMEMBER TO FREE THIS */
    int c = l;
    int p1, p2;
    p1 = l;
    p2 = ((l + r) / 2) + 1;
    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1)){
        if (a[p1] <= a[p2]){
            b[c++] = a[p1];
            p1++;
        }
        else{
            b[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1){
        while ((p1 < ((l + r) / 2) + 1)){
            b[c++] = a[p1];
            p1++;
        }
    }
    else
    {
        while ((p2 < r + 1)){
            b[c++] = a[p2];
            p2++;
        }
    }

    for (c = l; c < r + 1; c++) a[c] = b[c];
    free(b);
}

void merge_sort(int *a, int n, int l, int r){
    if (r - l == 1){
        if (a[l] > a[r])
            swap(&a[l], &a[r]);
    }
    else if (l != r){
        merge_sort(a, n, l, (l + r) / 2);
        merge_sort(a, n, ((l + r) / 2) + 1, r);
        merge(a, l, r, n);
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
    int size = 10;
    int* a = (int*) malloc(size*sizeof(int));
    int i;
    printf("Data Set Size: %d\n",size);

    for(i = 0; i<size; i++){
        *(a + i) = rand();
    }
    
    start = clock();
    merge_sort(a, size, 0, size-1);
    end = clock();
    free(a);

    executionTime = 1000*(((double) (end - start)) / CLOCKS_PER_SEC);
    printf("Execution Time: %f\n",executionTime);

    return 0;

}

