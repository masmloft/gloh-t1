#pragma once


extern UART_HandleTypeDef huart1;


static HAL_StatusTypeDef glo_uart_write_buf(const char* buf, uint16_t size, uint32_t timeout)
{
	HAL_StatusTypeDef res = HAL_UART_Transmit(&huart1, (const uint8_t*)buf, size, timeout);
	return res;
}

static HAL_StatusTypeDef glo_uart_write_str(const char* buf)
{
	uint16_t size = strlen(buf);
	return glo_uart_write_buf(buf, size, 100);
}

static HAL_StatusTypeDef glo_uart_write_int(int val)
{
	char buf[12];
	itoa(val, buf, 10);
	uint16_t size = strlen(buf);
	return glo_uart_write_buf(buf, size, 100);
}
