#include<stdio.h>
#include "filterwheel.h"

int main(int argc, char *argv[])
{
	int a;
	#if defined(POSIX)
	char * filterwheel_device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AI02PNA1-if00-port0";
	#else
	char * filterwheel_device = "\\\\.\\COM22";
	#endif

	if (argc != 2) {
		printf("usage: filterwheel-cli <command>\n");
		return 1;
	}

	a = (int)*argv[1] - '0'; /* convert char to int */

	filterwheel_init(filterwheel_device);
	printf("sending %i...\n", a);
	filterwheel_send(a);
	filterwheel_uninit();

	return 0;
}
