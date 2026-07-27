#ifndef EXTI_H_
#define EXTI_H_

#include "STD_TYPES.h"

#define LOW_LEVEL      0
#define IOC            1
#define FALLING_EDGE   2
#define RISING_EDGE    3

void EXTI_INT0_Init(u8 Trigger);

#endif
