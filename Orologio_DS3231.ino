#include <Time.h>
#include <TimeLib.h>
#include <DS3232RTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("  Orologio DS3231  ");
  lcd.setCursor(0, 1);
  lcd.print("  Pagina Facebook:  ");
  lcd.setCursor(0, 2);
  lcd.print("Progetti & Tutorial");
  lcd.setCursor(0, 3);
  lcd.print("      Ardunio       ");

  delay(3000);
  lcd.clear();

  setSyncProvider(RTC.get);

  if (timeStatus() != timeSet) {
    lcd.setCursor(0, 1);
    lcd.print(" RTC non sincorniz. ");
  }

  else {
    lcd.setCursor(0, 1);
    lcd.print(" RTC  sincronizzato ");
  }

  delay(2000);
  lcd.clear();
}

void loop() {
  digitalClockDisplay();
  delay(1000);
}

void digitalClockDisplay(void) {

  lcd.setCursor(12, 1);
  lcd.print("Data");
  lcd.setCursor(10, 2);
  lcd.print(day());
  lcd.print("/");
  lcd.print(month());
  lcd.print("/");
  lcd.print(year());

  lcd.setCursor(3, 1);
  lcd.print("Ora");
  lcd.setCursor(1, 2);
  lcd.print(hour());
  printDigits(minute());
  printDigits(second());
}

void printDigits(int digits) {

  lcd.print(":");

  if (digits < 10) {
    lcd.print("0");
  }

  lcd.print(digits);
}
