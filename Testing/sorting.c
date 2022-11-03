#include <stdio.h>

void quickSort(int a[], int first, int last){

    int LP, RP, pivotIn, temp;
    if(first<last){

        pivotIn = first;
        LP = first;
        RP = last;

        while(LP<RP){

            while(a[LP]<=a[pivotIn] && LP<last)
                LP++;
            
            while(a[RP]>a[pivotIn])
                RP--;
            
            if(LP<RP){
                temp = a[LP];
                a[LP] = a[RP];
                a[RP] = temp;
            }
        }
        temp = a[RP];
        a[RP] = a[pivotIn];
        a[pivotIn] = temp;
        quickSort(a,first, RP-1);
        quickSort(a,RP+1,last);
    }
}

void selectionSort(int a[], int size){

    int i,j,min_pos, temp;

    for(i = 0; i<size-1; i++){

        min_pos = i;
        for(j=i+1; j<size; j++){
            if(a[j]<a[min_pos]){
                min_pos = j;
            }
        }
        if(min_pos!=i){

            temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }

    }
}

void insertionSort(int a[], int size){

    int i, j, current;

    for(i = 0; i<size; i++){

        current = a[i];
        j = i-1;

        while(j >=0 && a[j]>current){
            a[j+1] = a[j];
            j = j-1;
        }

        a[j+1] = current;
    }
}

void bubbleSort(int a[], int size){

    int i, j, temp;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void arrToSting(int a[],int n){
    int i;
    for(i = 0; i<n; i++){
        printf("%d, ",a[i]);
    }
}

int main(){

    int a[] = {1,4,9,5,2,6};

    quickSort(a,0,5);
    arrToSting(a,6);

    return 0;

}