
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "steps.h"

return_code init_step_sequences(step_sequence *steps_5v_motor, step_sequence *steps_12v_motor1, step_sequence *steps_12v_motor2){
    
    if(!steps_5v_motor || !steps_12v_motor1 || !steps_12v_motor2) return ERROR_ALLOCATING_MEMORY;
    
    for(int i = 0; i < 7; i++){
        steps_5v_motor[i].next = &steps_5v_motor[i+1];
        steps_5v_motor[i].prev = NULL;
    }
    steps_5v_motor[7].next = &steps_5v_motor[0]; 
    steps_5v_motor[7].prev = NULL;
    
    // Step 1
    steps_5v_motor[0].A_plus = 0;
    steps_5v_motor[0].B_plus = 0;
    steps_5v_motor[0].A_minus = 0;
    steps_5v_motor[0].B_minus = 1;
    
    // Step 2
    steps_5v_motor[1].A_plus = 0;
    steps_5v_motor[1].B_plus = 0;
    steps_5v_motor[1].A_minus = 1;
    steps_5v_motor[1].B_minus = 1;
    
    // Step 3
    steps_5v_motor[2].A_plus = 0;
    steps_5v_motor[2].B_plus = 0;
    steps_5v_motor[2].A_minus = 1;
    steps_5v_motor[2].B_minus = 0;
    
    // Step 4
    steps_5v_motor[3].A_plus = 0;
    steps_5v_motor[3].B_plus = 1;
    steps_5v_motor[3].A_minus = 1;
    steps_5v_motor[3].B_minus = 0;
    
    // Step 5
    steps_5v_motor[4].A_plus = 0;
    steps_5v_motor[4].B_plus = 1;
    steps_5v_motor[4].A_minus = 0;
    steps_5v_motor[4].B_minus = 0;
    
    // Step 6
    steps_5v_motor[5].A_plus = 1;
    steps_5v_motor[5].B_plus = 1;
    steps_5v_motor[5].A_minus = 0;
    steps_5v_motor[5].B_minus = 0;
    
    // Step 7
    steps_5v_motor[6].A_plus = 1;
    steps_5v_motor[6].B_plus = 0;
    steps_5v_motor[6].A_minus = 0;
    steps_5v_motor[6].B_minus = 0; 
    
    // Step 8
    steps_5v_motor[7].A_plus = 1;
    steps_5v_motor[7].B_plus = 0;
    steps_5v_motor[7].A_minus = 0;
    steps_5v_motor[7].B_minus = 1;
    
    return SUCESS;
}

