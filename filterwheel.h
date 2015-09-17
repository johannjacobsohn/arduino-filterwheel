#ifndef _filterwheel_
#define _filterwheel_

#define FILTERWHEEL_CLOSED_A 1
#define FILTERWHEEL_CLOSED_B 1
#define FILTERWHEEL_OPENED_A 2
#define FILTERWHEEL_OPENED_B 2

int filterwheel_init(char * filterwheel_device);
int filterwheel_send(int position);
int filterwheel_uninit(void);
#endif
