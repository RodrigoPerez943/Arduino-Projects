
#include <LiquidCrystal.h>
const int rs = 50, en = 46, d4 = 51, d5 = 49, d6 = 47, d7 = 45;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int bot1 = 29;
int CLK = 37;
int DT = 35;
int SW = 33;
int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";
unsigned long lastButtonPress = 0;
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char letra;
char Letra;
int i = 0;
String nombre;
String apellido;
int a = 0;

void setup() {

  lcd.begin(16, 2);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(bot1, INPUT);
  Serial.begin(9600);

  lastStateCLK = digitalRead(CLK);

}

void loop() {

  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      currentDir = "CCW";
    } else {
      counter ++;
      currentDir = "CW";
    }
  }
  Serial.print("Direction: ");
  Serial.print(currentDir);
  Serial.print(" | Counter: ");
  Serial.println(counter);

  lastStateCLK = currentStateCLK;

  int btnState = digitalRead(SW);

  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed!");
    }
    lastButtonPress = millis();
  }

  if (counter < 0 || counter > 26 )
    counter = 0;

  if (counter >= 0 && counter <= 26 && i != 0)
    letra = alphabet[counter];

  if ( i == 0)
    letra = Alphabet[counter];
    
  if ( a == 0 && nombre == "") {
    lcd.setCursor(0, 0);
    lcd.print("Nombre:");
  }

  if (a <= 1) {
    lcd.setCursor(i, 1);
    lcd.print(letra);
  }

  if (btnState == LOW && a == 0 ) {
    nombre = nombre + letra;
    lcd.print(letra);
    i++;
    counter = 0;
    lcd.setCursor(i, 1);
    delay(400);
    Serial.println(nombre);
  }

  if (digitalRead(bot1) == LOW && a == 0 && nombre != "") {
    delay(500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Apellido:");
    counter = 0;
    i = 0;
    a++;
  }

  if (btnState == LOW && a == 1 ) {
    apellido = apellido + letra;
    lcd.print(letra);
    i++;
    counter = 0;
    lcd.setCursor(i, 1);
    delay(400);
    Serial.println(apellido);
  }


  if (digitalRead(bot1) == LOW && a == 1) {
    a++;
    delay(500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nombre completo:");
    lcd.setCursor(0, 1);
    lcd.print(nombre + " " + apellido);
    counter = 0;
    i = 0;
  }

  if (digitalRead(bot1) == LOW && a == 2) {
    lcd.clear();
    a = 0;
    nombre = "";
    apellido  = "";
    Serial.println(a);
  }
}
