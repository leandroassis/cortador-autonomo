/* 
 * File:   i2c.h
 * Author: assis
 *
 * Created on May 30, 2022, 3:16 PM
 */

#define SCL_CLOCK_FREQ          400000L     // 400KHz 
#define BUS_FREE_TIME           1.3         // ms   

#define LIDAR_WRITE_ADDRESS     0x52
#define LIDAR_READ_ADDRESS      0x53


return_code get_distance_from_lidar(float *destiny_var);