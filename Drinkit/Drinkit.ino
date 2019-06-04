#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "0e310d6d3f984c7f90a4b0dc8f9cd2a6";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nimmerland";
char pass[] = "7Uzgl4#1";
long Gewicht = 0;

#include <HX711.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = D1;
const int LOADCELL_SCK_PIN = D2;

HX711 scale;



void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN); // Start the HX711 
  Blynk.begin(auth, ssid, pass);                    // Connect to Blynk
}

void loop() {

   Blynk.run();

  if (scale.is_ready()) {
    long reading = scale.read();
    Gewicht =scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }


Blynk.virtualWrite(V1,Gewicht);
  
 if (Gewicht > 9000) {

    Blynk.notify("Hey, Trink mal was");
  }
delay(1000);
  
  
}
