/*
 * fsm_uart_communication.c
 *
 *  Created on: Dec 14, 2022
 *      Author: Acer
 */

#include "fsm_uart_communication.h"
#include "global.h"
#include "stdio.h"
#include "string.h"
#include "timer.h"
#include "stdlib.h"

uint32_t ADC_value = 0;
void uart_communication_fsm(){
	switch(status1){
	case RECEIVE_COM:
		if(command_flag == 1){
			//get ADC_value
			ADC_value = HAL_ADC_GetValue(&hadc1);
			command_flag = 0;
			//move to status1 = Transmit_Com
			status1 = Transmit_COM;
		}
		break;
	case Transmit_COM:
			//send data to console
			HAL_UART_Transmit(&huart2 , ( void *) str , sprintf(str, "!ADC=%d#\r\n", ADC_value), 1000);
			setTimer1(3000);
			status1 = WAIT_FOR_OK;
		break;
	case WAIT_FOR_OK:
		if(timer1_flag == 1){
			//time out 3s
			status1 =  Transmit_COM;
		}
		if(command_flag == 1){
			// set command_flag = 0
			command_flag = 0;
			status1 = RECEIVE_COM;
		}
		break;
	default:
		break;
	}
}
