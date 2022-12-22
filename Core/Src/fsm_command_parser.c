/*
 * fsm_command_parser.c
 *
 *  Created on: Dec 14, 2022
 *      Author: Acer
 */
#include "fsm_command_parser.h"
#include "stdio.h"
#include "string.h"

void command_parser_fsm(){
	switch(status){
	case INIT:
		if(buffer[index_buffer-1] == '!'){//!
			status = start;
		}
		break;
	case start:
		// if there are many symbolic !( !!!!!), it equal a single !
		if(buffer[index_buffer-1] == '!'){
			status = start;
		}
		//it receives a character R
		if(buffer[index_buffer-1] == 'R'){
			status = fsm_R;
		}
		//it receives a character O
		if(buffer[index_buffer-1] == 'O'){
			status = fsm_O;
		}
		//it doesn't receives both character O and R
		if(buffer[index_buffer-1] != 'O' && buffer[index_buffer-1] != 'R'){
			status = INIT;
		}
		break;
	case fsm_R: //!R
		//it receives a character S
		if(buffer[index_buffer-1] == 'S'){
			status = fsm_S;
		}
		//it receives a character R again
		if(buffer[index_buffer-1] == 'R'){
			status = INIT;
		}
		break;
	case fsm_S:// !RS
		//it receives a character T
		if(buffer[index_buffer-1] == 'T'){
			status = fsm_T;
		}
		//it receives a character S again
		if(buffer[index_buffer-1] == 'S'){
			status = INIT;
		}
		break;
	case fsm_T:// !RST
		//it receives a character #
		if(buffer[index_buffer-1] == '#'){
			status = finish1;
		}
		//it receives a character T again
		if(buffer[index_buffer-1] == 'T'){
			status = INIT;
		}
		break;
	case fsm_O://!O
		//it receives a character K
		if(buffer[index_buffer-1] == 'K'){
			status = fsm_T;
		}
		//it receives a character O again
		if(buffer[index_buffer-1] == 'O'){
			status = INIT;
		}
		break;
	case fsm_K://!OK
		//it receives a character #
		if(buffer[index_buffer-1] == '#'){
			status = finish2;
		}
		//it receives a character K again
		if(buffer[index_buffer-1] == 'K'){
			status = INIT;
		}
		break;
	case finish1:// !RST#
		// set command flag = 1 and return status = INIT
		command_flag = 1;
		status = INIT;
		break;
	case finish2://!OK#
		// set command flag = 1 and return status = INIT
		command_flag = 1;
		status = INIT;
	default:
		break;
	}
}
