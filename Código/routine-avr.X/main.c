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

#include "defines.h"
#include "debug-tools.h"
#include "i2c.h"
#include "steps.h"

int main(){
    return_code global_error_code; 
    unsigned short **map = NULL;
    step_sequence *steps_5v_motor = NULL, *steps_12v_motor1 = NULL, *steps_12v_motor2 = NULL;
    
    TWSR = 0x00;
    TWBR = (F_CPU - SCL_CLOCK_FREQ*16)/2*SCL_CLOCK_FREQ;

    
    
    DDRB = 0x07;
    DDRC = 0x0E;
    DDRD = 0xFF;
    
    PORTB = 0x00;
    PORTC = 0x04;
    PORTD = 0x00 | 0x7C;
    
    get_global_error(&global_error_code);
    
    // Step Sequence for 5V stepper motor
    steps_5v_motor = (step_sequence *) malloc(8 * sizeof(step_sequence));
    
    // Step Sequence for 12V stepper motors
    steps_12v_motor1 = (step_sequence *) malloc(4 * sizeof(step_sequence));
    steps_12v_motor2 = (step_sequence *) malloc(4 * sizeof(step_sequence));
    
    // Map
    map = (unsigned short**) malloc(WIDTH*sizeof(unsigned short));
    if(map != NULL){
        for(int i = 0; i < WIDTH; i++) map[i] = (unsigned short*) calloc(LENGTH, sizeof(unsigned short));
    }
    else set_global_error(&global_error_code, ERROR_ALLOCATING_MEMORY);
    
    set_global_error(&global_error_code, init_step_sequences(steps_5v_motor, steps_12v_motor1, steps_12v_motor2));
    map_terrain_2mts_range(map, steps_5v_motor);   
    
    return 0;
}