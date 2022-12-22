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
		if(buffer[index_buffer-1] == '!'){
			status = start;
		}
		break;
	case start: // !
		if(buffer[index_buffer-1] == '!'){
			status = start;
		}
		if(buffer[index_buffer-1] == 'R'){
			status = fsm_R;
		}
		if(buffer[index_buffer-1] == 'O'){
			status = fsm_O;
		}
		if(buffer[index_buffer-1] != 'O' && buffer[index_buffer-1] != 'R'){
			status = INIT;
		}
		break;
	case fsm_R: //!R
		if(buffer[index_buffer-1] == 'S'){
			status = fsm_S;
		}
		if(buffer[index_buffer-1] == 'R'){
			status = INIT;
		}
		break;
	case fsm_S:// !RS
		if(buffer[index_buffer-1] == 'T'){
			status = fsm_T;
		}
		if(buffer[index_buffer-1] == 'S'){
			status = INIT;
		}
		break;
	case fsm_T:// !RST
		if(buffer[index_buffer-1] == '#'){
			status = finish1;
		}
		if(buffer[index_buffer-1] == 'T'){
			status = INIT;
		}
		break;
	case fsm_O://!O
		if(buffer[index_buffer-1] == 'K'){
			status = fsm_T;
		}
		if(buffer[index_buffer-1] == 'O'){
			status = INIT;
		}
		break;
	case fsm_K://!OK
		if(buffer[index_buffer-1] == '#'){
			status = finish2;
		}
		if(buffer[index_buffer-1] == 'K'){
			status = INIT;
		}
		break;
	case finish1:// !RST#
		command_flag = 1;
		status = INIT;
		break;
	case finish2://!OK#
		command_flag = 1;
		status = INIT;
	default:
		break;
	}
}
