#ifndef _RUNTIMEERROR_H_
#define _RUNTIMEERROR_H_

void RuntimeError(const char * message, int parameter, const char * file, int line);

#define RUNTIME_ERROR(description, parameter) \
        RuntimeError(description, parameter, __FILE__, __LINE__)

#endif
