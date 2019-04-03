#ifndef _CONTROL_H
#define _CONTROL_H

#include "first_pid.h"
#include "control_motor.h"
#include "KalmanFilter.h"
#include"wave_create.h"
#include <MsTimer2.h>        //定时中断


float result1,result2;
unsigned int i;


void angle_PD(){              //角度PD控制
   result1 = ((fpid.caculate(res,KalFilter_x.angle6+38.2,KalFilter_x.Gyro_y)));  //PD控制
   
   //#define text_angle
   #ifdef  text_angle
            Serial.print(KalFilter_x.angle6+38.2);Serial.print(" ");
            Serial.print(KalFilter_x.Gyro_y); Serial.print(" ");
            Serial.println(result1);
  #endif
 
  result1 = (result1>255)?255:result1;
  result1 = (result1<-255)?-255:result1;
}

void Gyro_y_PD()       //角加速度PD控制
{
  result2 = fpid_gero_x.Gero_caculate(result1,KalFilter_x.Gyro_y);
  result2 = (result2>255)?255:result2;
  result2 = (result2<-255)?-255:result2;
  //==============================================================
  //#define text_gyro
  #ifdef  text_gyro
  Serial.print(KalFilter_x.angle6+38.2);Serial.print(" ");
  Serial.print(KalFilter_x.Gyro_y); Serial.print(" ");
  Serial.println(result2);
  #endif
  //================================================================
}

void control()
{
  
  sei();      //开启全局中断，禁止一切中断来处理一下的程序
  res = wave_create(2.5);//产生幅度为2.5的正弦信号
  Mpu6050.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);   //获取MPU6050原始数据
  KalFilter_x.Angletest_x(ax,az,gz,gy);               //通过一阶互补滤波获得x、y角度值
  KalFilter_y.Angletest_y(ay,az,gz,gx);
  //======================================================================================
  #define text
  #ifdef text
  Serial.print(KalFilter_x.angle6+38.2);Serial.print(" ");
  Serial.println(res);
  #endif
 
  //=======================================================================================
  if(i==2){           //中断为5ms，每10ms进行一次控制
    i = 0;
  angle_PD();
  Gyro_y_PD();
  
  if(result2>0)  {motor.motor_B(result2);motor.motor_A(0);}
  else {motor.motor_A(abs(result2));motor.motor_B(0);}
  }else i++;
}


void control_init()
{
  motorInitial(); //对于电机的硬件初始化定义
  delay(100);
  MsTimer2::set(5,control);  //使用Timer2设置5ms定时中断
  MsTimer2::start();          //使用中断使能
}


#endif
