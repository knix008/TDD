#ifndef __WAVSTRUCT_H__
#define __WAVSTRUCT_H__

#include <stdint.h>

struct FormatSubchunk
{
   uint16_t formatTag;
   uint16_t channels;
   uint32_t samplesPerSecond;
   uint32_t averageBytesPerSecond;
   uint16_t blockAlign;
   uint16_t bitsPerSample;
};

struct DataChunk
{
   uint32_t length;
};

#endif
