#ifndef __SNIPPET_H__
#define __SNIPPET_H__

using namespace std;

class Snippet
{
public:
    uint32_t dataLength(
        uint32_t samples,
        uint32_t bytesPerSample,
        uint32_t channels) const
    {
        return samples * bytesPerSample * channels;
    }
};

#endif