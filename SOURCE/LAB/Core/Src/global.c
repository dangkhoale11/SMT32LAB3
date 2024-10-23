/*
 * global.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ADMIN
 */
#include "global.h"
int status[5] = {0, 0, 0, 0, 0};

int status_traffic = ODD;

int timerRed = 500;
int  timerGreen = 300;
int timerYellow = 200;


void red_light(int i){
	switch (i){
		case ODD:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, SET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, RESET);
			HAL_GPIO_WritePin(red3_GPIO_Port, red3_Pin, SET);
			HAL_GPIO_WritePin(red4_GPIO_Port, red4_Pin, RESET);
			break;
		case EVEN:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, RESET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, SET);
			HAL_GPIO_WritePin(red3_GPIO_Port, red3_Pin, RESET);
			HAL_GPIO_WritePin(red4_GPIO_Port, red4_Pin, SET);
			break;
		default:
			break;
	}
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, RESET);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, RESET);
	HAL_GPIO_WritePin(green3_GPIO_Port, green3_Pin, RESET);
	HAL_GPIO_WritePin(green4_GPIO_Port, green4_Pin, RESET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, RESET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, RESET);
	HAL_GPIO_WritePin(yellow3_GPIO_Port, yellow3_Pin, RESET);
	HAL_GPIO_WritePin(yellow4_GPIO_Port, yellow4_Pin, RESET);
}


void green_light(int i){
	switch (i){
			case ODD:
				HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, SET);
				HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, RESET);
				HAL_GPIO_WritePin(green3_GPIO_Port, green3_Pin, SET);
				HAL_GPIO_WritePin(green4_GPIO_Port, green4_Pin, RESET);
				break;
			case EVEN:
				HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, RESET);
				HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, SET);
				HAL_GPIO_WritePin(green3_GPIO_Port, green3_Pin, RESET);
				HAL_GPIO_WritePin(green4_GPIO_Port, green4_Pin, SET);
				break;
			default:
				break;
		}
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, RESET);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, RESET);
		HAL_GPIO_WritePin(red3_GPIO_Port, red3_Pin, RESET);
		HAL_GPIO_WritePin(red4_GPIO_Port, red4_Pin, RESET);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, RESET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, RESET);
		HAL_GPIO_WritePin(yellow3_GPIO_Port, yellow3_Pin, RESET);
		HAL_GPIO_WritePin(yellow4_GPIO_Port, yellow4_Pin, RESET);
}

void yellow_light(int i){
			switch (i){
				case ODD:
					HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, SET);
					HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, RESET);
					HAL_GPIO_WritePin(yellow3_GPIO_Port, yellow3_Pin, SET);
					HAL_GPIO_WritePin(yellow4_GPIO_Port, yellow4_Pin, RESET);
					break;
				case EVEN:
					HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, RESET);
					HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, SET);
					HAL_GPIO_WritePin(yellow3_GPIO_Port, yellow3_Pin, RESET);
					HAL_GPIO_WritePin(yellow4_GPIO_Port, yellow4_Pin, SET);
					break;
				default:
					break;
			}
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, RESET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, RESET);
			HAL_GPIO_WritePin(red3_GPIO_Port, red3_Pin, RESET);
			HAL_GPIO_WritePin(red4_GPIO_Port, red4_Pin, RESET);
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, RESET);
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, RESET);
			HAL_GPIO_WritePin(green3_GPIO_Port, green3_Pin, RESET);
			HAL_GPIO_WritePin(green4_GPIO_Port, green4_Pin, RESET);
}
