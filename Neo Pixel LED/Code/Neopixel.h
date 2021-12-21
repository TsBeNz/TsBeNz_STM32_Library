/*
 * Neopixel.h
 *
 *  Created on: Nov 22, 2021
 *      Author: thans
 */

#ifndef INC_NEOPIXEL_H_
#define INC_NEOPIXEL_H_

// include stm32h7 driver
#include "stm32h7xx.h"

#define NUM_LED 2


typedef struct {
	uint32_t pwmData[(NUM_LED*24)+42];
	uint8_t LED_Data[NUM_LED][3];
	TIM_HandleTypeDef *htim;
}NeopixelParameter;

void Neopixel_Init(NeopixelParameter *Neopixel_led ,TIM_HandleTypeDef *htim_in);
void Neopixel_Set(NeopixelParameter *Neopixel_led,uint8_t LEDnum, uint8_t Red, uint8_t Green, uint8_t Blue);
void Neopixel_Sent(NeopixelParameter *Neopixel_led);

#endif /* INC_NEOPIXEL_H_ */
