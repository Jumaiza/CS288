#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    printf("Shared Memory ID: %d\n",shmid);

    void * shmaddr = shmat(shmid,NULL,0);

    int d = shmdt(shmaddr);
    printf("Detach Return Value: %d\n",d);

    int n = shmctl(shmid,IPC_RMID, NULL);
    printf("Destroy Return Value: %d\n",n);


    return 0;

}