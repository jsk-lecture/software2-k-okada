/* test-fork-mmap.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* exit */
#include <sys/wait.h> /* wait */

#include <sys/mman.h>
#include <fcntl.h>  // O_RDWR, O_CREAT
#include <string.h> // mmap

typedef struct {
  int shared_resource;
} shared_data_type;

int main () {
  int fd;
  shared_data_type shared_data;
  void *addr;

  fd = shm_open("/NAME", O_CREAT | O_RDWR, 0600); // 0600 = u+rw
  ftruncate(fd, sizeof(shared_data_type));
  addr = mmap(NULL, sizeof(shared_data_type), PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
  shared_data.shared_resource = 0;
  memcpy(addr, &shared_data, sizeof(shared_data_type)); // write shared_data to addr(memory)
  
  pid_t pid;
  pid = fork();
  if ( pid == 0 ) {
    /* 子プロセス */
    int i, j;
    for (i = 0; i < 10; i++ ) {
      for(j=0;j<10000;j++){
	memcpy(&shared_data, addr, sizeof(shared_data_type)); // write addr to shared_data
	shared_data.shared_resource++;
	memcpy(addr, &shared_data, sizeof(shared_data_type)); // write shared_data to addr
      }
      printf("Process [%d]: i:%d shared:%d\n", pid, i, shared_data.shared_resource);
      sleep(1);
    }
    printf("Process %d: finished, return %d.\n", pid, shared_data.shared_resource);
    exit(0);
  } else if ( pid > 0 ) {
    /* 親プロセス */
    int i, j;
    for (i = 0; i < 20; i++ ) {
      for(j=0;j<10000;j++){
	memcpy(&shared_data, addr, sizeof(shared_data_type)); // write addr to shared_data
	shared_data.shared_resource++;
	memcpy(addr, &shared_data, sizeof(shared_data_type)); // write shared_data to addr
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
