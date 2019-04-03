#ifndef _PARAMETRERECEIVE_H_
#define _PARAMETRERECEIVE_H_

#include "first_pid.h"

void ParameterReceive(void)
{
  float angle_kp, angle_kd,Gyro_kp,Gyro_kd;
  angle_kp = Serial.parseFloat();
  angle_kd = Serial.parseFloat();
  Gyro_kp = Serial.parseFloat();
  Gyro_kd = Serial.parseFloat();
  fpid.set_pid(angle_kp,angle_kd);
  fpid_gero_x.set_pid(Gyro_kp,Gyro_kd);
}


#endif
