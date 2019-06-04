#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

/*
  Humidity and Temperature Sensors with Lamp for Paintcabine

*/

int Temperatur = 0;
int Feuchtigkeit = 0;
int RoteLED = 2;
int GrueneLED = 3;
int RoterMerker = 0;
int GruenerMerker = 0;
int ROT=0;


dht DHT;

#define DHT11_PIN A0

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {

  pinMode(RoteLED, OUTPUT);
  pinMode(GrueneLED, OUTPUT);

  lcd.begin();
  Serial.begin(9600);
  
}

void loop() {

    DHT.read11(DHT11_PIN);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print(" %");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println(" C"); 

  Feuchtigkeit= DHT.humidity;
  Temperatur= DHT.temperature;
  
    lcd.backlight();
    lcd.setCursor (0,0);
    lcd.print("Feuchte:");
    lcd.setCursor (9,0);
    lcd.print(DHT.humidity);
    lcd.setCursor (15,0);
    lcd.print("%");   

    lcd.backlight();
    lcd.setCursor (0,1);
    lcd.print("Temperatur:");
    lcd.setCursor (12,1);
    lcd.print(DHT.temperature);
    lcd.setCursor (18,1);
    lcd.print("C");

    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print(" %");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println(" C"); 
  
if (Feuchtigkeit > 52.00)
{
      lcd.setCursor(1,2);
      lcd.print("Feuchte zu hoch!");
      digitalWrite(GrueneLED, LOW);
      if( digitalRead(RoteLED)!=HIGH);
      {
        digitalWrite(RoteLED, HIGH);
      }
}

if (Feuchtigkeit < 52.00)
{
      lcd.setCursor(1,2);
      lcd.print("Feuchte ist ok!");
      digitalWrite(RoteLED, LOW);
      if( digitalRead(GrueneLED)!=HIGH);
      {
        digitalWrite(GrueneLED, HIGH);
      }
} 
 Serial.println("RoteLED:");
 Serial.println(digitalRead(RoteLED));
 Serial.println("GrueneLED:"); 
 Serial.println(digitalRead(GrueneLED));

 delay (2000);
}

