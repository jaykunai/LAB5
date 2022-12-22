/*
 * global.h
 *
 *  Created on: Dec 14, 2022
 *      Author: Acer
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#define MAX_BUFFER_SIZE 30

#define INIT 1
#define start 2
#define fsm_R 3
#define fsm_S 4
#define fsm_T 5
#define fsm_O 6
#define fsm_K 7
#define finish1 8
#define finish2 9

#define INIT1 11
#define RECEIVE_COM	12
#define Transmit_COM	13
#define WAIT_FOR_OK	14

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t temp;
extern uint8_t command_flag;
extern uint8_t command_data[10];
extern uint8_t str[12];

extern int status;
extern int status1;
#endif /* INC_GLOBAL_H_ */
