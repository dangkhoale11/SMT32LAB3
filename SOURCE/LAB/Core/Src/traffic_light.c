/*
 * traffic_light.c
 *
 *  Created on: Oct 23, 2024
 *      Author: ADMIN
 */

#include "traffic_light.h"

void display_seg(int i){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		//HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);

		display7SEG(i);

}


void display_seg2(int i){
	//HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
	display7SEG_2(i);
}

void traffic_run(){
	switch (status_traffic){
		case INIT_traffic:
			status_traffic = ODD;
			setTimer_traffic();
			setTimer(0, 100);
			status[ODD] = INIT;
			status[EVEN] = INIT;
			break;
		case ODD:
			if(timerTraffic > timerGreen/100 + timerYellow/100) display_seg(timerTraffic - timerGreen/100 - timerYellow/100);
			else if(timerTraffic > timerYellow/100) display_seg(timerTraffic - timerYellow/100);
			else if (timerTraffic > 0) display_seg(timerTraffic);

			if(countGreen > 0) display_seg2(countGreen);
			if(countRed > 0) display_seg2(countRed);
			if(countYellow > 0) display_seg2(countYellow);

			fsm_automatic_run();
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
			//display_seg(EVEN);
			if(timerTraffic > timerGreen/100 + timerYellow/100) display_seg(timerTraffic - timerGreen/100 - timerYellow/100);
			else if(timerTraffic > timerYellow/100) display_seg(timerTraffic - timerYellow/100);
			else if (timerTraffic > 0) display_seg(timerTraffic);

			if(countGreen2 > 0) display_seg2(countGreen2);
			if(countRed2 > 0) display_seg2(countRed2);
			if(countYellow2 > 0) display_seg2(countYellow2);

			fsm_automatic_run2();
			if(timer_flag[0] == 1){
				timerTraffic--;
				setTimer(0,100);
			}
			if(timerTraffic == 0){
				status_traffic = INIT_traffic;
				//setTimer(0,100);
				//setTimer_traffic();
			}
			break;
		default:
			break;
	}
}
