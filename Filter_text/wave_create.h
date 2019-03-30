#ifndef _WAVE_CREATE_H_
#define _WAVE_CREATE_H_
#define PI 3.1415
float res;
unsigned int q = 0;
float Start_time,end_time;

float wave_create(int a){
  float p = 0;
    p = q*0.04*PI;
    q++; if(q == 50)  {q = 0;} 
    res = a*sin(p);
    return res; 
}




#endif
