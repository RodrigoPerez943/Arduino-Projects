
const int ledRojo = 35;
const int ledAzul = 39;
const int ledVerde = 43;
const int bot1 = 50;
const int bot2 = 46;
const int bot3 = 42;
const int bot4 = 38;
const int bot5 = 34;
const int buzz = 47;
const int detMag = 51;
int cuenta = 4;
int fallo = 0;

void setup() {

  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  analogWrite(ledRojo, 255);

}

void loop() {

  if ( digitalRead(bot3) == HIGH && cuenta != 4 && cuenta != 1 ) {
    fallo++;
    delay(300);
    Serial.println("3");
  }

  if ( digitalRead(bot1) == HIGH) {
    fallo++;
    delay(300);
    Serial.println("1");
  }

  if ( digitalRead(bot2) == HIGH) {
    fallo++;
    delay(300);
    Serial.println("2");
  }

  if ( digitalRead(bot4) == HIGH && cuenta != 3) {
    fallo++;
    delay(300);
    Serial.println("4");
  }

  if ( digitalRead(bot5) == HIGH && cuenta != 2) {
    fallo++;
    delay(300);
    Serial.println("5");
  }

  if ( fallo == 4) {
    fallo = 0;
    cuenta = 4;
    analogWrite(ledRojo, 0);
    delay(100);
    analogWrite(ledRojo, 255);
    tone(buzz, 2000, 70);
    delay(100);
    analogWrite(ledRojo, 0);
    tone(buzz, 2000, 70);
    delay(100);
    analogWrite(ledRojo, 255);
    tone(buzz, 2000, 70);
    Serial.println("Cuatro fallos");
  }

  if ( digitalRead(bot3) == HIGH && cuenta == 4) {
    cuenta--;
    Serial.println("3");
  }

  if ( digitalRead(bot4) == HIGH && cuenta == 3) {
    cuenta--;
    Serial.println("4");
  }

  if ( digitalRead(bot5) == HIGH && cuenta == 2) {
    cuenta--;
    Serial.println("5");
  }

  if ( digitalRead(bot3) == HIGH && cuenta == 1) {
    Serial.println("3");
    cuenta = 4;
    fallo = 0;
    analogWrite(ledRojo, 0);
    analogWrite(ledVerde, 255);
    tone(buzz, 2000, 40);
    delay(800);
    analogWrite(ledVerde, 0);
    analogWrite(ledRojo, 255);
    Serial.println("Correcto");
  }

  if ( digitalRead(detMag) == LOW) {
    cuenta = 4;
    fallo = 0;
    analogWrite(ledRojo, 0);
    analogWrite(ledVerde, 255);
    tone(buzz, 2000, 40);
    delay(800);
    analogWrite(ledVerde, 0);
    analogWrite(ledRojo, 255);
    Serial.println("Correcto");
  }
}
