#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <stdio.h>

int getMax(int *array, int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int *array, int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int *array, int size) {
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
