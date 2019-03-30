#ifndef _CONTROL_MOTOR_H_
#define _CONTROL_MOTOR_H_
#include"arduino.h"

#define PWMA 10
#define PWMB 9
#define PWMC 5
#define PWMD 6
#define A1 1
#define A2 2
#define B1 7
#define B2 8
#define C1 13
#define C2 12
#define D1 4
#define D2 0

class MOTOR{
  private:
       int a;
       int b;
       int c;
       int d;
  public:
      MOTOR();
      void motor_A(int a);
      void motor_B(int b);
      void motor_C(int c);
      void motor_D(int d);
};
MOTOR::MOTOR(){
 a = 0;
 b = 0;
 c = 0;
 d = 0;
}

void MOTOR::motor_A(int a){
  if(a>0)
  {
    if(a>255)
    a=255;
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
  analogWrite(PWMA,a);
  }
  else
  {
    if(a<-255)
    a=-255;
  digitalWrite(A1,HIGH);
  digitalWrite(A2,LOW);
  analogWrite(PWMA,abs(a));
  }
}

void MOTOR::motor_B(int b){
  if(b>0)
  {
    if(b>255)
    b=255;
  digitalWrite(B1,LOW);
  digitalWrite(B2,HIGH);
  analogWrite(PWMB,abs(b));
  }
  else
  {
    if(b<-255)
    b=-255;
  digitalWrite(B1,HIGH);
  digitalWrite(B2,LOW);
  analogWrite(PWMB,abs(b));
  }
}

void MOTOR::motor_C(int c){
  if(c>0)
  {
    if(c>255)
    c=255;
  digitalWrite(C1,LOW);
  digitalWrite(C2,HIGH);
  analogWrite(PWMC,c);
  }
  else
  {
    if(c<-255)
    c=-255;
  digitalWrite(C1,HIGH);
  digitalWrite(C2,LOW);
  analogWrite(PWMC,abs(c));
  }
}

void MOTOR::motor_D(int d){
  if(d>0)
  {
    if(d>255)
    d=255;
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  analogWrite(PWMD,d);
  }
  else
  {
    if(d<-255)
    d=-255;
  digitalWrite(D2,LOW);
  digitalWrite(D1,HIGH);
  analogWrite(PWMD,abs(d));
  }
}

MOTOR motor;
#endif
