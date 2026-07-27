#ifndef EXTI_H_
#define EXTI_H_

#include "STD_TYPES.h"


#define INT0_ID      0
#define INT1_ID      1
#define INT2_ID      2


#define LOW_LEVEL      0
#define ANY_CHANGE     1
#define FALLING_EDGE   2
#define RISING_EDGE    3

void EXTI_Init(u8 INT_ID, u8 SenseMode);
void EXTI_Enable(u8 INT_ID);
void EXTI_Disable(u8 INT_ID);
void GIE_Enable(void);
void GIE_Disable(void);

#endif
