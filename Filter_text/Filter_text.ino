#include"Filter.h"
#include"wave_create.h"
float res_fill;
void setup() {
  Serial.begin(9600);
}

void loop() {
   res = wave_create(2.5);
   res_fill = low_filter(res,0.05);
   Serial.print(res); Serial.print(" ");
   Serial.println(res_fill);
}
