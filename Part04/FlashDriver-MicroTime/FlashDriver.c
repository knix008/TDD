#include "IO.h"
#include "FlashDriver.h"
#include "MicroTime.h"

void Flash_Create(void)
{
}

void Flash_Destroy(void)
{
}

static int writeError(int status)
{
    IO_Write(CommandRegister, Reset);
    if (status & VppErrorBit)
        return FLASH_VPP_ERROR;
    else if (status & ProgramErrorBit)
        return FLASH_PROGRAM_ERROR;
    else if (status & BlockProtectionErrorBit)
        return FLASH_PROTECTED_BLOCK_ERROR;
    else
        return FLASH_UNKNOWN_PROGRAM_ERROR;
}

int Flash_Write(ioAddress offset, ioData data)
{
    ioData status = 0;
    IO_Write(CommandRegister, ProgramCommand);
    IO_Write(offset, data);
    while ((status & ReadyBit) == 0)
        status = IO_Read(StatusRegister);
    if (status != ReadyBit)
        return writeError(status);
    if (data != IO_Read(offset))
        return FLASH_READ_BACK_ERROR;
    return FLASH_SUCCESS;
}