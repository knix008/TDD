#ifndef __FAKEMICROTIME_H__
#define __FAKEMICROTIME_H__

#include "MicroTime.h"

void FakeMicroTime_Init(uint32_t start, uint32_t increment);
uint32_t FakeMicroTime_GetDelayDuration();

#endif