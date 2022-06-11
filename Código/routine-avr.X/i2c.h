/* 
 * File:   i2c.h
 * Author: assis
 *
 * Created on May 30, 2022, 3:16 PM
 */
#include "defines.h"

#ifndef I2C_H
#define I2C_h
    return_code get_distance_from_lidar(float *destiny_var);
    return_code read_TWI(unsigned short* data, unsigned short address);
    return_code write_TWI(unsigned short* data, unsigned short address);
#endif