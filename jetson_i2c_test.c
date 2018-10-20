#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <cstdlib>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>

int get_filedescriptor(){
	char fileNameBuffer[32];
	sprintf(fileNameBuffer, "dev/i2c-0");
	int FileDescriptor = open(fileNameBuffer, 0_RDWR);
	if (FileDescriptor <0){
		return -1;
	}
	if (ioctl(FileDescriptor, I2C_SLAVE, kI2CAddress) <0){
		return -1;
	}
	return FileDescriptor;
}


int main(){
	int FileDescriptor = get_filedescriptor();
	if (FileDescriptor != -1){
		i2c_smbus_write_byte(FileDescriptor, 2);
	}
	return 0;
}
