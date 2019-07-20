#ifndef __ROTENC_H__
#define __ROTENC_H__

#include <Arduino.h>

class RotEnc {
private:
	int _pinA;
	int _pinB;
	volatile int _value=0;

	static RotEnc *_instance;
	static void _pinAHandler();
	static void _pinBHandler();

public:
	RotEnc(int pinA, int pinB);
	int getValue();
};

#endif