/*
 * software_timer.h
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#include "main.h"

extern int timer_flag[5];
void setTimer(int i, int duration);

void timer_run(int i);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
