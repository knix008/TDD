#ifndef __FAKERANDOMMINUTE_H__
#define __FAKERANDOMMINUTE_H__

#include "RandomMinute.h"

void FakeRandomMinute_SetFirstAndIncrement(int seed, int increment);
int FakeRandomMinute_Get(void);
void FakeRandomMinute_Reset(void);

#endif