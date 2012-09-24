/*
 * mma7361.cpp
 *
 *  Created on: Sep 24, 2012
 *      Author: nemo
 */

#include "mma7361.h"

MMA7361 :: MMA7361(void){
}

void MMA7361 :: begin(uint8_t new_pin_0g_Detect, uint8_t new_pin_SelfTest, uint8_t new_pin_g_Select, uint8_t new_pin_SleepMode, uint8_t new_pin_Xout, uint8_t new_pin_Yout, uint8_t new_pin_Zout){
	pin_0g_Detect	=	new_pin_0g_Detect;
	pin_SelfTest	=	new_pin_SelfTest;
	pin_g_Select	=	new_pin_g_Select;
	pin_SleepMode	=	new_pin_SleepMode;
	pin_Xout		=	new_pin_Xout;
	pin_Yout		=	new_pin_Yout;
	pin_Zout		=	new_pin_Zout;

	pinMode(pin_SleepMode,	OUTPUT);
	pinMode(pin_g_Select,	OUTPUT);
	pinMode(pin_0g_Detect,	INPUT);
}

void MMA7361 :: getState(uint8_t *X, uint8_t *Y, uint8_t *Z){
	*X = analogRead(pin_Xout);
	*Y = analogRead(pin_Yout);
	*Z = analogRead(pin_Zout);
}

void MMA7361 :: setSleepState(bool mode){
	digitalWrite(pin_SleepMode, (uint8_t)mode);
}

void MMA7361 :: setSensitivity(bool mode){
	digitalWrite(pin_g_Select, (uint8_t)mode);
}

void MMA7361 :: setInteruptHandler(void (*user_handler)(void)){
	if(pin_0g_Detect == 2) attachInterrupt(0 ,user_handler, FALLING);
	if(pin_0g_Detect == 3) attachInterrupt(1 ,user_handler, FALLING);
}
