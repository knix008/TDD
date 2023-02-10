#ifndef __FLASHDRIVER_H__
#define __FLASHDRIVER_H__

void Flash_Create(void);
void Flash_Destroy(void);
int Flash_Write(ioAddress offset, ioData data);

typedef enum
{
	FLASH_SUCCESS = 0,
	FLASH_VPP_ERROR,
	FLASH_PROGRAM_ERROR,
	FLASH_PROTECTED_BLOCK_ERROR,
	FLASH_UNKNOWN_PROGRAM_ERROR,
	FLASH_READ_BACK_ERROR,
	FLASH_TIMEOUT_ERROR
} FlashStatus;

typedef enum
{
	CommandRegister = 0x0,
	StatusRegister = 0x0
} Flash_Registers;

typedef enum
{
	ProgramCommand = 0x40,
	Reset = 0xff
} Flash_Command;

#endif