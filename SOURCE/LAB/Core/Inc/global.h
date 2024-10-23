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


#define INIT		0
#define AUTO_RED 	4
#define AUTO_GREEN  5
#define AUTO_YELLOW 3

#define MODE_1 		11
#define MODE_2 		12
#define MODE_3 		13

#define ODD 		1
#define EVEN		2

void red_light(int i);
void green_light(int i);
void yellow_light(int i);

#endif /* INC_GLOBAL_H_ */
