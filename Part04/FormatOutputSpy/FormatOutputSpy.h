#ifndef __FORMATOUTPUTSPY_H__
#define __FORMATOUTPUTSPY_H__

int FormatOutputSpy(const char *format, ...);
void FormatOutputSpy_Create(int size);
void FormatOutputSpy_Destroy(void);
const char *FormatOutputSpy_GetOutput(void);

#endif