/*
 * software_timer.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include "software_timer.h"

int counter[5];
int timer_flag[5];

void setTimer(int i, int duration){
	counter[i] = duration;
	timer_flag[i] = 0;
}

void timer_run(int i){
	if(counter[i] > 0){
		counter[i]--;
		if(counter[i] <= 0){
			timer_flag[i] = 1;
		}
	}
}

void timerRun(){
	timer_run(0);
	timer_run(1);
	timer_run(2);
	timer_run(3);
	timer_run(4);
}
