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
    #define F_CPU       20e6L
    #define GLOBAL_ERROR_ADDRESS    (uint8_t *) 0x45

    #define SCL_CLOCK_FREQ          400000L     // 400KHz 
    #define BUS_FREE_TIME           1.3         // ms   

    #define LIDAR_WRITE_ADDRESS     0x52
    #define LIDAR_READ_ADDRESS      0x53

    #define STEPS_PER_ROLL_5V_MOTOR      64
    #define STEPS_PER_ROLL_12V_MOTOR     200


    #define WIDTH                150
    #define LENGTH               150


    typedef enum{
        SUCESS = 0,         \
        ERROR_MEASURING = 1, \
        ERROR_ALLOCATING_MEMORY = 2, \
        MEASURE_OUT_OF_RANGE_ERROR = 3, \
        ERROR_READING_DISTANCE_FROM_LIDAR = 4
    } return_code;

    typedef struct {
        unsigned short A_plus;
        unsigned short B_plus;
        unsigned short A_minus;
        unsigned short B_minus;
        struct step_sequence *next;
        struct step_sequence *prev;
    } step_sequence;

#endif	/* TYPES_H */