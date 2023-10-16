/*
 * button.c
 *
 *  Created on: Oct 5, 2023
 *      Author: dinhq
 */

#include "button.h"
int KeyReg0 = NORMAL_STATE; //SET state
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  200;
int button1_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(){
	//TODO
	button1_flag = 1;
}

void getKeyInput(){
	KeyReg2 = KeyReg1;
	KeyReg1 = KeyReg0;
	//Add your button here
	KeyReg0 = HAL_GPIO_ReadPin(SET_MODE_GPIO_Port, SET_MODE_Pin);

	if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){ //avoid noise
		if (KeyReg2 != KeyReg3){ //change state
			KeyReg3 = KeyReg2;
			if (KeyReg3 == PRESSED_STATE){
				TimeOutForKeyPress = 200;
				subKeyProcess();
			}
		}

		else{ //press without release
			TimeOutForKeyPress--;
			if (TimeOutForKeyPress == 0){
				KeyReg3 = NORMAL_STATE;
			}

			}
		}
	}



