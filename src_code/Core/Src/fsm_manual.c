/*
 * fsm_manual.c
 *
 *  Created on: Oct 15, 2023
 *      Author: dinhq
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(led_status){
	case RED_MAN:
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		if (timer5_flag == 1){
			setTimer5(25);
			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
		}
		if (isButtonPressed(1) == 1){
			r_val++;
			if (r_val >= 100) r_val=2;
		}
		if (isButtonPressed(0) == 1){
			setTimer5(1);
			led_status = YELLOW_MAN;
		}
		break;

	case YELLOW_MAN:
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		if (timer5_flag == 1){
			setTimer5(25);
			HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
		}
		if (isButtonPressed(1) == 1){
			y_val++;
			if (y_val >= 100) y_val=1;
		}
		if (isButtonPressed(0) == 1){
			setTimer5(1);
			led_status = GREEN_MAN;
		}
		break;

	case GREEN_MAN:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		if (timer5_flag == 1){
			setTimer5(25);
			HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
		}
		if (isButtonPressed(1) == 1){
			g_val++;
			if (g_val >= 100) g_val=1;
		}
		if (isButtonPressed(0) == 1){
			led_status = RED_GREEN;
			setTimer1(300);
			setTimer2(100);
			setTimer4(1);
			index_led=0;
			clearSignal();
			timerRoad1 = 5;
			timerRoad2 = 3;
		}
		break;

	default:
		break;
	}
	if (isButtonPressed(2) == 1){
		timerRoad1 = r_val;
	}
}
