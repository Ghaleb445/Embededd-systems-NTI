#include "DIO.h"
#include <avr/io.h>

void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
	switch(Port)
	{
		case PORT_A:
		if(Direction == OUTPUT)
		DDRA |= (1 << Pin);
		else
		DDRA &= ~(1 << Pin);
		break;

		case PORT_B:
		if(Direction == OUTPUT)
		DDRB |= (1 << Pin);
		else
		DDRB &= ~(1 << Pin);
		break;

		case PORT_C:
		if(Direction == OUTPUT)
		DDRC |= (1 << Pin);
		else
		DDRC &= ~(1 << Pin);
		break;

		case PORT_D:
		if(Direction == OUTPUT)
		DDRD |= (1 << Pin);
		else
		DDRD &= ~(1 << Pin);
		break;
	}
}

void DIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
	switch(Port)
	{
		case PORT_A:
		if(Value == HIGH)
		PORTA |= (1 << Pin);
		else
		PORTA &= ~(1 << Pin);
		break;

		case PORT_B:
		if(Value == HIGH)
		PORTB |= (1 << Pin);
		else
		PORTB &= ~(1 << Pin);
		break;

		case PORT_C:
		if(Value == HIGH)
		PORTC |= (1 << Pin);
		else
		PORTC &= ~(1 << Pin);
		break;

		case PORT_D:
		if(Value == HIGH)
		PORTD |= (1 << Pin);
		else
		PORTD &= ~(1 << Pin);
		break;
	}
}

void DIO_TogglePinValue(u8 Port, u8 Pin)
{
	switch(Port)
	{
		case PORT_A: PORTA ^= (1 << Pin); break;
		case PORT_B: PORTB ^= (1 << Pin); break;
		case PORT_C: PORTC ^= (1 << Pin); break;
		case PORT_D: PORTD ^= (1 << Pin); break;
	}
}

u8 DIO_GetPinValue(u8 Port, u8 Pin)
{
	switch(Port)
	{
		case PORT_A: return (PINA >> Pin) & 1;
		case PORT_B: return (PINB >> Pin) & 1;
		case PORT_C: return (PINC >> Pin) & 1;
		case PORT_D: return (PIND >> Pin) & 1;
	}

	return 0;
}

void DIO_SetPortDirection(u8 Port, u8 Direction)
{
	switch(Port)
	{
		case PORT_A:
		DDRA = (Direction == OUTPUT) ? 0xFF : 0x00;
		break;

		case PORT_B:
		DDRB = (Direction == OUTPUT) ? 0xFF : 0x00;
		break;

		case PORT_C:
		DDRC = (Direction == OUTPUT) ? 0xFF : 0x00;
		break;

		case PORT_D:
		DDRD = (Direction == OUTPUT) ? 0xFF : 0x00;
		break;
	}
}

void DIO_SetPortValue(u8 Port, u8 Value)
{
	switch(Port)
	{
		case PORT_A:
		PORTA = Value;
		break;

		case PORT_B:
		PORTB = Value;
		break;

		case PORT_C:
		PORTC = Value;
		break;

		case PORT_D:
		PORTD = Value;
		break;
	}
}
