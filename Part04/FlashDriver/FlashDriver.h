#ifndef __FLASHDRIVER_H__
#define __FLASHDRIVER_H__

void Flash_Create(void);
void Flash_Destroy(void);
int Flash_Write(ioAddress offset, ioData data);

typedef enum
{
	FLASH_SUCCESS = 0,
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

typedef enum
{
	ReadyBit = 1 << 7,
} StatusRegisterBits;

#endif