#ifndef _CONTROL_MOTOR_H_
#define _CONTROL_MOTOR_H_
#include"arduino.h"

#define PWMA 3
#define PWMB 9
#define PWMC 5
#define PWMD 6
#define A1 10
#define A2 2
#define B1 7
#define B2 8
#define C1 13
#define C2 12
#define D1 4
#define D2 0

class MOTOR{
  private:
      unsigned int a;
      unsigned int b;
      unsigned int c;
      unsigned int d;
  public:
      MOTOR();
      void motor_A(unsigned int a);
      void motor_B(unsigned int b);
      void motor_C(unsigned int c);
      void motor_D(unsigned int d);
};
MOTOR::MOTOR(){
 a = 0;
 b = 0;
 c = 0;
 d = 0;
}

void MOTOR::motor_A(unsigned int a){
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
  analogWrite(PWMA,a);
}

void MOTOR::motor_B(unsigned int b){
  digitalWrite(B1,LOW);
  digitalWrite(B2,HIGH);
  analogWrite(PWMB,b);
}

void MOTOR::motor_C(unsigned int c){
  digitalWrite(C1,LOW);
  digitalWrite(C2,HIGH);
  analogWrite(PWMC,c);
}

void MOTOR::motor_D(unsigned int d){
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  analogWrite(PWMD,d);
}

MOTOR motor;
#endif
