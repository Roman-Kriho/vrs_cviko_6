/*
 * lps25.c
 *
 *  Created on: Nov 4, 2023
 *      Author: romyk
 */

#include "lps25hb.h"
#include "hts221.h"
#include "stdio.h"
#include "string.h"
#include <math.h>

#define N_REF_SAMPLES 500
#define PRESSURE_0 1013.25


uint8_t lps25hb_address = LPS25HB_DEVICE_ADDRESS0;

// LPS25HB_read_byte implementation
uint8_t LPS25HB_read_byte(uint8_t reg_addr)
{
	uint8_t data = 0;
	return *(i2c_master_read(&data, 1, reg_addr, lps25hb_address, 0));
}

// LPS25HB_write_byte implementation
void LPS25HB_write_byte(uint8_t data, uint8_t register_addr, uint8_t slave_addr)
{
	i2c_master_write(data, register_addr, slave_addr, 0);
}

// LPS25HB_read_array implementation
void LPS25HB_read_array(uint8_t *data, uint8_t reg, uint8_t length)
{
	i2c_master_read(data, length, reg, lps25hb_address, 1);
}

// LPS25HB_get_pressure implementation
float LPS25HB_get_pressure()
{
	uint8_t pressure[3] = { 0 };
	LPS25HB_read_array(pressure, LPS25HB_PRESSURE_OUT_XL, 3);

	float pressure_real = ((pressure[2] * 65536) + (pressure[1] * 256) + pressure[0]) / 4096.0;

	return pressure_real;
}
float LPS25HB_get_height()
{

	float pressure = LPS25HB_get_pressure();
	float temperature_K = HTS221_get_temperature()+273.15;
	float humidity = HTS221_get_humidity();
	float tlakovy_gradient = 0.125*(1+(0.0065*(temperature_K-288.15))*(1+(0.0029*(humidity/100))));

	float relativna_vyska = (PRESSURE_0-pressure) / tlakovy_gradient;

	return relativna_vyska;
}

uint8_t LPS25HB_Init()
{
	uint8_t status = 1;

	//LPS25hb_ACC_ON;
	LL_mDelay(100);

	uint8_t val = LPS25HB_read_byte(LPS25HB_WHO_AM_I_ADDRESS);

	if (val == LPS25HB_WHO_AM_I_VALUE)
	{
		status = 1;
	}
	else			//if the device is not found on one address, try another one
	{
		lps25hb_address = LPS25HB_DEVICE_ADDRESS1;
		val = LPS25HB_read_byte(LPS25HB_WHO_AM_I_ADDRESS);
		if (val == LPS25HB_WHO_AM_I_VALUE)
		{
			status = 1;
		}
		else
		{
			status = 0;
			//return status;
		}
	}

	// Set power-down mode to turn ON -> set PD to 1 to power on
	uint8_t reg_setup = LPS25HB_read_byte(LPS25HB_CONTROL_REG1);
	reg_setup |= (1 << 7);
	LPS25HB_write_byte(reg_setup, LPS25HB_CONTROL_REG1, lps25hb_address);
	// Set up continuous update
	reg_setup = LPS25HB_read_byte(LPS25HB_CONTROL_REG1);
	reg_setup &= ~(1 << 2);
	LPS25HB_write_byte(reg_setup, LPS25HB_CONTROL_REG1, lps25hb_address);
	// Set Output data rate register to 25 Hz -> 0b100
	reg_setup = LPS25HB_read_byte(LPS25HB_CONTROL_REG1);
	reg_setup &= ~(0x07 << 4);
	reg_setup |= (0x04 << 4);
	LPS25HB_write_byte(reg_setup, LPS25HB_CONTROL_REG1, lps25hb_address);

	reg_setup = LPS25HB_read_byte(LPS25HB_CONTROL_REG1);

	return status;
}

