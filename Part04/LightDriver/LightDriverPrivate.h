#ifndef __LIGHTDRIVER_PRIVATE_H__
#define __LIGHTDRIVER_PRIVATE_H__

typedef struct LightDriverInterfaceStruct *LightDriverInterface;

typedef struct LightDriverStruct
{
    LightDriverInterface vtable;
    const char *type;
    int id;
} LightDriverStruct;

typedef struct LightDriverInterfaceStruct
{
    void (*TurnOn)(LightDriver);
    void (*TurnOff)(LightDriver);
    void (*Destroy)(LightDriver);
} LightDriverInterfaceStruct;

#endif