/*
 * bmp280.h
 *
 *  Created on: Nov 2, 2024
 *      Author: Youri Klaassens
 */

#ifndef INC_BMP280_H_
#define INC_BMP280_H_

#include "stm32f4xx_hal.h"
#include <stdbool.h>

#define BMP280_ADDR		(0x77 << 1)

#define BMP280_CHIPID_REG		0xD0
#define BMP280_RESET_REG		0xE0
#define BMP280_CTRL_REG			0xF4

typedef enum
{
	BMP280_MODE_SLEEP = 0x00,
	BMP280_MODE_FORCED = 0x01,
	BMP280_MODE_NORMAL = 0x03
} bmp280_mode_t;

typedef enum
{
	BMP280_PRESSURE_OFF = 0x00,
	BMP280_OVERSAMPLE_1 = 0x01,
	BMP280_OVERSAMPLE_2 = 0x02,
	BMP280_OVERSAMPLE_4 = 0x03,
	BMP280_OVERSAMPLE_8 = 0x04,
	BMP280_OVERSAMPLE_16 = 0x05
} bmp280_pressure_mode_t;

typedef enum
{
	BMP280_TEMPERATURE_OFF = 0x00,
	BMP280_TEMPERATURE_1 = 0x01,
	BMP280_TEMPERATURE_2 = 0x02,
	BMP280_TEMPERATURE_4 = 0x03,
	BMP280_TEMPERATURE_8 = 0x04,
	BMP280_TEMPERATURE_16 = 0x05
} bmp280_temperature_mode_t;

typedef struct
{
	bmp280_temperature_mode_t temp_setting;
	bmp280_pressure_mode_t pres_setting;
	bmp280_mode_t mode;
} bmp280_init_t;


bool bmp280_is_connected(I2C_HandleTypeDef *i2c);

bool bmp280_reset(I2C_HandleTypeDef *i2c);

bool bmp280_init(I2C_HandleTypeDef *i2c, bmp280_init_t init_vars);


#endif /* BMP280_H */
