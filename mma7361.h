/*
 * mma7361.h
 *
 *  Created on: Sep 24, 2012
 *      Author: nemo
 */

#ifndef MMA7361_H_
#define MMA7361_H_

class MMA7361{
public:
	MMA7361(void);
	void begin(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
	void getState(uint8_t *, uint8_t *, uint8_t *);
	void setSleepState(bool);
	void setSensitivity(bool);
	void setInteruptHandler(void (*)(void));
private:

	uint8_t	pin_0g_Detect;
	uint8_t pin_SelfTest;
	uint8_t pin_g_Select;
	uint8_t pin_SleepMode;
	uint8_t pin_Xout;
	uint8_t pin_Yout;
	uint8_t pin_Zout;
};




#endif /* MMA7361_H_ */
