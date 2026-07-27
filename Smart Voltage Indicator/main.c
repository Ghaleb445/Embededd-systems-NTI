#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "LCD.h"
#include "ADC.h"

#define RED_LED      PC0
#define YELLOW_LED   PC1
#define GREEN_LED    PC2

int main(void)
{
	u16 Voltage;
	char Buffer[10];

	DDRC |= (1<<RED_LED) | (1<<YELLOW_LED) | (1<<GREEN_LED);	   //o_put
	PORTC &= ~((1<<RED_LED) | (1<<YELLOW_LED) | (1<<GREEN_LED));   //off
 
 //LCD _Commands
	LCD_Init();
	LCD_Clear();
	ADC_init();
	ADC_voidEnable();



	while (1)
	{
		
		ADC_voidStartConversion(ADC_CH0);
		Voltage = ADC_u16ReadADCInMV();

		
		LCD_Command(0x80);
		LCD_String("Voltage = ");

		LCD_Command(0xC0);
		ltoa(Voltage, Buffer, 10);
		LCD_String(Buffer);
		LCD_String(" mV   ");

		
		PORTC &= ~((1<<RED_LED) | (1<<YELLOW_LED) | (1<<GREEN_LED));

		if (Voltage <= 1500)
		{
			PORTC |= (1<<RED_LED);
		}
		else if (Voltage <= 3000)
		{
			PORTC |= (1<<YELLOW_LED);
		}
		else
		{
			PORTC |= (1<<GREEN_LED);
		}

		_delay_ms(100);
	}
}
