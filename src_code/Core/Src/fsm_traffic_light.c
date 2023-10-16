/*
 * fsm_traffic_light.c
 *
 *  Created on: Oct 15, 2023
 *      Author: dinhq
 */

#include "fsm_traffic_light.h"


void fsm_traffic_light(){
	switch(led_status){
	case INIT:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);

		led_status = RED_GREEN;
		last_status = led_status;
		setTimer1(300);
		setTimer2(100);
		break;
	case RED_GREEN:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = 2;
		}

		if (timer1_flag == 1){
			setTimer1(200);
			led_status = RED_YELLOW;
			last_status = led_status;
		}

		if (isButtonPressed(0) == 1){
			led_status = RED_MAN;
			setTimer5(1);
		}
		break;
	case RED_YELLOW:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			if (timerRoad1 <= 0) timerRoad1 = 3;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = 5;
		}

		if(timer1_flag == 1){
			setTimer1(300);
			led_status = GREEN_RED;
			last_status = led_status;
		}

		if (isButtonPressed(0) == 1){
			led_status = RED_MAN;
			setTimer5(1);
		}
		break;
	case GREEN_RED:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			if (timerRoad1 <= 0) timerRoad1 = 2;
			timerRoad2--;
		}

		if(timer1_flag == 1){
			setTimer1(200);
			led_status = YELLOW_RED;
			last_status = led_status;
		}

		if (isButtonPressed(0) == 1){
			led_status = RED_MAN;
			setTimer5(1);
		}
		break;
	case YELLOW_RED:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			if (timerRoad1 <= 0) timerRoad1 = 5;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = 3;
		}

		if (timer1_flag == 1){
			setTimer1(300);
			led_status = RED_GREEN;
		}

		if (isButtonPressed(0) == 1){
			led_status = RED_MAN;
			setTimer5(1);
		}
		break;
	default:
		break;
	}
}
