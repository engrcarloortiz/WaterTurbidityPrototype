#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 16);
int sensorPin = A0;
int ErrorLightPin = 2;
int ErrorLightFreq = 1000;
int ResetButton = 5;
void setup()
{ 
  Serial.begin(9600);
  lcd.begin();
}
void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  int turbidity = map(sensorValue, 0, 580, 100, 0);
  delay(50);
  lcd.setCursor(0, 0);
  lcd.print("Kalinawan: ");
  lcd.print("   ");
  lcd.setCursor(10, 0);
  lcd.print(turbidity);
  delay(500);
  if (turbidity < 20) {
    lcd.setCursor(0, 1);
    lcd.print(" MALINAW ");
  }
  if ((turbidity > 10) && (turbidity < 50)) {
    lcd.setCursor(0, 1);
    lcd.print(" MALABO ");
  }
  if (turbidity > 50) {
    lcd.setCursor(0, 1);
    lcd.print(" MADUMI ");
    digitalWrite(ErrorLightPin, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000); // wait for a second
    digitalWrite(ErrorLightPin, LOW); // turn the LED off by making the voltage LOW
    delay(1000); // wait for a second
  }
}