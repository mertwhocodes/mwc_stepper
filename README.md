[![arduino-library-badge](https://www.ardu-badge.com/badge/mwc_stepper.svg?)](https://www.ardu-badge.com/mwc_stepper)
# MWC_Stepper Step Driver 
 Arduino Step Motor Driver Library. For more information about that library usage, go to my blog page [mertwhocodes-step-driver]( http://mertwhocodes.com/index.php/en/2020/05/08/stepper-motor-driver-with-arduino/)
  

# **Description**
This is the library for drive step motor for Arduino. It supports DC motors & Stepper motors with microstepping.
A4988, DRV8825, DRV8834, DRV8880,TB6600... and generic two-pin stepper motor driver library. Features:
- Constant speed mode(RPM)
- Microstepping 
# **Connection:**
![WIRE CONNECTION](http://mertwhocodes.com/wp-content/uploads/2020/05/Resim1-e1588902990129-1024x785.png)
# **Wiring**
- VCC	9-42 **–** VDC
- GND	**-** Power supply ground
- ENA-	**-** Arduino GND
- ENA+	**-** Arduino Pin 5
- DIR-	**-** Arduino GND
- DIR+	**-** Arduino Pin 4
- PUL-	**-** Arduino GND
- PUL+	**-** Arduino Pin 3
- A-, A+	**-** Coil 1 stepper motor
- B-, B+	**-** Coil 2 stepper motor
# **Functions**
```c
void init(); //makes pin configuration 
void active(bool _active); //makes enable pin LOW(active)or HIGH(deactive)
void run(uint64_t _rpmt);//motor rotation start with RPM value 
void set(bool _dir, uint8_t _rpm, uint16_t _pulse);//sets direction ,RPM value and steppping value
void run();//motor rotation start with last setted RPM value
 ```
 Before use ```run();``` function ```set();``` function have to configure. 
# **Code**
See basic two direction stepping 1:8 1 tour for each direction example.
```c
/*
 Name:		step_drive.ino
 
 Author:	mertwhocodes
*/
#include<mwc_stepper.h>

#define EN_PIN 3
#define DIR_PIN 2
#define STEP_PIN 5

#define RPM 50
#define RPM1 50

#define PULSE 1600

#define ClOCKWISE 1
#define OTHERWISE 0

MWCSTEPPER nema23(EN_PIN, DIR_PIN, STEP_PIN);

void setup() {

	nema23.init();
	
}

void loop() {
	nema23.set(ClOCKWISE, RPM, PULSE);

	for (size_t i = 0; i < 1600; i++)
	{
		nema23.run();
	}

	delay(1000);

	nema23.set(OTHERWISE, RPM1, PULSE);

	for (size_t i = 0; i < 1600; i++)
	{
		nema23.run();
	}
}

```
