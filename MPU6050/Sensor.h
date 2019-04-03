#ifndef __Sensor_H
#define __Sensor_H

#include "Arduino.h"
#include "I2Cdev.h"
#include "Wire.h"
#include <KalmanFilter.h>    //卡尔曼滤波
#include <MPU6050_6Axis_MotionApps20.h>//MPU6050库文件

//定义电源检测引脚
#define VIN A0
//实例化一个 MPU6050 对象，对象名称为 Mpu6050
MPU6050 Mpu6050;

//MPU6050的三轴加速度和三轴陀螺仪数据
int16_t ax, ay, az, gx, gy, gz;  

//********************************************************

void Sensor_Init(void)
{
  pinMode(VIN,INPUT);
  Wire.begin();  //加入 IIC 总线
  delay(500);
  Mpu6050.initialize();     //初始化MPU6050
  delay(1000);
}

#endif
