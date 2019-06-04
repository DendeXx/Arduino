#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  short dataPIN = 2;
  pinMode(dataPIN, INPUT);
  Serial.begin(9600);
  mySwitch.enableReceive(dataPIN);  // Receiver on D3
}

void loop() {
  Serial.println("Hallo Welt!");
  delay(2000);
  if (mySwitch.available()) {
    Serial.println(mySwitch.getReceivedValue());
    Serial.println(mySwitch.getReceivedBitlength());
    Serial.println(mySwitch.getReceivedDelay());
    //Serial.println(mySwitch.getReceivedRawdata());
    Serial.println(mySwitch.getReceivedProtocol());
    Serial.println("Hello World!");
    mySwitch.resetAvailable();
  }
}
