/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: dinhq
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;

void getKeyInput();
int isButton1Pressed();

#endif /* INC_BUTTON_H_ */
