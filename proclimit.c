#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: proclimit <mem MB> <command>\n");
    return 1;
  }
  int memlimit = atoi(argv[1]) * (1024 * 1024); // MB
  printf("Will spawn %s with %d memory limit\n", argv[2], memlimit);

  // Set the limit using setrlimit() system call
  struct rlimit rlimit_mem;
  rlimit_mem.rlim_cur = memlimit;
  rlimit_mem.rlim_max = memlimit;
  //setrlimit(RLIMIT_AS, &rlimit_mem); // Virtual memory
  setrlimit(RLIMIT_DATA, &rlimit_mem); // Heap

  // Now, spawn the process
  execvp(argv[2], &(argv[2]));
}
