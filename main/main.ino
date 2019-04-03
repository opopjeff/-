#include"Sensor.h"
#include"control_motor.h"
#include "control.h"
#include"parametreReceiver.h"
void setup() {
  Serial.begin(500000);
  Sensor_Init();
  control_init();
}

void loop() {
  while(Serial.available()){
    ParameterReceive();
  }
} 
