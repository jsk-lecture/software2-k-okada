/* test-fork-mmap-lock.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* exit */
#include <sys/wait.h> /* wait */

#include <sys/mman.h>
#include <fcntl.h>  // O_RDWR, O_CREAT
#include <string.h> // mmap

#include <sys/sem.h> // shmget

typedef struct {
  int shared_resource;
} shared_data_type;

union semun {
  int val;
  struct semid_ds *buf;
  ushort * array;
} argument;

int main () {
  int fd;
  shared_data_type shared_data;
  void *addr;

  fd = shm_open("/NAME", O_CREAT | O_RDWR, 0600); // 0600 = u+rw
  ftruncate(fd, sizeof(shared_data_type));
  addr = mmap(NULL, sizeof(shared_data_type), PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
  shared_data.shared_resource = 0;
  memcpy(addr, &shared_data, sizeof(shared_data_type)); // write shared_data to addr(memory)

  int id;
  id = semget(12345, 1, 0666 | IPC_CREAT);
  argument.val = 1;
  semctl(id, 0, SETVAL, argument);
  
  pid_t pid;
  pid = fork();
  if ( pid == 0 ) {
    /* 子プロセス */
    struct sembuf operations[1];
    operations[0].sem_num = 0;
    operations[0].sem_op = -1;
    operations[0].sem_flg = 0;
    int i, j;
    for (i = 0; i < 10; i++ ) {
      for(j=0;j<10000;j++){
	operations[0].sem_op = -1;
	semop(id, operations, 1);

	memcpy(&shared_data, addr, sizeof(shared_data_type)); // write addr to shared_data
	shared_data.shared_resource++;
	memcpy(addr, &shared_data, sizeof(shared_data_type)); // write shared_data to addr

	operations[0].sem_op = 1;
	semop(id, operations, 1);
      }
      printf("Process [%d]: i:%d shared:%d\n", pid, i, shared_data.shared_resource);
      sleep(1);
    }
    printf("Process %d: finished, return %d.\n", pid, shared_data.shared_resource);
    exit(0);
  } else if ( pid > 0 ) {
    /* 親プロセス */
    struct sembuf operations[1];
    operations[0].sem_num = 0;
    operations[0].sem_op = -1;
    operations[0].sem_flg = 0;
    int i, j;
    for (i = 0; i < 20; i++ ) {
      for(j=0;j<10000;j++){
	operations[0].sem_op = -1;
	semop(id, operations, 1);

	memcpy(&shared_data, addr, sizeof(shared_data_type)); // write addr to shared_data
	shared_data.shared_resource++;
	memcpy(addr, &shared_data, sizeof(shared_data_type)); // write shared_data to addr

	operations[0].sem_op = 1;
	semop(id, operations, 1);
      }
      printf("Process [%d]: i:%d shared:%d\n", pid, i, shared_data.shared_resource);
      usleep(300*1000); // 300 msec
    }
    int status;
    wait(&status);
    printf("Process %d finished, return %d.\n", pid, shared_data.shared_resource);
  }
  
  //shm_unlink("/NAME");
  
  return 0;
}
