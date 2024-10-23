/*
 * traffic_light.c
 *
 *  Created on: Oct 23, 2024
 *      Author: ADMIN
 */

#include "traffic_light.h"

void traffic_run(){
	switch (status_traffic){
		case ODD:
			fsm_automatic_run(1);
			fsm_automatic_run(3);
			status_traffic = EVEN;
			break;
		case EVEN:
			fsm_automatic_run(2);
			fsm_automatic_run(4);
			status_traffic = ODD;
			break;
		default:
			break;
	}
}
