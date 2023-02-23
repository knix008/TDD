#ifndef __M28W160ECT_H__
#define __M28W160ECT_H__

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
	ReadyBit = 1<<7,
	EraseSuspendBit = 1<<6,
	EraseErrorBit = 1<<5,
	ProgramErrorBit = 1<<4,
	VppErrorBit = 1<<3,
	ProgramSuspendBit = 1<<2,
	BlockProtectionErrorBit = 1<<1,
	ReservedBit = 1
} StatusRegisterBits;

#endif
