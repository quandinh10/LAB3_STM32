/*
 * global.c
 *
 *  Created on: Oct 15, 2023
 *      Author: dinhq
 */

#include "global.h"

int led_status=0;
int led_buffer[4]={0,0,0,0};
int index_led = 0;
int timerRoad1 = 5;
int timerRoad2 = 3;
void updateLedBuffer(){
	led_buffer[0] = timerRoad1 / 10;
	led_buffer[1] = timerRoad1 % 10;
	led_buffer[2] = timerRoad2 / 10;
	led_buffer[3] = timerRoad2 % 10;
}