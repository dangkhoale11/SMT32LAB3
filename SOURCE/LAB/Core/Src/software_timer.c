/*
 * software_timer.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include "software_timer.h"

int counter = 0;
int counter_flag = 0;

void setTimer(int duration){
	counter = duration;
	counter_flag = 0;
}

void timerRun(){
	if(counter > 0){
		counter--;
		if(counter <= 0){
			counter_flag = 1;
		}
	}
}
