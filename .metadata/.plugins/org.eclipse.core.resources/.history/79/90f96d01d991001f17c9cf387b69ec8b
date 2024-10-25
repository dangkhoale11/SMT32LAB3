/*
 * fsm_automatic.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ADMIN
 */

#include "fsm_automatic.h"

void fsm_automatic_run(int i){
	switch (status[i]){
	case INIT:
		status[i] = AUTO_RED;
		setTimer(i, timerRed);
		break;
	case AUTO_RED:
		red_light(i);
		if(timer_flag[i] == 1){
			status[i] = AUTO_GREEN;
			setTimer(i, timerGreen);
		}
		break;
	case AUTO_GREEN:
		green_light(i);
		if(timer_flag[i] == 1){
			status[i] = AUTO_YELLOW;
			setTimer(i, timerYellow);
		}
		break;
	case AUTO_YELLOW:
		yellow_light(i);
		if(timer_flag[i] == 1){
			status[i] = INIT;
		}
		break;
	default:
		break;
	}

}
