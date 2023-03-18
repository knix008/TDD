#ifndef __WRITESAMPLE_H__
#define __WRITESAMPLE_H__

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>

using namespace std;

void WriteSamples(ostringstream *out, char *data, uint32_t startingSample, uint32_t samplesToWrite, uint32_t bytesPerSample);

#endif