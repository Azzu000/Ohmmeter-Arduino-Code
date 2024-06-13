#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 or 0x3f for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48);
float Voltage = 0.0;
float Resistance = 0.0;
float Sum = 0.0;
float Average_Voltage = 0.0;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  ads.begin();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  int16_t adc0; // 16 bits ADC read of input A0
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  for (int i = 0; i < 10; i++){
    adc0 = ads.readADC_SingleEnded(0);
    Voltage = (adc0 * 0.1875)/1000;
    Sum = Sum + Voltage;
  }

  Average_Voltage = Sum / 10;
  Resistance = (Voltage)/(0.00278);

  if(Voltage > 3.316){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    for (int i = 0; i < 10; i++){
      adc0 = ads.readADC_SingleEnded(0);
      Voltage = (adc0 * 0.1875)/1000;
      Sum = Sum + Voltage;
    }

    Average_Voltage = Sum / 10;
    Resistance = (Average_Voltage)/(0.0001649);

    if(Voltage > 3.629){
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);

      for (int i = 0; i < 10; i++){
        adc0 = ads.readADC_SingleEnded(0);
        Voltage = (adc0 * 0.1875)/1000;
        Sum = Sum + Voltage;
      }
      
      Average_Voltage = Sum / 10;
      Resistance = (Average_Voltage)/(0.0000152);

      if(Voltage > 3.302){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);

        for (int i = 0; i < 10; i++){
          adc0 = ads.readADC_SingleEnded(0);
          Voltage = (adc0 * 0.1875)/1000;
          Sum = Sum + Voltage;
        }
        
        Average_Voltage = Sum / 10;
        Resistance = (Average_Voltage)/(0.000002);

      }
    }
  }
  
  
  Serial.print("AIN0: ");
  Serial.print(adc0);
  Serial.print("\tVoltage: ");
  Serial.println(Average_Voltage, 7);
  Serial.println();  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Resistance:   ");
  lcd.setCursor(3,1);
  lcd.print(Resistance,7);
  delay(1000);
  
}
