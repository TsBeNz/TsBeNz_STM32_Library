/*
 * Neopixel.c
 *
 *  Created on: Nov 22, 2021
 *      Author: thans
 */

#include "Neopixel.h"

void Neopixel_Init(NeopixelParameter *Neopixel_led ,TIM_HandleTypeDef *htim_in){
	Neopixel_led->htim = htim_in;
}

inline void Neopixel_Set(NeopixelParameter *Neopixel_led, uint8_t LEDnum,
		uint8_t Red, uint8_t Green, uint8_t Blue) {
	Neopixel_led->LED_Data[LEDnum][0] = Green;
	Neopixel_led->LED_Data[LEDnum][1] = Red;
	Neopixel_led->LED_Data[LEDnum][2] = Blue;
}

inline void Neopixel_Sent(NeopixelParameter *Neopixel_led) {
	uint32_t index = 0;
	uint32_t data;
	for (int j = 0; j < MAX_LED; j++) {
		data = ((Neopixel_led->LED_Data[j][0] & 0xFF) << 16)
				| ((Neopixel_led->LED_Data[j][1] & 0xFF) << 8)
				| (Neopixel_led->LED_Data[j][2] & 0xFF);
		for (int i = 23; i >= 0; i--) {
			if (data & (1 << i)) {
				Neopixel_led->pwmData[index] = 192;
			} else {
				Neopixel_led->pwmData[index] = 96;
			}
			index++;
		}
	}
	for (int i = 0; i < 42; i++) {
		Neopixel_led->pwmData[index] = 0;
		index++;
	}
	HAL_TIM_PWM_Start_DMA(Neopixel_led->htim, TIM_CHANNEL_1,
			Neopixel_led->pwmData, index);
}
