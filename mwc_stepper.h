// stepper.h

#ifndef _MWC_STEPPER_h
#define _MWC_STEPPER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MWCSTEPPER {
	
private:
	uint8_t enPin;
	uint8_t stepPin;
	uint8_t dirPin;
    uint64_t rpm_t=500;
public:
	MWCSTEPPER(uint8_t _enPin, uint8_t _dirPin, uint8_t _stepPin);
	void init();
	void active(bool _active);
	void run(uint64_t _rpmt);
	void run();
	void set(bool _dir, uint8_t _rpm, uint16_t _pulse);
};


#endif
