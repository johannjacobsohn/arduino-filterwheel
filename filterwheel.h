#ifndef _filterwheel_
#define _filterwheel_
int filterwheel_init(char * device);
int filterwheel_send(int position);
int filterwheel_uninit(void);
#endif
