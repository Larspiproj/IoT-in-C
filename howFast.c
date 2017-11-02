#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include <sched.h>
#include <sys/mman.h>

int main(int argc, char** argv) {
	const struct sched_param priority = {1};
	sched_setscheduler(0, SCHED_FIFO, &priority);
	mlockall(MCL_CURRENT | MCL_FUTURE);
if (!bcm2835_init()) return 1;

bcm2835_gpio_fsel(RPI_BPLUS_GPIO_J8_07, BCM2835_GPIO_FSEL_INPT);

volatile int i;
while (1) {
	while (1 == bcm2835_gpio_lev(RPI_BPLUS_GPIO_J8_07));
		while (0 == bcm2835_gpio_lev(RPI_BPLUS_GPIO_J8_07));
		for (i = 0; i < 5000; i++) {
			if (0 == bcm2835_gpio_lev(RPI_BPLUS_GPIO_J8_07)) break;
		}
		printf("%d\n\r", i); fflush(stdout);
	}

	return (EXIT_SUCCESS);
}
