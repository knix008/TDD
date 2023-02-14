#include "LightDriver.h"
#include "LightController.h"

LightDriver LightDriverSpy_Create(int id);
void LightDriverSpy_Destroy(LightDriver);
void LightDriverSpy_TurnOn(LightDriver);
void LightDriverSpy_TurnOff(LightDriver);
/* Functions just needed by the spy */
void LightDriverSpy_Reset(void);
int LightDriverSpy_GetState(int id);
int LightDriverSpy_GetLastId(void);
int LightDriverSpy_GetLastState(void);
void LightDriverSpy_AddSpiesToController(void);

enum
{
    LIGHT_ID_UNKNOWN = -1,
    LIGHT_STATE_UNKNOWN = -1,
    LIGHT_OFF = 0,
    LIGHT_ON = 1
};