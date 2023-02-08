#include <stdio.h>
#include "FakeRandomMinute.h"

static int seed = -1;
static int increment = -1;

void FakeRandomMinute_Reset(void)
{
	seed = -1;
	increment = -1;
}

void FakeRandomMinute_SetFirstAndIncrement(int s, int i)
{
	seed = s;
	increment = i;
	printf("Setting the seed and increments: %d, %d\n", seed, i);
}

int FakeRandomMinute_Get(void)
{
	printf("Calling FakeMinuteGet()!!!");
	int result = seed;
	seed += increment;
	printf("Getting the result : %d\n", result);
	return result;
}