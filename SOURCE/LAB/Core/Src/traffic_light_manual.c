/*
 * traffic_light_manual.c
 *
 *  Created on: Oct 25, 2024
 *      Author: ADMIN
 */

#include "traffic_light_manual.h"


void traffic_light_manual_run(){

	switch (status_traffic){
		case MODE_2:

			if(tmp == 0) tmp = timerRed;

			if(tmp == 9900) tmp = 500;
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			display7SEG(tmp/1000);
			display7SEG_2((tmp % 1000)/100);
			if(timer_flag[4] == 1){
				red_blinky();
				setTimer(4,50);
			}
			if(isButtonPressed(1) == 1){
				status_traffic = MODE_3;
				tmp = 0;
				reset_light();
				setTimer(4,50);
			}
			if(isButtonPressed(2) == 1){
				tmp += 100;
			}
			if(isButtonPressed(3) == 1){
				reset_light();
				timerRed = tmp;
				tmp = 0;
				status_traffic = INIT_traffic;
			}
			break;
		case MODE_3:

			if(tmp == 0) tmp = timerGreen;

			if(tmp == 9900) tmp = 300;
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			display7SEG(tmp/1000);
			display7SEG_2((tmp % 1000) / 100);


			if(timer_flag[4] == 1){
				green_blinky();
				setTimer(4,50);
			}
			if(isButtonPressed(1) == 1){
				reset_light();
				tmp = 0;
				status_traffic = MODE_4;

				setTimer(4,50);
			}
			if(isButtonPressed(2) == 1){
				tmp += 100;
			}
			if(isButtonPressed(3) == 1){
				reset_light();
				timerGreen = tmp;
				tmp = 0;
				status_traffic = INIT_traffic;
			}
			break;
		case MODE_4:

			if(tmp == 0) tmp = timerYellow;

			if(tmp == 9900) tmp = 200;
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			display7SEG(tmp/1000);
			display7SEG_2((tmp % 1000) / 100);

			if(timer_flag[4] == 1){
				yellow_blinky();
				setTimer(4,50);
			}
			if(isButtonPressed(1) == 1){
				status_traffic = INIT_traffic;
				tmp = 0;
				reset_light();
			}
			if(isButtonPressed(2) == 1){
				tmp += 100;
			}
			if(isButtonPressed(3) == 1){
				reset_light();
				timerYellow = tmp;
				tmp = 0;
				status_traffic = INIT_traffic;
			}
			break;
		default:
			if(isButtonPressed(1) == 1){
				status_traffic = MODE_2;
				tmp = 0;
				reset_light();
				setTimer(4,50);
			}
			break;
	}
}
