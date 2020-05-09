// 
// 
// 

#include "mwc_stepper.h"


MWCSTEPPER::MWCSTEPPER(uint8_t _enPin, uint8_t _dirPin, uint8_t _stepPin)
{
	stepPin = _stepPin;
	dirPin = _dirPin;
	enPin = _enPin;
}
void MWCSTEPPER::init() {
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
	pinMode(enPin, OUTPUT);
	digitalWrite(enPin, LOW);

}
void MWCSTEPPER::set(bool _dir, uint8_t _rpm, uint16_t _pulse) {
	digitalWrite(dirPin, _dir);
	rpm_t = 60000000 / 2 / _pulse / _rpm;
	
}
void MWCSTEPPER::run(uint64_t _rpmt) {
	
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(_rpmt);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(_rpmt);
	
}
void MWCSTEPPER::run() {

	digitalWrite(stepPin, HIGH);
	delayMicroseconds(rpm_t);
	digitalWrite(stepPin, LOW);
	delayMicroseconds(rpm_t);

}

void MWCSTEPPER::active(bool _active) {
	digitalWrite(enPin, _active);
}
