#ifndef _filterwheel_
#define _filterwheel_

#include "configurations.h"

static int FILTERWHEEL_CLOSED_A = 1;
static int FILTERWHEEL_CLOSED_B = 1;
static int FILTERWHEEL_OPENED_A = 2;
static int FILTERWHEEL_OPENED_B = 2;

int filterwheel_init(sConfigStruct * config);
int filterwheel_send(int position);
int filterwheel_uninit(sConfigStruct * config);
#endif
