#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI.h"

void EXTI_INT0_Init(u8 Trigger)
{
	switch(Trigger)
	{
		case LOW_LEVEL:
		CLR_BIT(MCUCR,ISC00);
		CLR_BIT(MCUCR,ISC01);
		break;

		case IOC:
		SET_BIT(MCUCR,ISC00);
		CLR_BIT(MCUCR,ISC01);
		break;

		case FALLING_EDGE:
		CLR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;

		case RISING_EDGE:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;
	}

	
	SET_BIT(GICR,INT0);
}
