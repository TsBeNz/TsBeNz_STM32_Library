# Neo Pixel LED
## for STM32 HAL Library
first define NUM_LED in Neopixel.h
This parameter is your number of your LED
Edit ?? to your number of LED
```bash
#define NUM_LED ??
```


add this function in your main
```bash
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim){
	HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
}
```
