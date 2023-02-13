#include <CppUTestExt/MockSupport_c.h>
#include "IOMock.h"

void IO_Write(ioAddress addr, ioData value)
{
    mock_c()->actualCall("IO_Write")->withIntParameters("addr", addr)->withIntParameters("value", value);
}

ioData IO_Read(ioAddress addr)
{
    mock_c()->actualCall("IO_Read")->withIntParameters("addr", addr);
    return mock_c()->returnValue().value.intValue;
}