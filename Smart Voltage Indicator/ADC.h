#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include "STD_TYPES.h"

#define ADC_CH0    0
#define ADC_CH1    1
#define ADC_CH2    2
#define ADC_CH3    3
#define ADC_CH4    4
#define ADC_CH5    5
#define ADC_CH6    6
#define ADC_CH7    7

void ADC_init(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
u16 ADC_u16ReadADC(void);
void ADC_voidStartConversion(u8 addresscpy);
u16 ADC_u16ReadADCInMV(void);

#endif
