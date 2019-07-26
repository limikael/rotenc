#ifndef __ROTENC_H__
#define __ROTENC_H__

#ifndef MOCK_ARDUINO
#include <Arduino.h>
#endif

class RotEnc {
public:
	RotEnc(int pinA, int pinB);
	int getValue();

private:
	int _pinA;
	int _pinB;
	volatile int _value=0;

	static RotEnc *_instance;
	static void _pinAHandler();
	static void _pinBHandler();

	friend void setRotEncMockValue(int v);
};

#endif