#ifndef _FILTER_H_
#define _FILTER_H_
float out,out_last;

float low_filter(float in,float q){
  out = q*in + (1 - q)*out_last;
  out_last = out;
  return out;
}





#endif
