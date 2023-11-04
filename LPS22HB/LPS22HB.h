/*
 * LPS22HB.H
 *
 *  Created on: Oct 30, 2023
 *      Author: romyk
 */

#define 	HTS221_DEVICE_ADDRESS					0xBB

#define 	HTS221_WHO_AM_I_ADDRES					0x0F
#define 	HTS221_WHO_AM_I_VALUE					0XB1

#define 	HTS221_CTRL_REG1						0x10
#define		HTS221_CTRL_REG2						0X11
#define  	HTS221_CTRL_REG3						0X12

#define 	LPS22HB_PRESS_OUT_XL					0x28
#define 	LPS22HB_PRESS_OUT_L						0x29
#define 	LPS22HB_PRESS_OUT_H						0x2A

#define 	LPS22HB_REF_P_XL						0x15
#define 	LPS22HB_REF_P_L							0x16
#define 	LPS22HB_REF_P_H							0x17


uint8_t lps22hb_init(void);
void lps22hb_write_byte(uint8_t reg_addr, uint8_t value);
uint8_t lps22hb_read_byte(uint8_t reg_addr);
void lps22hb_read_array(uint8_t * data, uint8_t reg, uint8_t byteCount);

float lps22hb_get_pressure();
