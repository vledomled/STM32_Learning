/*
 * max7219.h
 *
 *  Created on: Feb 22, 2025
 *      Author: Vlad
 */

#include "stm32f4xx_hal.h"

#ifndef INC_MAX7219_H_
#define INC_MAX7219_H_

#define NO_OP 0x00
#define DIGIT_0 0x01
#define DIGIT_1 0x02
#define DIGIT_2 0x03
#define DIGIT_3 0x04
#define DIGIT_4 0x05
#define DIGIT_5 0x06
#define DIGIT_6 0x07
#define DIGIT_7 0x08
#define DECODE_MODE 0x09
#define INTENSITY 0x0A
#define SCAN_LIMIT 0x0B
#define SHUTDOWN 0x0C
#define DISP_TEST 0x0F

void MAX7219_Init(void);  //Initialize max7219
void MAX7219_Write(uint8_t addr, uint8_t data); //write to register using HAL
void MAX7219_Shutdown(void); //Shutdown mode




#endif /* INC_MAX7219_H_ */
