const int sensorPin = A0;
const float baselineTemp = 20.0;
void setup() {
  Serial.begin(9600);
  for ( int i = 2; i <= 4; i++) {
    digitalWrite(i, LOW);
    pinMode(i, OUTPUT);
  }
}

void loop() {

  int sensorVal = analogRead(sensorPin);
  Serial.println("Valor del sensor:");
  Serial.println(sensorVal);

  float voltaje = sensorVal / 1024.0 * 5.0;
  Serial.println("Valor del voltaje:");
  Serial.println(voltaje);

  float temp = (voltaje - 0.5) * 100;
  Serial.println("Valor de la temperatura:");
  Serial.println(temp);

  float valorRest = temp - baselineTemp;


  if ( valorRest / 2.0 > 1.0) {
    float a = 2.0;
    for (int num = 2 ; num < 5; num ++) {
      if ( (valorRest - a) >= 0.0) {
        digitalWrite(num, HIGH);
        a += 2.0;
      }
      else
      digitalWrite(num, LOW);
    }
    delay(1000);
  }
}
