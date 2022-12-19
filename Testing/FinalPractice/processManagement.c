#include <stdio.h>
#include <unistd.h>

int main() {

  int pid = fork();  // Create a new process

  if (pid < 0) {
    // Error occurred
    fprintf(stderr, "Fork Failed");
    return 1;
  } else if (pid == 0) {
    // Child process
    printf("I am the child process\n");
  } else {
    // Parent process
    printf("I am the parent process\n");
  }

  return 0;
}
