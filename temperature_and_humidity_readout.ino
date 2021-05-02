#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {  
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("Temp:       ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:   ");
}

void loop() {
  delay(500);
  lcd.setCursor(0, 1);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  if (isnan(h) || isnan(f)) {
    lcd.print("ERROR");
    return;
  }
  lcd.setCursor(12, 0)
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(12, 1);
  lcd.print(h);
  lcd.print("  %");
}