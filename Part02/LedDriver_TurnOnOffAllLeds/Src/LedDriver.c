#include "LedDriver.h"

static uint16_t *ledsAddress;

void LedDriver_Create(uint16_t *address)
{
    ledsAddress = address;
    *ledsAddress = 0;
}

void LedDriver_Destroy(void)
{
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
    *ledsAddress &= ~(convertLedNumberToBit(ledNumber));
}

enum
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

void LedDriver_TurnAllOn(void)
{
    *ledsAddress = ALL_LEDS_ON;
}
