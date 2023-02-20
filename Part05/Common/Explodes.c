#include <assert.h>
#include "Explodes.h"

void explodesInTestEnvironment(void * p)
{
    p = p;
	assert(0 == "Explode - intercepted call that cannot be made in test environment");
}