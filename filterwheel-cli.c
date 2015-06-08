#include<stdio.h>
#include "filterwheel.h"

#if defined(POSIX)
	static char * device = "/dev/ttyUSB0";
#else
	static char * device = "\\\\.\\COM22";
#endif

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("usage: filterwheel-cli <command>\n");
		return 1;
	} else {
		int a = (int)*argv[1] - '0'; // convert char to int
		filterwheel_init(device);
		filterwheel_send(a);
		printf("sending %i\n", a);
		filterwheel_uninit();
	}
}
