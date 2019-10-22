
#include <Servo.h>

Servo servo1;
int pos1 = 0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9); // define pino PWM
  servo1.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
 
    servo1.write(pos1);
    delay(10);
 }
