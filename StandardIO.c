#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

int main(int argc, char const *argv[]) {

  int fp, rd;
  clock_t st, et;
  char* buf = NULL;
  struct stat s;

  st = clock();

  fp = open("Bible", O_RDWR);
  int status = fstat (fp, & s);
  int size = s.st_size;

  buf = (char* )malloc(size);
  rd = read(fp, buf, size);

  et = clock();
  printf("%ld\n", et-st);
  //watch
  //printf("%s\n", buf);
  free(buf);
  return 0;
}
