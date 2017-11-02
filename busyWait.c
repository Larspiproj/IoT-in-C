#include <stdio.h>
#include <bcm2835.h>

int main() {
	if (!bcm2835_init())
		return 1;
	bcm2835_gpio_fsel(RPI_BPLUS_GPIO_J8_40, BCM2835_GPIO_FSEL_OUTP);

	volatile int i;
	for(;;) {
		for(i = 0; i < 9; i++){};
		bcm2835_gpio_write(RPI_BPLUS_GPIO_J8_40, HIGH);
		for(i = 0; i < 9; i++){};
		bcm2835_gpio_write(RPI_BPLUS_GPIO_J8_40, LOW);
	}

	return 0;	
	
}
