#ifndef _FIRST_PID_H_
#define _FIRST_PID_H_

 class F_PID{
 private:
 static float PWM_right;   //风力指向位移方向的风机输出
 static float PWM_left;    //风力背向位移方向的风机输出
 float P;
 float D;
 float I;
 float error;
 float error_last;
 float error_all;

 public:
 F_PID();           //构造函数，用于初始化PD
 void set_pid(float p,float d);
 void set_pid(float p,float i,float d);
 void set_pid(float p);
 void caculate(float will,float angle,float MAX,float time_s);        //计算函数  angle:经传感器测量出的值
                                                                           // MAX:限幅值,will:期望 time_s : 控制时间
 };

 F_PID::F_PID(){
  P = 0;
  D = 0;
  D = 0;
  error = 0;
  error_last = 0;
  error_all = 0;
 }

 void F_PID::set_pid(float p,float d){
  P = p;
  D = d;
  I = 0;
 }

 void F_PID::set_pid(float p,float i,float d){
  P = p;
  D = d;
  I = i;
 }

 void F_PID::set_pid(float p){
  P = p;
  I = 0;
  D = 0;
 }

 void F_PID::caculate(float will,float angle,float MAX,float time_s){         
  float a;
  error = will - angle;      //误差
  a = (error * P + (error - error_last) * D * (1/time_s) + error_all * I * time_s) * 0.5; //PID控制
  error_last = error;
  error_all +=error;
  //a = (a>MAX)?MAX:a;              此处需要做一个限幅，或者归一化操作
  //a = (a<-MAX)?-MAX:a;
  PWM_right = a;
  PWM_left = -a;
 }
#endif
