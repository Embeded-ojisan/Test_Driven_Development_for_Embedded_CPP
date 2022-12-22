#include <stdint.h>
#include <stdbool.h>

extern void LedDriver_Create(uint16_t*);

extern void LedDriver_TurnOn(int);
extern void LedDriver_TurnAllOn(void);

extern void LedDriver_TurnOff(int);

extern bool LedDriver_IsOn(int);