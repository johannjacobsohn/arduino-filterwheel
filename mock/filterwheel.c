#include <stdio.h>
#if defined(WIN)
#include<windows.h>		/* Sleep */
#else
#include<unistd.h>		/* usleep */
#endif
#include "../filterwheel.h"
#pragma GCC diagnostic ignored "-Wunused-parameter"
int filterwheel_init(char * filterwheel_device)
{
	return 0;
}

int filterwheel_send(int position)
{
#if defined(WIN)
	Sleep(2000);
#else
	sleep(2);
#endif
	return 0;
}

int filterwheel_uninit(void)
{
	return 0;
}
#pragma GCC diagnostic warning "-Wunused-parameter"
