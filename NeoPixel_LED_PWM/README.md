# Neo Pixel LED 
## !!! The document is not yet complete. !!!
\
Neo Pixel LED for STM32 HAL Library using Timer on PWM mode with DMA (Memory to Peripheral)
## How to use this library?

### First Step
Setup .ioc in your STM32IDE Project.
* Enable timer with PWM mode\
![image](https://github.com/TsBeNz/TsBeNz_STM32_Library/blob/main/NeoPixel_LED_PWM/Image/ioc_setup_1.png?raw=True)
![image](https://github.com/TsBeNz/TsBeNz_STM32_Library/blob/main/NeoPixel_LED_PWM/Image/ioc_setup_2.png?raw=True)
* Enable DMA in PWM channal
![image](https://github.com/TsBeNz/TsBeNz_STM32_Library/blob/main/NeoPixel_LED_PWM/Image/DMA_setup.png?raw=True)

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
<!-- * สามารถตั้งค่าสีของไฟเเต่ละดวงได้โดยใช้ฟังก์ชั่นนี้ -->
* Set LED color function.
```bash
Neopixel_Set(&<PARAMETER_NAME>, <Number_of_LED>, <Red_value>, <Green_value>, <Blue_value>);
```

*