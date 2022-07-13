#pragma once

#include "glo_uart.h"
#include "glo_leds.h"
#include "glo_bq25898d.h"


static void app_main()
{
	glo_uart_write_str("start\r\n");
	glo_leds_set_leds(0b1111, 0);

//	glo_leds_set_led(0, 1);
//	glo_leds_set_led(1, 1);
//	glo_leds_set_led(2, 1);
//	glo_leds_set_led(3, 1);

	HAL_GPIO_WritePin(GLO_EH_POWER_GPIO_Port, GLO_EH_POWER_Pin, GPIO_PIN_RESET);

	size_t iter = 0;

	bq2589x_disable_watchdog_timer();

	bq2589x_set_minimum_system_voltage_limit();

	while (1)
	{
//		{
//			HAL_StatusTypeDef res = HAL_I2C_IsDeviceReady(&hi2c1, 0x6A << 1, 1, HAL_MAX_DELAY);
//			if(res == HAL_OK)
//				glo_leds_set_led(1, 1);
//			else
//				glo_leds_set_led(1, 0);
//		}

		{
			bq2589x_adc_start(0);
			int vbat = bq2589x_adc_read_battery_volt();
			int tbat = bq2589x_adc_read_temperature();

			glo_uart_write_str("vbat = ");
			glo_uart_write_int(vbat);
			glo_uart_write_str(" tbat = ");
			glo_uart_write_int(tbat);
			glo_uart_write_str("\r\n");

//			if(vbat > 3000 || tbat > 21000)
//			{
//				glo_leds_set_led(2, 1);
//			}
//			else
//			{
//				glo_leds_set_led(2, 0);
//			}

			{
				int v = vbat - 3000;
				v /= 1000 / 4;
				if(v < 1)
					v = 1;
				if(v > 4)
					v = 4;
				uint8_t leds = 0;
				switch(v)
				{
				case 4:
					leds |= 0b1000;
				case 3:
					leds |= 0b0100;
				case 2:
					leds |= 0b0010;
				case 1:
					leds |= 0b001;
				}
				glo_leds_set_leds(~leds, 0);
				glo_leds_set_leds(leds, 1);
			}
		}

		{
//			GPIO_PinState b = HAL_GPIO_ReadPin(GLO_BUTTON1_GPIO_Port, GLO_BUTTON1_Pin);
//			if(b == GPIO_PIN_SET)
//				glo_leds_set_led(0, 1);
//			else
//				glo_leds_set_led(0, 0);
		}

//		HAL_GPIO_WritePin(GLO_LED1_GPIO_Port, GLO_LED1_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GLO_LED2_GPIO_Port, GLO_LED2_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GLO_LED3_GPIO_Port, GLO_LED3_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GLO_LED4_GPIO_Port, GLO_LED4_Pin, GPIO_PIN_SET);
//
//		if(iter % 4 == 0)
//			HAL_GPIO_WritePin(GLO_LED1_GPIO_Port, GLO_LED1_Pin, GPIO_PIN_RESET);
//		if(iter % 4 == 1)
//			HAL_GPIO_WritePin(GLO_LED2_GPIO_Port, GLO_LED2_Pin, GPIO_PIN_RESET);
//		if(iter % 4 == 2)
//			HAL_GPIO_WritePin(GLO_LED3_GPIO_Port, GLO_LED3_Pin, GPIO_PIN_RESET);
//		if(iter % 4 == 3)
//			HAL_GPIO_WritePin(GLO_LED4_GPIO_Port, GLO_LED4_Pin, GPIO_PIN_RESET);


		HAL_Delay(50);

		iter++;
	}

}
