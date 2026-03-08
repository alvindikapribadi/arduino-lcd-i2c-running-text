/*
  =========================================================
  Project : Arduino LCD I2C Running Text (Loop Continuous)
  Board   : Arduino Uno
  LCD     : 16x2 I2C Display
  =========================================================

  Components:
  - Arduino Uno
  - LCD 16x2 I2C
  - Jumper wires

  Wiring:
  LCD I2C  -> Arduino
  GND      -> GND
  VCC      -> 5V
  SDA      -> A4
  SCL      -> A5
  =========================================================
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String text = " Welcome to Arduino Running Text Demo ";
String scrollText;

void setup() 
{
  lcd.init();
  lcd.backlight();

  scrollText = text + text;
}

void loop() 
{
  for (int i = 0; i < text.length(); i++) 
  {
    lcd.setCursor(0, 0);
    lcd.print(scrollText.substring(i, i + 16));

    delay(300);
  }
}

