#include <stdio.h>
int main() {
   printf("Hello World!\n");
   char name[]="Zaid";
   char city[] = {'B','u','d','d','L','a','k','e'};
   printf("%p",&city+1);
   return 0;
}