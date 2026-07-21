#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	signed char i;

	unsigned char seven_segment[10] =
	{
		0x3F, /* 0 */
		0x06, /* 1 */
		0x5B, /* 2 */
		0x4F, /* 3 */
		0x66, /* 4 */
		0x6D, /* 5 */
		0x7D, /* 6 */
		0x07, /* 7 */
		0x7F, /* 8 */
		0x6F  /* 9 */
	};

	
	DDRA = 0x07;

	
	DDRC = 0xFF;
	DDRD = 0xFF;

	while (1)
	{
		
		PORTA = (1 << PA2);

		for (i = 10; i >= 1; i--)
		{
			PORTC = seven_segment[i / 10]; 
			PORTD = seven_segment[i % 10]; 

			_delay_ms(1000);
		}

		
		PORTA = (1 << PA1);

		for (i = 3; i >= 1; i--)
		{
			PORTC = seven_segment[i / 10];
			PORTD = seven_segment[i % 10];

			_delay_ms(1000);
		}

		
		PORTA = (1 << PA0);

		for (i = 10; i >= 1; i--)
		{
			PORTC = seven_segment[i / 10];
			PORTD = seven_segment[i % 10];

			_delay_ms(1000);
		}
	}

	return 0;
}
