#include "WriteSample.h"

using namespace std;

void WriteSamples(ostringstream *out, char *data,
                 uint32_t startingSample,
                 uint32_t samplesToWrite,
                 uint32_t bytesPerSample)
{
    for (auto sample = startingSample;
         sample < startingSample + samplesToWrite;
         sample++)
    {
        auto byteOffsetForSample = sample * bytesPerSample;
        for (uint32_t byte{0}; byte < bytesPerSample; byte++)
        {
            out->put(data[byteOffsetForSample + byte]);
        }
    }
}