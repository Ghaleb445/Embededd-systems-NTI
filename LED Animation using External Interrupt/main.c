#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "EXTI.h"

volatile u8 Animation_Mode = 0;


ISR(INT0_vect)
{
	Animation_Mode++;

	if(Animation_Mode > 2)
	{
		Animation_Mode = 0;
	}
}

int main(void)
{
	u8 i;

	
	for(i = 0; i < 8; i++)
	{
		DIO_SetPinDirection(PORT_C, i, OUTPUT);
	}

	DIO_SetPinDirection(PORT_D, PIN2, INPUT);

	
	DIO_SetPinValue(PORT_D, PIN2, HIGH);

	
	EXTI_INT0_Init(IOC);

	
	sei();

	while(1)
	{
		switch(Animation_Mode)
		{
			
			case 0:
			for(i = 0; i < 8; i++)
			{
				PORTC = (1 << i);
				_delay_ms(150);

				if(Animation_Mode != 0)
				break;
			}
			break;

			
			case 1:
			for(i = 7; i > 0; i--)
			{
				PORTC = (1 << i);
				_delay_ms(150);

				if(Animation_Mode != 1)
				break;
			}

			if(Animation_Mode == 1)
			{
				PORTC = (1 << 0);
				_delay_ms(150);
			}

			break;

			
			case 2:
			PORTC = 0xFF;
			_delay_ms(300);

			if(Animation_Mode != 2)
			break;

			PORTC = 0x00;
			_delay_ms(300);
			break;
		}
	}
}
