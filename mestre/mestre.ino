#define potPin 0
#define botPin 2
#include <SoftwareSerial.h>

SoftwareSerial Arduino_escravo(10, 11);

int valPot = 0;
int intensidade = 0;

void setup() {
  Serial.begin(9600);
  Arduino_escravo.begin(9600);
}

void loop() {
  valPot = analogRead(potPin);
  Serial.println(intensidade);
  intensidade = map(valPot, 0, 1023, 0, 255);
  Serial.println(digitalRead(botPin));

  Arduino_escravo.print(String(intensidade)+";"+String(digitalRead(botPin))+";");
  //na linha acima o arduino mestre esta mandando as informaçoes do potenciometro e do botao para o arduino escravo

}
