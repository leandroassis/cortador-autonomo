/* 
 * File:   main.c
 * Author: l30 4ss1s
 *
 * Created on May 27, 2022, 5:27 PM
 */

#include <xc.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "i2c.h"
#include "defines.h"
#include "steps.h"

int main(){
    return_code global_error_code; 
    unsigned short **map;
    step_sequence *steps_5v_motor, *steps_12v_motor1, *steps_12v_motor2;
    
    TWSR = 0x00;
    TWBR = (F_CPU/SCL_CLOCK_FREQ - 16)/2;
    TWEN = 1;
    
    DDRB = 0x07;
    DDRC = 0x0E;
    DDRD = 0xFF;
    
    PORTB = 0x00;
    PORTC = 0x04;
    PORTD = 0x00 | 0x7C;
    
    get_global_error(&global_error_code);
    
    set_global_error(&global_error_code, init_step_sequences(steps_5v_motor, steps_12v_motor1, steps_12v_motor2));
    map_terrain_2mts_range(map, steps_5v_motor);   
    
    return 0;
}