/*
 * hts221.h
 *
 *  Created on: Oct 29, 2023
 *      Author: romyk
 */

#include "main.h"
#include "i2c.h"


#define 	HTS221_DEVICE_ADDRESS_0				    0xBF //I2C operation Read

#define 	HTS221_WHO_AM_I_VALUE 					0xBC
#define 	HTS221_WHO_AM_I_ADDRES					0x0F

#define 	HTS221_ADDRESS_CTRL1					0x20 //pre zapinanie

#define 	HTS221_HUMIDITY_OUT_L 					0x28
#define 	HTS221_TEMP_OUT_L 						0x2A

uint8_t hts221_init(void);
uint8_t hts221_read_byte(uint8_t reg_addr);
void hts221_write_byte(uint8_t reg_addr, uint8_t value);


