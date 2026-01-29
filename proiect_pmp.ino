#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include "pitches.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(2, DHT11);

float humidity = 0.0;
float temp_air = 0.0;
float nivel_apa = 0.0;
float humid_ground = 0.0;

int alarmMelody[] = { NOTE_A5, NOTE_E5, NOTE_A5, NOTE_E5 };
int alarmDurations[] = { 4, 4, 4, 4 };
int powerPin = 7;
int relay_pin = 3;

bool force_start = false;

void setup() {

  DDRA = B00000000;
  PORTA = 0x00;

  dht.begin();
  pinMode(8, OUTPUT);
  pinMode(relay_pin, OUTPUT);
  pinMode(powerPin,OUTPUT);
  digitalWrite(powerPin,LOW);
  digitalWrite(relay_pin,HIGH);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Proiect PMP");
  delay(2000);
  lcd.clear();
}

void loop() {

  humidity = dht.readHumidity();
  temp_air = dht.readTemperature();

  digitalWrite(powerPin,HIGH);
  delay(10);

  nivel_apa = analogRead(A0) * (5.0 / 1023.0); 

  float interval = 1023.0 - 200.0;
  int sol = analogRead(A1);
  humid_ground = ((1023 - (float)sol) / interval) * 100.0;

  digitalWrite(powerPin, LOW);


  if(nivel_apa <= 1.0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NU MAI ESTE APA");
    lcd.setCursor(0, 1);
    lcd.print("PUNETI APA!");
    declanseazaAlarma();
  }
  else{

if(humid_ground <= 30 || force_start){
      lcd.clear();
      lcd.print("POMPA ACTIVA...");
      digitalWrite(relay_pin, LOW); 
      delay(3000);                  
      digitalWrite(relay_pin, HIGH); 
      
      force_start = false;
      lcd.clear();
      lcd.print("ASTEPTARE ABSORBTIE");
      delay(2000); 
      lcd.clear();
    }

  if(digitalRead(22) == HIGH){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umi: "); lcd.print(humidity); lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp: "); lcd.print(temp_air); lcd.write(223); lcd.print("C");
    delay(3000); 
    lcd.clear();
  }

  if(digitalRead(23) == HIGH){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Nivel Apa:");
    lcd.setCursor(0,1);
    
    if(nivel_apa < 1.15){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NIVEL SCAZUT APA:");
      lcd.setCursor(0, 1);
      //lcd.print(nivel_apa);
    }
    else if(nivel_apa >=1.30 && nivel_apa < 1.5){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NIVEL MEDIU APA:");
      lcd.setCursor(0, 1);
    //lcd.print(nivel_apa);
    }
    else if(nivel_apa >=1.5){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NIVEL RIDICAT");
      lcd.setCursor(0,1);
      lcd.print("APA");
      //lcd.print(nivel_apa);
    }
    
    delay(3000);
    lcd.clear();
  }
  if(digitalRead(24) == HIGH){
    lcd.clear();
    lcd.print("Umiditate Sol:");
    lcd.setCursor(0,1);
    lcd.print(humid_ground); lcd.print("%");
    delay(2000);
    lcd.clear();
  }

    if(digitalRead(25) == HIGH){
    force_start = true;
  }


  // lcd.clear();
  // lcd.setCursor(0,0);
  // lcd.print("Proiect PMP");
  }

}

void declanseazaAlarma() {
  for (int thisNote = 0; thisNote < 4; thisNote++) {
    int noteDuration = 1000 / alarmDurations[thisNote];
    
    tone(8, alarmMelody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(8); 
  }
}