#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

const u8 MAX_SPEED = 255;

void PrintSensorValue(const u16 *val) {
	/*
	 * Doesn't work because the value pointed
	 * to by "val" is marked as const.
	 * *val = 0;
	 */

	printf("Reading Sensor... Temperature is: %hu\n", *val);
}

int main(void) {
	const u32 DEVICE_ID = 987654321;
	const u32 *const id_ptr = &DEVICE_ID;
	u16 Temperature = 75;
	u8 PORTA_DATA = 0;
	u8 *const hardware_ptr = &PORTA_DATA;

	printf("System Booting...\n");
	/*
	 * Doesn't work because MAX_SPEED is
	 * declared as const.
	 * MAX_SPEED = 200;
	 */

	printf("Max Speed Configuration: %hu\n", MAX_SPEED);
	PrintSensorValue(&Temperature);

	*hardware_ptr = 100;
	printf("Hardware Port Data is now: %hu\n", PORTA_DATA);
	/*
	 * Doesn't work because hardware_ptr is
	 * a constant pointer pointing at variable
	 * data.
	 * hardware_ptr = &MAX_SPEED;
	 */

	printf("Device ID verified: %d\n", *id_ptr);
}