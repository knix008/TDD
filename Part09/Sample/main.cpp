#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void WriteSample(ostringstream *out, char *data,
                 uint32_t startingSample,
                 uint32_t samplesToWrite,
                 uint32_t bytesPerSample)
{
    for (auto sample = startingSample;
         sample < startingSample + samplesToWrite;
         sample++)
    {
        auto byteOffsetForSample = sample + bytesPerSample;
        for (uint32_t byte{0}; byte < bytesPerSample; byte++)
        {
            out->put(data[byteOffsetForSample + byte]);
        }
        cout << "Inp;ut : " << data << endl;
        cout << "Result : " << out->str() << endl;
    }
}

int main()
{
    ostringstream out;

    char data[]{"abcd"};
    uint32_t bytesPerSample{1};
    uint32_t startingSample{0};
    uint32_t samplesToWrite{1};

    WriteSample(&out, data, startingSample, samplesToWrite, bytesPerSample);
    return 0;
}
