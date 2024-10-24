/*
 * traffic_light.c
 *
 *  Created on: Oct 23, 2024
 *      Author: ADMIN
 */

#include "traffic_light.h"

void display_seg(int i){
	if(i == ODD){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	}
	else if(i == EVEN){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	}
	if(timerTraffic > timerGreen/100 + timerYellow/100) display7SEG(timerTraffic - timerGreen/100 - timerYellow/100);
	else if(timerTraffic > timerYellow/100) display7SEG(timerTraffic - timerYellow/100);
	else if (timerTraffic > 0) display7SEG(timerTraffic);
}


void traffic_run(){
	switch (status_traffic){
		case INIT_traffic:
			status_traffic = ODD;
			setTimer_traffic();
			setTimer(0, 100);
			break;
		case ODD:
			display_seg(ODD);
			fsm_automatic_run(ODD);
			if(timer_flag[0] == 1){
				timerTraffic--;
				setTimer(0,100);
			}
			if(timerTraffic == 0){
				status_traffic = EVEN;
				setTimer(0,100);
				setTimer_traffic();
			}
			break;
		case EVEN:
			display_seg(EVEN);
			fsm_automatic_run(EVEN);
			if(timer_flag[0] == 1){
				timerTraffic--;
				setTimer(0,100);
			}
			if(timerTraffic == 0){
				status_traffic = INIT_traffic;
				setTimer_traffic();
			}
			break;
		default:
			break;
	}
}
