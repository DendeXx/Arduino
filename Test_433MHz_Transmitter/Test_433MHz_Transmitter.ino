#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
void setup() {
  pinMode(0, OUTPUT);
  mySwitch.enableTransmit(10);  // Der Sender wird an Pin 10 angeschlossen
  mySwitch.setPulseLength(300);
}
void loop() {
  mySwitch.send(1361, 24); // 1361 für Lampe neben dem TV. 
  mySwitch.send(10380860, 24);
  mySwitch.send(10420224, 24);

  delay(4000);  // Eine Sekunde Pause, danach startet der Sketch von vorne
  mySwitch.send(1364, 24);
  mySwitch.send(5204, 24);
  mySwitch.send(9783596, 24);
  delay(4000);
}  

/* 
Dizimalcodes der einzelnen Steckdosen (jeweils AN/AUS)
TV-Stehlampe: 1361/1364
Plattenspieler-Lampe: 4433/4436
Kugellampe Erker: 5201/5204
Schreibtischlampe: 
*/
