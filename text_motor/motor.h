#ifndef _MOTOR_H
#define _MOTOR_H

//#include "first_pid.h"
#include "control_motor.h"
//#include "_mpu6050.h"
/*
void initialAC()
{
  float kp=30,kd=0.5;
  fpid.set_pid(kp,kd);
}
void controlAC()
{
  float result;
  result = ((fpid.caculate(res,ang_y,0.01)));
  motor.motor_A(-result);
  motor.motor_C(result);
  result = ((fpid.caculate(0,ang_y,0.01)));
  motor.motor_B(-result);
  motor.motor_D(result);
}*/

void controlAC(){
  motor.motor_A(-250);
  motor.motor_C(250);
}
void controlBD(){
  motor.motor_B(-60);
  motor.motor_D(-60);
}

void motorInitial()
{
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(PWMA,OUTPUT);
pinMode(B1,OUTPUT);
pinMode(B2,OUTPUT);
pinMode(PWMC,OUTPUT);
pinMode(C1,OUTPUT);
pinMode(C2,OUTPUT);
pinMode(PWMC,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(PWMD,OUTPUT);
}
#endif
