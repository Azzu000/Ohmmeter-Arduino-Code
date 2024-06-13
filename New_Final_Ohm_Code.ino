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
int Sample_size = 50;

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
  Voltage = 0;
  Sum=0;
  Average_Voltage=0;
  Resistance=0;
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  for(int i = 0; i < Sample_size; i++){
    adc0 = ads.readADC_SingleEnded(0);
    Voltage = (adc0 * 0.1875)/1000;
    Sum = Sum + Voltage;
  }
  
  Average_Voltage = Sum / Sample_size;
  Resistance = (Average_Voltage)/(0.002837);

  if(Resistance < 10){
    Resistance = Resistance - 2;
  }
  if(Voltage > 3.316){
    Voltage = 0;
    Sum=0;
    Average_Voltage=0;
    Resistance=0;
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    for(int i = 0; i < Sample_size; i++){
      adc0 = ads.readADC_SingleEnded(0);
      Voltage = (adc0 * 0.1875)/1000;
      Sum = Sum + Voltage;
    }
    
    Average_Voltage =  Sum / Sample_size;
    Resistance = (Average_Voltage)/(0.000165062);
    if(Voltage > 3.629){
      Voltage = 0;
      Sum=0;
      Average_Voltage=0;
      Resistance=0;
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);

      for(int i = 0; i < Sample_size; i++){
        adc0 = ads.readADC_SingleEnded(0);
        Voltage = (adc0 * 0.1875)/1000;
        Sum = Sum + Voltage;
      }

      Average_Voltage = Sum/Sample_size;
      Resistance = (Average_Voltage)/(0.000014944);

      if(Voltage > 3.200){
        Voltage = 0;
        Sum=0;
        Average_Voltage=0;
        Resistance=0;
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);

        for(int i = 0 ; i < Sample_size; i++){
          adc0 = ads.readADC_SingleEnded(0);
          Voltage = (adc0 * 0.1875)/1000;
          Sum = Sum + Voltage;
        }
        Average_Voltage = Sum/Sample_size;
        Resistance = (Average_Voltage)/(0.000002092);
      }
    }
    }
    if(Resistance > 2000000){
      lcd.clear();
      lcd.print("No load");
      delay(1000);
    } else {
      if(Resistance >= 295000){
        Resistance=Resistance - 2300;
        if(Resistance >= 340000){
          Resistance = Resistance + 6000;
          if(Resistance >= 395000){   
          Resistance = Resistance + 3000;
            if(Resistance >= 440000){
              Resistance = Resistance + 5000;
              if(Resistance >= 495000){
                Resistance = Resistance + 0;
                if(Resistance >= 540000){
                  Resistance = Resistance + 12000;
                  if(Resistance >= 595000){   
                    Resistance = Resistance + 0;
                    if(Resistance >= 640000){
                      Resistance = Resistance + 17000;
                      if(Resistance >= 695000){
                        Resistance = Resistance + 0;
                        if(Resistance >= 740000){
                          Resistance = Resistance + 20000;
                          if(Resistance >= 795000){   
                            Resistance = Resistance + 0;
                            if(Resistance >= 840000){
                              Resistance = Resistance + 0;
                              if(Resistance >= 895000){
                                Resistance = Resistance + 0;
                                if(Resistance >= 940000){
                                Resistance = Resistance + 10000;
                                  if(Resistance >= 995000){   
                                  Resistance = Resistance + 0;
                                    if(Resistance >= 1040000){
                                    Resistance = Resistance+0;
                                    if(Resistance >= 1095000){
                                        Resistance = Resistance + 10000;
                                        if(Resistance >= 1140000){ 
                                          Resistance = Resistance + 10000;
                                          if(Resistance >= 1195000){   
                                            Resistance=Resistance + 0;
                                            if(Resistance >=1240000){
                                              Resistance=Resistance+0;
                                              if(Resistance >= 1295000){
                                                Resistance=Resistance+0;
                                                if(Resistance >=1340000){
                                                  Resistance=Resistance+0;
                                                  if(Resistance >=1395000){   
                                                  Resistance=Resistance+0;
                                                    if(Resistance >=1440000){
                                                      Resistance=Resistance+0;
                                                    }
                                                  }
                                                } 
                                              }
                                            }
                                          }
                                        } 
                                      }
                                    }
                                  }
                                } 
                              }
                            }
                          }
                        } 
                      }
                    }
                  }
                } 
              }
            }
          }
        } 
      }

      Serial.print("AIN0: ");
      Serial.print(adc0);
      Serial.print("\tVoltage: ");
      Serial.println(Voltage, 7);
      Serial.println();  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Resistance:   ");
      lcd.setCursor(3,1);
      lcd.print(Resistance,4);
      delay(500);
    
  }
}
