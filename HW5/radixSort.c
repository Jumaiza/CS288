#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <stdio.h>

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;
  int i, j, k, l, m, n;

  for (i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (j = 0; j < max; ++j)
    count[j] = 0;

  // Calculate count of elements
  for (k = 0; k < size; k++)
    count[(array[k] / place) % 10]++;
    
  // Calculate cumulative count
  for (l = 1; l < 10; l++)
    count[l] += count[l - 1];

  // Place the elements in sorted order
  for (m = size - 1; m >= 0; m--) {
    output[count[(array[m] / place) % 10] - 1] = array[m];
    count[(array[m] / place) % 10]--;
  }

  for (n = 0; n < size; n++)
    array[n] = output[n];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

void arrToSting(int *a,int n){
    int i;
    for(i = 0; i<n; i++){
        printf("%d, ",*(a+i));
    }
    printf("\n\n");
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
    radixsort(a,size);
    end = clock();
    free(a);

    executionTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %f\n",executionTime);

    return 0;

}
