#ifndef __SNIPPET_H__
#define __SNIPPET_H__

using namespace std;

class Snippet
{
public:
    Snippet(shared_ptr<FileUtil> fileUtil,
            shared_ptr<WavDescriptor> descriptor,
            const std::string &dest,
            rlog::RLogChannel *channel)
        : fileUtil_(fileUtil), descriptor_(descriptor), dest_(dest), channel_(channel) {}

    uint32_t dataLength(
        uint32_t samples,
        uint32_t bytesPerSample,
        uint32_t channels) const
    {
        return samples * bytesPerSample * channels;
    }

private:
    shared_ptr<FileUtil> fileUtil_;
    shared_ptr<WavDescriptor> descriptor_;
    const string dest_;
    rlog::RLogChannel *channel_;
};

#endif