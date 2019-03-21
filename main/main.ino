#include"control_motor.h"
#include "MPU6050.h"
#include "Wire.h"
#include "I2Cdev.h"
#include"Filter.h"
#include"first_pid.h"
MPU6050 Mpu6050;
int16_t ax, ay, az,gx, gy, gz;
void setup() {
  Wire.begin();
  Mpu6050.initialize();
  Serial.begin(9600);
}

void loop() {
   Mpu6050.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
   KalFilter.Angletest(ax, ay, az, gx, gy, gz, dt, Q_angle, Q_gyro, R_angle, C_0, K1);          //通过卡尔曼滤波获取角度
  }
