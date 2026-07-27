#define F_CPU 8000000UL
#include "LCD.h"
#include "DIO.h"
#include <util/delay.h>

static void LCD_EnablePulse(void)
{
	DIO_SetPinValue(PORT_C, PIN7, HIGH);
	_delay_ms(2);
	DIO_SetPinValue(PORT_C, PIN7, LOW);
}

void LCD_Command(u8 cmd)
{
	DIO_SetPinValue(PORT_C, PIN5, LOW);   // RS = 0
	DIO_SetPinValue(PORT_C, PIN6, LOW);   // RW = 0

	DIO_SetPortValue(PORT_D, cmd);

	LCD_EnablePulse();

	_delay_ms(2);
}

void LCD_Char(u8 data)
{
	DIO_SetPinValue(PORT_C, PIN5, HIGH);  // RS = 1
	DIO_SetPinValue(PORT_C, PIN6, LOW);   // RW = 0

	DIO_SetPortValue(PORT_D, data);

	LCD_EnablePulse();

	_delay_ms(2);
}

void LCD_String(char *str)
{
	while(*str)
	{
		LCD_Char(*str++);
	}
}

void LCD_Clear(void)
{
	LCD_Command(0x01);
	_delay_ms(2);
}

void LCD_Init(void)
{
	DIO_SetPortDirection(PORT_D, OUTPUT);

	DIO_SetPinDirection(PORT_C, PIN5, OUTPUT);
	DIO_SetPinDirection(PORT_C, PIN6, OUTPUT);
	DIO_SetPinDirection(PORT_C, PIN7, OUTPUT);

	_delay_ms(20);

	LCD_Command(0x38);   
	LCD_Command(0x0C);   
	LCD_Command(0x06);   
	LCD_Command(0x01);   

	_delay_ms(2);
}
