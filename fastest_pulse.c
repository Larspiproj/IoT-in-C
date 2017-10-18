#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

// int main(int argc, char** argv) {
int main() {
	int memfd = open("/dev/mem", O_RDWR | O_SYNC);
	uint32_t * map = (uint32_t *)mmap(
						NULL,
						4*1024,
						(PROT_READ | PROT_WRITE),
						MAP_SHARED,
						memfd,
						0x3f200000);
	if (map == MAP_FAILED)
		printf("bcm2835_init: %s mmap failed: %s\n", strerror(errno));
	close(memfd);

	printf("fsel0 %X \n\r", *map);
	printf("fsel0 %X \n\r", map);

	volatile uint32_t* paddr = map;
	*paddr=0x1000;
	printf("*paddr %X \n\r", *paddr);
	printf("paddr %X \n\r", paddr);

	volatile uint32_t* paddr1 = map + 0x1C/4;
	volatile uint32_t* paddr2 = map + 0x28/4;
	for(;;) {
		*paddr1=0x10;
		printf("paddr1 %X \n\r", paddr1);
		printf("*paddr1 %X \n\r",*paddr1);
		bcm2835_delay(500);
		*paddr2=0x10;
		printf("paddr2 %X \n\r", paddr2);
		printf("*paddr2 %X \n\r",*paddr2);
		bcm2835_delay(500);
	};
	return (EXIT_SUCCESS);
}
