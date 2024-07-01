#include <LiquidCrystal.h>

LiquidCrystal lcd(43, 41, 39, 37, 35, 33);

void setup()
{
  lcd.begin(16,1);
  lcd.print("hello, world!");
}

void loop() {}
