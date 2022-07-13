#pragma once

#define BQ2589X_I2C_ADDR (0x6A << 1)

extern I2C_HandleTypeDef hi2c1;


static HAL_StatusTypeDef bq2589x_read_reg(uint8_t regNum, uint8_t* regData)
{
	{
//		HAL_StatusTypeDef res = HAL_I2C_IsDeviceReady(&hi2c1, 0x6A << 1, 1, HAL_MAX_DELAY);
//		if(res != HAL_OK)
//			return res;
	}

	{
		uint8_t txBuf[1] = {regNum};
		HAL_StatusTypeDef res = HAL_I2C_Master_Transmit(&hi2c1, BQ2589X_I2C_ADDR, txBuf, sizeof(txBuf), 200);
		if(res != HAL_OK)
			return res;
	}

	{
		//uint8_t rxBuf[1];
		HAL_StatusTypeDef res = HAL_I2C_Master_Receive(&hi2c1, BQ2589X_I2C_ADDR, regData, 1, 200);
		if(res != HAL_OK)
			return res;
	}
	return HAL_OK;
}

static HAL_StatusTypeDef bq2589x_write_byte(uint8_t regNum, uint8_t* regData)
{
	uint8_t txBuf[2] = {regNum, *regData};
	HAL_StatusTypeDef res = HAL_I2C_Master_Transmit(&hi2c1, BQ2589X_I2C_ADDR, txBuf, sizeof(txBuf), 200);
	return res;
}

static HAL_StatusTypeDef bq2589x_update_bits(uint8_t reg, uint8_t mask, uint8_t data)
{
	uint8_t tmp;
	HAL_StatusTypeDef res = bq2589x_read_reg(reg, &tmp);
	if(res != HAL_OK)
		return res;

	tmp &= ~mask;
	tmp |= data & mask;

	return bq2589x_write_byte(reg, &tmp);
}

static HAL_StatusTypeDef bq2589x_disable_watchdog_timer()
{
	uint8_t val = 0 << 4;

	return bq2589x_update_bits(0x07, 0x30, val);
}

static int bq2589x_adc_start(uint8_t oneshot)
{
	uint8_t val;
	HAL_StatusTypeDef res = bq2589x_read_reg(0x02, &val);
	if(res != HAL_OK)
		return res;

	{
		//	if (((val & BQ2589X_CONV_RATE_MASK) >> BQ2589X_CONV_RATE_SHIFT) == BQ2589X_ADC_CONTINUE_ENABLE)
		//		return 0; /*is doing continuous scan*/
		//	if (oneshot)
		//		ret = bq2589x_update_bits(bq, BQ2589X_REG_02, BQ2589X_CONV_START_MASK, BQ2589X_CONV_START << BQ2589X_CONV_START_SHIFT);
		//	else
		if ((val & (1 << 6)) == 0)
		{
			uint8_t mask = (1 << 7) | (1 << 6);
			uint8_t val = (1 << 7) | (1 << 6);
			HAL_StatusTypeDef res = bq2589x_update_bits(0x02, mask, val);
			if(res != HAL_OK)
				return res;
			res = bq2589x_update_bits(0x02, 0x40, 1 << 6);
			if(res != HAL_OK)
				return res;
		}
	}

	{
		uint8_t val;
		HAL_StatusTypeDef res = bq2589x_read_reg(0x02, &val);
		if(res != HAL_OK)
			return res;
	}

	return HAL_OK;
}

static int bq2589x_adc_read_battery_volt()
{
	uint8_t rxVal;
//	HAL_StatusTypeDef res = bq2589x_read_reg(0x0E, &rxVal);
	HAL_StatusTypeDef res = bq2589x_read_reg(0x0F, &rxVal);
	if(res != HAL_OK)
		return 0;
	int val = 2304 + ((rxVal & 0x7F) >> 0) * 20;
	return val;
}

int static bq2589x_adc_read_temperature()
{
	uint8_t rxVal;
	HAL_StatusTypeDef res = bq2589x_read_reg(0x10, &rxVal);
	if(res != HAL_OK)
		return 0;
	int val = 21000 + ((rxVal & 0x7F) >> 0) * 465;
	return val;
}

