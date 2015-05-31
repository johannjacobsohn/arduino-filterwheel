#include "serial.c"

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("usage: filterwheel-cli <command>\n");
		return 1;
	} else {
		int a = (int)*argv[1] - '0';
		filterwheel_init();
		filterwheel_send(a);
		printf("sending %i", a);
		filterwheel_uninit();
	}
}
