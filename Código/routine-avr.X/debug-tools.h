/* 
 * File:   debug-tools.h
 * Author: assis
 *
 * Created on May 29, 2022, 7:38 PM
 */

#include "defines.h"

#ifndef MAIN_H
#define	MAIN_H

#endif	/* MAIN_H */

void get_global_error(return_code *global_error);
void set_global_error(return_code *global_error, return_code function_callback);
void handle_global_error(return_code *global_error);