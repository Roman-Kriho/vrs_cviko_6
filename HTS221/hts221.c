/*
 * hts221.c
 *
 *  Created on: Oct 30, 2023
 *      Author: romyk
 */

#include "hts221.h"

uint8_t addres = HTS221_DEVICE_ADDRESS;

uint8_t hts221_read_byte(uint8_t reg_addr){

	i2c_master_read(addres, reg_addr, value, 0);

}
void hts221_write_byte(uint8_t reg_addr, uint8_t value){

	i2c_master_write(addres, reg_addr, value, 0);
}
uint8_t hts221_init(void){

}

float hts221_get_temperature(float *value){

}
uint8_t hts221_get_humidity(void){

}






