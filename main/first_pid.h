#ifndef _FIRST_PID_H_
#define _FIRST_PID_H_
#include"Filter.h"

 class F_PID{
 private:
 float P;
 float D;
 float error;
 float error_last;
 float error_fill;

 public:
 F_PID();           //构造函数，用于初始化PD
 
 void set_pid(float p,float d);
 float caculate(float will,float angle,float w);                            //计算函数  angle:经传感器测量出的值 w:角速度
                                                                           // MAX:限幅值,will:期望 time_s : 控制时间
 float Gero_caculate(float will,float gero);
 };

 F_PID::F_PID(){
  P = 0;
  D = 0;
  error = 0;
  error_last = 0;
  error_fill = 0;
 }

 void F_PID::set_pid(float p,float d){
  P = p;
  D = d;
 }


 float F_PID::caculate(float will,float angle,float w)
 {         
  float a;
  error = will - angle;      //误差
  a = (error * P   +  w * D ); 
  return a;
 }

 float F_PID::Gero_caculate(float will,float gero)
 {
     float a;
     error = will - gero;
     error_fill = low_filter((error_last - error),0.05);
     a = (error * P + error_fill* D );
     error_last = error;
     return a;
 }
 
 F_PID fpid;
 F_PID fpid_gero_x;
 F_PID fpid_gero_y;
 
#endif     
