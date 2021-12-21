# Neo Pixel LED 
## !!! The document is not yet complete. !!!
\
Neo Pixel LED for STM32 HAL Library using Timer on PWM mode with DMA (Memory to Peripheral)
## How to use this library?

### First Step 
Setup .ioc in your STM32IDE Project.\
...

### Second Step
Define/add variable and function for this library in main.c\
NUM_LED in Neopixel.h
* This parameter is your number of your LED.
```bash
#define NUM_LED <Number_of_your_Neo_Pixel>
```
Define NeopixelParameter.
```bash
NeopixelParameter <PARAMETER_NAME>;
```
Initial function.
```bash
Neopixel_Init(&<PARAMETER_NAME>, &<htimx>);
```

add this function in your main for stop DMA to tranfer data to Timer peripheral
```bash
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim){
	HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
}
```