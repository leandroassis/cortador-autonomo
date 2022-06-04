#include <xc.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include "debug-tools.h"
#include "defines.h"

void set_global_error(return_code *global_error_pointer, return_code function_callback){
    *global_error_pointer = function_callback;
    eeprom_write_byte(*global_error_poiter);
    handle_global_error(global_error_pointer);
    return;
}
/*
SUCESS = 0,         \
    ERROR_MEASURING = 1, \ -> Verifica se é erro de cálculo ou conexão com o lidar
    ERROR_ALLOCATING_MEMORY = 2, \
    MEASURE_OUT_OF_RANGE_ERROR = 3, \     -> Reinicia o sensor
    ERROR_READING_DISTANCE_FROM_LIDAR = 4 -> Reset o sistema
 */

void handle_global_error(return_code *global_error_pointer){
    switch(*global_error_pointer){
        case ERROR_MEASURING:
            reset_TWI_peripherals();
            break;
        case ERROR_ALLOCATING_MEMORY:
            halt_process_routine();
            break;
        default:
            *global_error_pointer = NULL;
            break;
    }
    return;
}