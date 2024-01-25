#define ledPin 9
#include <SoftwareSerial.h>

SoftwareSerial Arduino_mestre(10, 11);

int intensidade = 0;
int btn = 0;
String msg;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Arduino_mestre.begin(9600);
}

void loop() {
  if (Arduino_mestre.available()) {

    intensidade = Arduino_mestre.readStringUntil(';').toInt();
    //nesta linha ele ler o valor do potenciomentro ate o ; , em seguida trasforma de uma string para um numero inteiro
    btn = Arduino_mestre.readStringUntil(';').toInt();
    //nesta linha ele ler o valor do botao ate o ; , em seguida trasforma de uma string para um numero inteiro

    if (btn == 1) {
      analogWrite(ledPin, 255);
    } else if (intensidade < 20) {
      Serial.println("Baixa luminosidade!");
    } 

    Serial.flush();
    analogWrite(ledPin, intensidade);
    
  }
}
