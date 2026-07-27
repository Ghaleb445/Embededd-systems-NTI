#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "EXTI.h"

int main(void)
{

	DIO_SetPinDirection(PORT_C, PIN0, OUTPUT);
	DIO_SetPinDirection(PORT_C, PIN1, OUTPUT);


	DIO_SetPinDirection(PORT_D, PIN2, INPUT);   
	DIO_SetPinDirection(PORT_D, PIN3, INPUT);   


	DIO_SetPinValue(PORT_D, PIN2, HIGH);
	DIO_SetPinValue(PORT_D, PIN3, HIGH);


	EXTI_Init(INT0_ID, ANY_CHANGE);
	EXTI_Init(INT1_ID, ANY_CHANGE);

	EXTI_Enable(INT0_ID);
	EXTI_Enable(INT1_ID);

	GIE_Enable();

	while(1)
	{

	}
}


ISR(INT0_vect)
{
	DIO_TogglePinValue(PORT_C, PIN0);
}


ISR(INT1_vect)
{
	DIO_TogglePinValue(PORT_C, PIN1);
}
