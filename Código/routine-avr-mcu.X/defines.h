/* 
 * File:   types.h
 * Author: assis
 *
 * Created on May 30, 2022, 10:58 PM
 */

 /*
  * 
  * alocação da eeprom
  *  
  * 0 ate 766 -> 
  * 768 ate 1023 -> Hash de integridade, erro global, 
  */

#ifndef TYPES_H
#define	TYPES_H
#endif	/* TYPES_H */

#define F_CPU       20e6L

typedef enum{
    SUCESS = 0,         \
    ERROR_MEASURING = 1, \
    ERROR_ALLOCATING_MEMORY = 2, \
    MEASURE_OUT_OF_RANGE_ERROR = 3, \
    ERROR_READING_DISTANCE_FROM_LIDAR = 4
} return_code;
