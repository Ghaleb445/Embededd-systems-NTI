#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI.h"

void EXTI_Init(u8 INT_ID, u8 SenseMode)
{
	switch(INT_ID)
	{
		case INT0_ID:

		MCUCR &= ~((1<<ISC01)|(1<<ISC00));

		switch(SenseMode)
		{
			case LOW_LEVEL:
			break;

			case ANY_CHANGE:
			SET_BIT(MCUCR,ISC00);
			break;

			case FALLING_EDGE:
			SET_BIT(MCUCR,ISC01);
			break;

			case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		}

		break;

		case INT1_ID:

		MCUCR &= ~((1<<ISC11)|(1<<ISC10));

		switch(SenseMode)
		{
			case LOW_LEVEL:
			break;

			case ANY_CHANGE:
			SET_BIT(MCUCR,ISC10);
			break;

			case FALLING_EDGE:
			SET_BIT(MCUCR,ISC11);
			break;

			case RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		}

		break;

		case INT2_ID:

		if(SenseMode == FALLING_EDGE)
		CLR_BIT(MCUCSR,ISC2);

		else if(SenseMode == RISING_EDGE)
		SET_BIT(MCUCSR,ISC2);

		break;
	}
}

void EXTI_Enable(u8 INT_ID)
{
	switch(INT_ID)
	{
		case INT0_ID:
		SET_BIT(GICR,INT0);
		break;

		case INT1_ID:
		SET_BIT(GICR,INT1);
		break;

		case INT2_ID:
		SET_BIT(GICR,INT2);
		break;
	}
}

void EXTI_Disable(u8 INT_ID)
{
	switch(INT_ID)
	{
		case INT0_ID:
		CLR_BIT(GICR,INT0);
		break;

		case INT1_ID:
		CLR_BIT(GICR,INT1);
		break;

		case INT2_ID:
		CLR_BIT(GICR,INT2);
		break;
	}
}

void GIE_Enable(void)
{
	sei();
}

void GIE_Disable(void)
{
	cli();
}
