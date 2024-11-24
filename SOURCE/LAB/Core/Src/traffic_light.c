/*
 * traffic_light.c
 *
 *  Created on: Oct 23, 2024
 *      Author: ADMIN
 */

#include "traffic_light.h"
void traffic_run(){
	switch (status_traffic){
		case INIT_traffic:
			status_traffic = ODD;
			setTimer_traffic();
			setTimer(0, 100);
			status[ODD] = INIT;
			break;
		case ODD:
			fsm_automatic_run();
			if(timer_flag[0] == 1){
				timerTraffic--;
				setTimer(0,100);
			}
			if(timerTraffic == 0){
				status_traffic = INIT_traffic;
			}
			break;
		default:
			break;
	}
}
