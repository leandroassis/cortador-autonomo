/* 
 * File:   mapping-routine.c
 * Author: l30 4ss1s
 *
 * Created on May 28, 2022, 7:19 PM
 */

#include <xc.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "steps.h"
#include "i2c.h"

return_code map_terrain_2mts_range(unsigned short **mapped_matrix, step_sequence *steps_5v_motor){
        
    if(measure_distance_around(mapped_matrix, steps_5v_motor)) return ERROR_MEASURING;
   
    // find_better_way(mapped_matrix);
    
    return SUCESS;
}

return_code measure_distance_around(unsigned short **mapped_matrix, step_sequence *steps_5v_motor){
    unsigned short x_pos, y_pos, center = (int) WIDTH/2;
    float distance_measured, degrees_radian = 0;
    unsigned short hipotenuse_converted;
    step_sequence *temp;
    
    temp = steps_5v_motor;
    for(int step = 0; step < 64; step++){
        
        PORTD = (temp->A_plus << PD0) | (temp->B_plus << PD1);
        PORTC = (temp->A_minus << PC1)| (temp->B_minus << PC2);
        
        if(get_distance_from_lidar(&distance_measured)) return ERROR_READING_DISTANCE_FROM_LIDAR;
        if(distance_measured < 1.5){
            hipotenuse_converted = distance_measured*50;
            x_pos = hipotenuse_converted*((int) cos(degrees_radian)) + center;

            if(degrees_radian > 0 && degrees_radian < M_PI){
                y_pos = center - hipotenuse_converted*((int) sin(degrees_radian));
            }
            else{
                y_pos = center + hipotenuse_converted*abs((int) sin(degrees_radian));
            }

            if(y_pos >= WIDTH - 1 || x_pos > LENGTH - 1) return MEASURE_OUT_OF_RANGE_ERROR;
            mapped_matrix[y_pos][x_pos] = 1;

            degrees_radian += (float) M_PI/32;
        }
        temp = temp->next;
    }
    
    return SUCESS;
}