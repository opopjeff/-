#ifndef _CONTROL_H_
#define _CONTROL_H_
#include <MsTimer2.h>        //定时中断
void control(){
  sei();//全局中断开启
  Mpu6050.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  //获取MPU6050陀螺仪和加速度计的数据
  Serial.println(ax);
}
void Control_Init(void)
{
  MsTimer2::set(5, control);  //使用Timer2设置5ms定时中断
  MsTimer2::start();          //使用中断使能
} 




#endif
