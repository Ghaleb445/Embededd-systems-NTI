#include "ADC.h"

void ADC_init(void)
{
	ADMUX = (1 << REFS0);  //5v

	
	ADMUX &= ~(1 << ADLAR);


	ADCSRA = (1 << ADPS2) |(1 << ADPS1); //64 *8=125 kH
}

void ADC_voidEnable(void)
{
	ADCSRA |= (1 << ADEN); //enable
}

void ADC_voidDisable(void)
{
	ADCSRA &= ~(1 << ADEN);
}

void ADC_voidStartConversion(u8 addresscpy)
{
	ADMUX &= 0xF8;   //PA0

	ADCSRA |= (1 << ADSC);

	while (ADCSRA & (1 << ADSC)); // RETURN 0
}

u16 ADC_u16ReadADC(void)
{
	return ADC;  //            5    1023
}                //           2.5   511.5  

u16 ADC_u16ReadADCInMV(void)
{
	u16 DigitalValue;
	u16 Voltage;

	DigitalValue = ADC;

	Voltage = ((u32)DigitalValue * 5000) / 1023;

	return Voltage;
}
