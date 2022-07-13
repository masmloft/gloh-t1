#pragma once



static void glo_leds_set_led(int led_num, int is_on)
{
	GPIO_PinState pin_state = (is_on) ? GPIO_PIN_RESET : GPIO_PIN_SET;
	if(led_num == 0)
		HAL_GPIO_WritePin(GLO_LED0_GPIO_Port, GLO_LED0_Pin, pin_state);
	if(led_num == 1)
		HAL_GPIO_WritePin(GLO_LED1_GPIO_Port, GLO_LED1_Pin, pin_state);
	if(led_num == 2)
		HAL_GPIO_WritePin(GLO_LED2_GPIO_Port, GLO_LED2_Pin, pin_state);
	if(led_num == 3)
		HAL_GPIO_WritePin(GLO_LED3_GPIO_Port, GLO_LED3_Pin, pin_state);
}

static void glo_leds_set_leds(int led_mask, int is_on)
{
	GPIO_PinState pin_state = (is_on) ? GPIO_PIN_RESET : GPIO_PIN_SET;
	if(led_mask & 0b0001)
		HAL_GPIO_WritePin(GLO_LED0_GPIO_Port, GLO_LED0_Pin, pin_state);
	if(led_mask & 0b0010)
		HAL_GPIO_WritePin(GLO_LED1_GPIO_Port, GLO_LED1_Pin, pin_state);
	if(led_mask & 0b0100)
		HAL_GPIO_WritePin(GLO_LED2_GPIO_Port, GLO_LED2_Pin, pin_state);
	if(led_mask & 0b1000)
		HAL_GPIO_WritePin(GLO_LED3_GPIO_Port, GLO_LED3_Pin, pin_state);
}
