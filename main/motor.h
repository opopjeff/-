#ifndef _MOTOR_H
#define _MOTOR_H

#include "first_pid.h"
#include "control_motor.h"
#include "KalmanFilter.h"
MPU6050 Mpu6050;
int16_t ax, ay, az,gx, gy, gz;
//==================================
float filter_res;
//==================================
void initialAC()
{
  fpid.set_pid(10,5);
  fpid_gero_x.set_pid(5,5);
}

void controlAC()
{
  float result1,result2;
  result1 = ((fpid.caculate(res,KalFilter_x.angle6+38.2,KalFilter_x.Gyro_y)));  //PD控制
  //Serial.print(KalFilter_x.angle6+38.2);Serial.print(" ");
  //Serial.println(KalFilter_x.Gyro_y); //Serial.print(" ");
  //Serial.println(result1);
   result1 = (result1>255)?255:result1;
  result1 = (result1<-255)?-255:result1;
  result2 = fpid_gero_x.Gero_caculate(result1,KalFilter_x.Gyro_y);
  result2 = (result2>255)?255:result2;
  result2 = (result2<-255)?-255:result2;
  /*Serial.print(KalFilter_x.angle6+38.2);Serial.print(" ");
  Serial.print(KalFilter_x.Gyro_y); Serial.print(" ");
  Serial.print(res); Serial.print(" ");
  Serial.println(result2);*/
  if(result2>0)  {motor.motor_C(result2);motor.motor_A(0);}
  else {motor.motor_A(abs(result2));motor.motor_C(0);}
  
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
