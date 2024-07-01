#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  
myServo.attach(9);

Serial.begin(9600);

}

void loop() {

  potVal = analogRead(potPin);
  Serial.println("Valor del potenciometro: " + (String)potVal);

  angle = map(potVal,0,1023,0,90);
  Serial.println("Valor del angulo: " + (String)angle);

  myServo.write(angle);
  delay(15);
  
  

}
