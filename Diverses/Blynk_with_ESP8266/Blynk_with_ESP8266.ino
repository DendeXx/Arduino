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

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

Blynk.virtualWrite(V1, "abc"); 
  
}
