#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	int gpio = 4;
	char buf[100];

	FILE* fd = fopen("/sys/class/gpio/export", "w");
	fprintf(fd, "%d", gpio);
	fclose(fd);

	sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
	fd = fopen(buf, "w");
	fprintf(fd, "out");
	fclose(fd);

	sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
	fd = fopen(buf, "w");

	for (;;) {
		fd = fopen(buf, "w");
		fprintf(fd, "1");
		fclose(fd);
		fd = fopen(buf, "w");
		fprintf(fd, "0");
		fclose(fd);

	/*
		fprintf(fd, "1");
		fflush(fd);
		fprintf(fd, "0");
		fflush(fd);
	*/
	
	}
	return 0;
}
