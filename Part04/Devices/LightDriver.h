#ifndef __LIGHTDRIVER_H__
#define __LIGHTDRIVER_H__

typedef struct LightDriverStruct *LightDriver;

typedef enum LightDriverType
{
    TestLightDriver,
    X10,
    AcmeWireless,
    MemoryMapped
} LightDriverType;

typedef struct LightDriverStruct
{
    LightDriverType type;
    int id;
} LightDriverStruct;

#endif