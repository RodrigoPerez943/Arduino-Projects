  
const int ledRojo = 11;
const int ledVerde = 10;
const int ledAzul = 9;

const int resRojo = A0;
const int resVerde = A1;
const int resAzul = A2;

int valLedRojo = 0;
int valLedVerde = 0;
int valLedAzul = 0;

int valResRojo = 0;
int valResVerde = 0;
int valResAzul = 0;

void setup() {
  
Serial.begin(9600);

pinMode(ledRojo,OUTPUT);
pinMode(ledVerde,OUTPUT);
pinMode(ledAzul,OUTPUT);

}

void loop() {

valResRojo = analogRead(resRojo);
delay(100);
valResVerde =analogRead(resVerde);
delay(100);
valResAzul =analogRead(resAzul);

Serial.println ( "Valor Rojo: " + (String)valResRojo + "Valor Verde: " + (String)valResVerde + "Valor Azul: " + (String)valResAzul );

valLedRojo = valResRojo/4;
valLedVerde = valResVerde/4;
valLedAzul = valResAzul/4;

Serial.println ( "Valor Rojo: " + (String)valLedRojo + "Valor Verde: " + (String)valLedVerde + "Valor Azul: " + (String)valLedAzul );

analogWrite(ledRojo,valLedRojo);
analogWrite(ledVerde,valLedVerde);
analogWrite(ledAzul,valLedAzul);

}
