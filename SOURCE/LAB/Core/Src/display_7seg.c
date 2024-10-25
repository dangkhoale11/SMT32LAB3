/*
 * display_7seg.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ADMIN
 */

#include "display_7seg.h"

 GPIO_TypeDef *SEG_PORTS[14] = {
		SEG0_GPIO_Port, SEG1_GPIO_Port, SEG2_GPIO_Port, SEG3_GPIO_Port, SEG4_GPIO_Port, SEG5_GPIO_Port,
		SEG6_GPIO_Port, SEG7_GPIO_Port, SEG8_GPIO_Port, SEG9_GPIO_Port, SEG10_GPIO_Port, SEG11_GPIO_Port, SEG12_GPIO_Port,
		SEG13_GPIO_Port
};

 uint16_t SEG_PINS[14] = {
		SEG0_Pin, SEG1_Pin, SEG2_Pin, SEG3_Pin, SEG4_Pin, SEG5_Pin, SEG6_Pin,
		SEG7_Pin, SEG8_Pin, SEG9_Pin, SEG10_Pin, SEG11_Pin, SEG12_Pin, SEG13_Pin
};
GPIO_PinState LEDS_state[10][7] = { { 0, 0, 0, 0, 0, 0, 1 }, { 1, 0, 0, 1,
  			1, 1, 1 }, { 0, 0, 1, 0, 0, 1, 0 }, { 0, 0, 0, 0, 1, 1, 0 }, { 1, 0,
  			0, 1, 1, 0, 0 }, { 0, 1, 0, 0, 1, 0, 0 }, { 0, 1, 0, 0, 0, 0, 0 }, {
  			0, 0, 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0,
  			0 } };

void set_LEDS(GPIO_PinState *L_LEDS_state){
	for (int i = 0; i < 7; i++) {
	  	HAL_GPIO_WritePin(SEG_PORTS[i], SEG_PINS[i], L_LEDS_state[i]);
	}
}
void display7SEG(int number) {
  		switch (number) {
  		case 0:
  			set_LEDS(LEDS_state[0]);
  			break;
  		case 1:
  			set_LEDS(LEDS_state[1]);
  			break;
  		case 2:
  			set_LEDS(LEDS_state[2]);
  			break;
  		case 3:
  			set_LEDS(LEDS_state[3]);
  			break;
  		case 4:
  			set_LEDS(LEDS_state[4]);
  			break;
  		case 5:
  			set_LEDS(LEDS_state[5]);
  			break;
  		case 6:
  			set_LEDS(LEDS_state[6]);
  			break;
  		case 7:
  			set_LEDS(LEDS_state[7]);
  			break;
  		case 8:
  			set_LEDS(LEDS_state[8]);
  			break;
  		case 9:
  			set_LEDS(LEDS_state[9]);
  			break;
  		default:
  			break;
  		}
 }

void set_LEDS_2(GPIO_PinState *L_LEDS_state){
	for (int i = 7; i < 14; i++) {
	  	HAL_GPIO_WritePin(SEG_PORTS[i], SEG_PINS[i], L_LEDS_state[i - 7]);
	}
}

void display7SEG_2(int number) {
  		switch (number) {
  		case 0:
  			set_LEDS_2(LEDS_state[0]);
  			break;
  		case 1:
  			set_LEDS_2(LEDS_state[1]);
  			break;
  		case 2:
  			set_LEDS_2(LEDS_state[2]);
  			break;
  		case 3:
  			set_LEDS_2(LEDS_state[3]);
  			break;
  		case 4:
  			set_LEDS_2(LEDS_state[4]);
  			break;
  		case 5:
  			set_LEDS_2(LEDS_state[5]);
  			break;
  		case 6:
  			set_LEDS_2(LEDS_state[6]);
  			break;
  		case 7:
  			set_LEDS_2(LEDS_state[7]);
  			break;
  		case 8:
  			set_LEDS_2(LEDS_state[8]);
  			break;
  		case 9:
  			set_LEDS_2(LEDS_state[9]);
  			break;
  		default:
  			break;
  		}
 }
