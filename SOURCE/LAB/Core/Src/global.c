/*
 * global.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ADMIN
 */
#include "global.h"
int status[5] = {0, 0, 0, 0, 0};

int status_traffic = INIT_traffic;

int timerRed = 600;
int  timerGreen = 300;
int timerYellow = 200;

int timerTraffic = 0;

void setTimer_traffic(){
	timerTraffic = timerRed/100 + timerGreen/100 + timerYellow/100;
}

void red_light(int i){
	switch (i){
	case ODD:
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, SET);
		//HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, RESET);
		break;
	case EVEN:
		//HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, RESET);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, SET);
		break;
	default:
		break;
	}

	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, RESET);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, RESET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, RESET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, RESET);
}


void green_light(int i){
	switch (i){
	case ODD:
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, SET);
		//HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, RESET);
		break;
	case EVEN:
		//HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, RESET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, SET);
		break;
	default:
		break;
	}
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, RESET);
	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, RESET);

	HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, RESET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, RESET);
}

void yellow_light(int i){
	switch (i){
	case ODD:
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, SET);
		//HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, RESET);
		break;
	case EVEN:
		//HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, RESET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, SET);
		break;
	default:
		break;
	}
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, RESET);
	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, RESET);
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, RESET);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, RESET);

}
