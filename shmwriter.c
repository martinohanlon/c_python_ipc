#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, const char **argv)
{
   int shmid;
   key_t key = 123456;
   char *shared_memory;

   // Setup shared memory 
   if ((shmid = shmget(key, 11, IPC_CREAT | 0666)) < 0)
   {
      printf("Error getting shared memory id");
      exit(1);
   }
   // Attached shared memory
   if ((shared_memory = shmat(shmid, NULL, 0)) == (char *) -1) 
   {
      printf("Error attaching shared memory id");
      exit(1);
   }
   memcpy(shared_memory, "Hello World", sizeof("Hello World"));
   sleep(10);
   // Detach and remove shared memory
   shmdt(shmid);
   shmctl(shmid, IPC_RMID, NULL);
}
