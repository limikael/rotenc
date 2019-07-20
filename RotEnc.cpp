#include "RotEnc.h"

static RotEnc *RotEnc::_instance=NULL;

RotEnc::RotEnc(int pinA, int pinB) {
	_instance=this;

	_pinA=pinA;
	_pinB=pinB;

	pinMode(_pinA,INPUT_PULLUP);
	pinMode(_pinB,INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(_pinA),_pinAHandler,CHANGE);
	attachInterrupt(digitalPinToInterrupt(_pinB),_pinBHandler,CHANGE);
}

static void RotEnc::_pinAHandler() {
	cli();
	if (digitalRead(_instance->_pinA)==digitalRead(_instance->_pinB))
		_instance->_value++;

	else
		_instance->_value--;

	sei();
}

static void RotEnc::_pinBHandler() {
	cli();
	if (digitalRead(_instance->_pinA)==digitalRead(_instance->_pinB))
		_instance->_value--;

	else
		_instance->_value++;

	sei();
}

int RotEnc::getValue() {
	return _value;
}