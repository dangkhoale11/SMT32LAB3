/*
 * global.h
 *
 *  Created on: Oct 22, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
//#include "display_7seg.h"
#include "main.h"
#include "software_timer.h"
#include "button.h"

extern int status[5];

extern int status_traffic;

extern int timerRed;
extern int timerGreen;
extern int timerYellow;
extern int timerTraffic;
extern int countRed;
extern int countGreen;
extern int countYellow;

extern int tmp;

extern int countRed2;
extern int countGreen2;
extern int countYellow2;

#define INIT		0
#define AUTO_RED 	4
#define AUTO_GREEN  5
#define AUTO_YELLOW 3

#define MODE_1 		0
#define MODE_2 		12
#define MODE_3 		13
#define MODE_4		14

#define ODD 		1
#define EVEN		2
#define INIT_traffic  100

void reset_light();

void red_blinky();
void green_blinky();
void yellow_blinky();

void setTimer_traffic();

void onRed1();
void onRed2();
void onGreen1();
void onGreen2();
void onYellow1();
void onYellow2();

#endif /* INC_GLOBAL_H_ */
