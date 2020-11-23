#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <time.h>

int main(int argc, char const *argv[]) {

	int fp, rd;
	clock_t st, et;
	unsigned char *f;
	struct stat s;

	st = clock();

	fp = open("Bible", O_RDWR);
	int status = fstat (fp, & s);
	int size = s.st_size;

	f = (char *) mmap (0, size, PROT_READ, MAP_PRIVATE, fp, 0);

	et = clock();
	printf("%ld\n", et-st);
	//watch
	//printf("%s\n", f);

	return 0;
}
