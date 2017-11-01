#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	int gpio = 4;
	FILE* fd = fopen("/sys/class/gpio/export", "w");
	fprintf(fd, "%d", gpio);
	fclose(fd);
	return 0;
}
