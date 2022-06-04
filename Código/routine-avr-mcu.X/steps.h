/* 
 * File:   steps.h
 * Author: assis
 *
 * Created on May 29, 2022, 7:20 PM
 */

#ifndef STEPS_H
#define	STEPS_H

#define STEPS_PER_ROLL_5V_MOTOR      64
#define STEPS_PER_ROLL_12V_MOTOR     200


#define WIDTH                150
#define LENGTH               150

#endif	/* STEPS_H */

typedef struct{
    unsigned short A_plus = NULL;
    unsigned short B_plus = NULL;
    unsigned short A_minus = NULL;
    unsigned short B_minus = NULL;
    step_sequence* next = NULL;
    step_sequence* prev = NULL;
} step_sequence;

return_code init_step_sequences(step_sequence *steps_5v_motor, step_sequence *steps_12v_motor1, step_sequence *steps_12v_motor2);
return_code map_terrain_2mts_range(unsigned short **mapped_matrix, step_sequence *steps_5v_motor);
return_code measure_distance_around(unsigned short **mapped_matrix, step_sequence *steps_5v_motor);
