/* 
 * File:   steps.h
 * Author: assis
 *
 * Created on May 29, 2022, 7:20 PM
 */
#include "defines.h"

#ifndef STEPS_H
#define STEPS_H
    return_code init_step_sequences(step_sequence *steps_5v_motor, step_sequence *steps_12v_motor1, step_sequence *steps_12v_motor2);
    return_code map_terrain_2mts_range(unsigned short **mapped_matrix, step_sequence *steps_5v_motor);
    return_code measure_distance_around(unsigned short **mapped_matrix, step_sequence *steps_5v_motor);
#endif