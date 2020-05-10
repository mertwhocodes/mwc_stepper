/*
 Name:    step_drive.ino
 Author:  mertwhocodes
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
  
  //nema23.active(DEACTIVE);
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
    //nema23.run();
  }
}
