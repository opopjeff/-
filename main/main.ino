#include <FlexiTimer2.h>
#include "MPU6050.h"
#include "Wire.h"
#include "I2Cdev.h"
#include"wave_create.h"
#include"control_motor.h"
#include "motor.h"

static float p_angle,d_angle,p_w,d_w;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  initialAC();
  Mpu6050.initialize();
  motorInitial();
  FlexiTimer2::set(10,1.0/1000,controlAC);
  FlexiTimer2::start();
}

void loop() {
   wave_create(2.5); 
   Mpu6050.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
   KalFilter_x.Angletest_x(ax,az,gz,gy); 
   KalFilter_y.Angletest_y(ay,az,gz,gx);
   
    //=======================================================================
   //filter_res = low_filter(KalFilter_x.angle6+38.2,0.05);
   //======================================================================

   Serial.print(KalFilter_x.angle6+38.2);Serial.print(" ");
   //Serial.print(filter_res);Serial.print(" ");
   Serial.println(res);
} 
