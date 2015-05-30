#include "serial.c"

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("usage: filterwheel-cli <command>\n");
		return 1;
	} else {
		filterwheel_init();
		filterwheel_send(*argv[1]);
		filterwheel_uninit();
	}
}
