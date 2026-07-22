#include "DIO.h"
#include <util/delay.h>

void DIO_SetPinDirection(unsigned char port,unsigned char pin,unsigned char direction)
{
	switch(port)
	{
		case PORT_A:
		if(direction==OUTPUT)
		DDRA |= (1<<pin);
		else
		DDRA &= ~(1<<pin);
		break;

		case PORT_B:
		if(direction==OUTPUT)
		DDRB |= (1<<pin);
		else
		DDRB &= ~(1<<pin);
		break;

		case PORT_C:
		if(direction==OUTPUT)
		DDRC |= (1<<pin);
		else
		DDRC &= ~(1<<pin);
		break;

		case PORT_D:
		if(direction==OUTPUT)
		DDRD |= (1<<pin);
		else
		DDRD &= ~(1<<pin);
		break;
	}
}

void DIO_SetPinValue(unsigned char port,unsigned char pin,unsigned char value)
{
	switch(port)
	{
		case PORT_A:
		if(value==HIGH)
		PORTA |= (1<<pin);
		else
		PORTA &= ~(1<<pin);
		break;

		case PORT_B:
		if(value==HIGH)
		PORTB |= (1<<pin);
		else
		PORTB &= ~(1<<pin);
		break;

		case PORT_C:
		if(value==HIGH)
		PORTC |= (1<<pin);
		else
		PORTC &= ~(1<<pin);
		break;

		case PORT_D:
		if(value==HIGH)
		PORTD |= (1<<pin);
		else
		PORTD &= ~(1<<pin);
		break;
	}
}

void DIO_TogglePinValue(unsigned char port,unsigned char pin)
{
	switch(port)
	{
		case PORT_A:
		PORTA ^= (1<<pin);
		break;

		case PORT_B:
		PORTB ^= (1<<pin);
		break;

		case PORT_C:
		PORTC ^= (1<<pin);
		break;

		case PORT_D:
		PORTD ^= (1<<pin);
		break;
	}
}

unsigned char DIO_GetPinValue(unsigned char port,unsigned char pin)
{
	switch(port)
	{
		case PORT_A:
		return (PINA&(1<<pin))?HIGH:LOW;

		case PORT_B:
		return (PINB&(1<<pin))?HIGH:LOW;

		case PORT_C:
		return (PINC&(1<<pin))?HIGH:LOW;

		case PORT_D:
		return (PIND&(1<<pin))?HIGH:LOW;
	}

	return LOW;
}
