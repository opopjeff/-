#include"motor.h"
void setup() {
  motorInitial();
}

void loop() {
  controlAC();
  //controlBD();
  delay(1000);

}
