#include "stm32f4xx_hal.h"
#include "bmp280.h"


bool bmp280_is_connected(I2C_HandleTypeDef *i2c)
{
	HAL_StatusTypeDef hal_status;
	uint8_t bmp280_chipid_return[1];
	uint8_t bmp280_chipid_register[1] = {BMP280_CHIPID_REG};


	/* Send the CHIPID register over i2c to the BMP280 sensor, telling it that we want to read this register */
	hal_status = HAL_I2C_Master_Transmit(i2c, BMP280_ADDR, bmp280_chipid_register, 1, HAL_MAX_DELAY);
	if(hal_status != HAL_OK)
		return false;

	/* Read the CHIPID register via i2c back to us */
	hal_status = HAL_I2C_Master_Receive(i2c, BMP280_ADDR, bmp280_chipid_return, 1, HAL_MAX_DELAY);
	if(hal_status != HAL_OK)
		return false;

	/* If we receive a byte from the CHIPID register and it is 0x58 which is according to the BMP280 datasheet,
	 * then we know that the BMP280 sensor is connected. */
	if(bmp280_chipid_return[0] == 0x58)
		return true;

	return false;
}

bool bmp280_reset(I2C_HandleTypeDef *i2c)
{
	HAL_StatusTypeDef hal_status;
	uint8_t bmp280_reset_key[1] = {0xB6};

	hal_status = HAL_I2C_Mem_Write(i2c, BMP280_ADDR, BMP280_RESET_REG, I2C_MEMADD_SIZE_8BIT, bmp280_reset_key, 1, HAL_MAX_DELAY);
	if(hal_status != HAL_OK)
		return false;

	return true;
}

bool bmp280_init(I2C_HandleTypeDef *i2c, bmp280_init_t init_vars)
{
	HAL_StatusTypeDef hal_status;
	uint8_t init_register_data = (init_vars.temp_setting << 5) | (init_vars.pres_setting << 2) | init_vars.mode;

	hal_status = HAL_I2C_Mem_Write(i2c, BMP280_ADDR, BMP280_CTRL_REG, I2C_MEMADD_SIZE_8BIT, &init_register_data, 1, HAL_MAX_DELAY);
	if(hal_status != HAL_OK)
		return false;

	return true;
}
