# Neo Pixel LED 
## !!! The document is not yet complete. !!!
\
Neo Pixel LED for STM32 HAL Library using Timer on PWM mode with DMA (Memory to Peripheral)
## How to use this library?

### First Step
Setup .ioc in your STM32IDE Project.
* Enable timer in PWM mode\
![ioc_setup_1](https://user-images.githubusercontent.com/42747938/147074852-d3ecea4f-cfba-48b7-8472-3cf0e0f3b0d4.png)
![alt text](https://github.com/[username]/[reponame]//tree/main/NeoPixel_LED_PWM/Image/ioc_setup_1.png?raw=true)

### Second Step
Define/add variable and function for this library in main.c\
NUM_LED in Neopixel.h
* This parameter is your number of your LED.
```bash
#define NUM_LED <Number_of_your_Neo_Pixel>
```
* Define NeopixelParameter.
```bash
NeopixelParameter <PARAMETER_NAME>;
```
* add this function in your main for stop DMA to tranfer data to Timer peripheral.
```bash
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim){
	HAL_TIM_PWM_Stop_DMA(<PARAMETER_NAME>.htim, <PARAMETER_NAME>.timer_Channel);
}
```
Try to use this library
* Initial function.
```bash
Neopixel_Init(&<PARAMETER_NAME>, &<htimx>,<TIM_CHANNEL_X>);
```
