/*
 * fsm_automatic.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ADMIN
 */

#include "fsm_automatic.h"

int timerRed1 = 0;
int timerGreen1 = 0;
int timerYellow1 = 0;
int check = 0;
void fsm_automatic_run(){
	switch (status[ODD]){
	case INIT:
		countGreen = timerGreen/100;
		timerRed1 = timerRed/100;
		countYellow = timerYellow/100;
		check = 1;
		setTimer(3, 100);
		setTimer(5, 50);
		status[ODD] = AUTO_RED;
		break;
	case AUTO_RED:
		if(timerRed1 > 0){
			onRed1();
			if(countGreen> 0) onGreen2();
			else onYellow2();
		}

		if(check == 1){
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);


			display7SEG_2(timerRed1  % 10);
			if(countGreen > 0) display7SEG(countGreen % 10);
			check = 0;
		}

		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
		if(timer_flag[5] == 1){
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);

			display7SEG(timerRed1 / 10);
			if(countGreen > 0) display7SEG_2(countGreen/10);
			else  display7SEG_2(countYellow/10);

			setTimer(5, 50);
		}
		if(timer_flag[3] == 1){

			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);

			timerRed1--;
			countGreen--;

			display7SEG_2(timerRed1  % 10);
			if(countGreen > 0) display7SEG(countGreen % 10);
			else  display7SEG(countYellow % 10);

			if(countGreen <= 0) countYellow--;
			setTimer(3, 100);
		}
		if(timerRed1 == 0){
			countRed = timerRed/100;
			timerGreen1 = timerGreen/100;
			check = 1;
			status[ODD] = AUTO_GREEN;
			setTimer(5, 50);
			setTimer(3, 100);
		}
		if(isButtonPressed(1) == 1){
			reset_light();
			setTimer(4, 50);
			setTimer(6, 100);
			status[ODD] = MODE_2;
			return;
		}

		break;


	case AUTO_GREEN:

		//HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);

		onGreen1();
		onRed2();
		if(check == 1){

			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			display7SEG_2(timerGreen1 % 10);
			display7SEG(countRed % 10);
			check = 0;
		}

		if(timer_flag[5] == 1){
			setTimer(5,50);

			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);

			 display7SEG(timerGreen1/10);
			 display7SEG_2(countRed/10);
		}

		if(timer_flag[3] == 1){
			setTimer(3, 100);

			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);

			countRed--;
			timerGreen1--;

			display7SEG_2(timerGreen1 % 10);
			display7SEG(countRed % 10);


		}
		if(timerGreen1  == 0){

			setTimer(5, 50);
			setTimer(3, 100);
			check = 1;
			timerYellow1 = timerYellow/100;
			status[ODD] = AUTO_YELLOW;
		}
		if(isButtonPressed(1) == 1){
			reset_light();
			setTimer(4, 50);
			setTimer(6, 100);
			status[ODD] = MODE_2;
			return;
		}
		break;


	case AUTO_YELLOW:
		onYellow1();
		onRed2();

		if(check == 1){
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);

			display7SEG_2(timerYellow1%10);
			display7SEG(countRed%10);
			check = 0;
		}
		if(timer_flag[5] == 1){
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);

			display7SEG(timerYellow1/10);
			display7SEG_2(countRed/10);
			setTimer(5,50);
		}

		if(timer_flag[3] == 1){
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);

			countRed--;
			timerYellow1--;
			display7SEG_2(timerYellow1%10);
			display7SEG(countRed%10);
			setTimer(3, 100);
		}
		if(isButtonPressed(1) == 1){
			reset_light();
			setTimer(4, 50);
			setTimer(6, 100);
			status[ODD] = MODE_2;
			return;
		}
		if(timerYellow1 == 0){
			status[ODD] = INIT;
		}
		break;
	default:
		break;
	}
}




