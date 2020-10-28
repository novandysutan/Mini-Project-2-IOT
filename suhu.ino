#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
int merah = 2;
int kuning = 5 ;
int hijau = 18;
int statussuhu = 0;
int button = 15;

void setup() {
  Serial.begin(9600);

  dht.begin();
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if(statussuhu == 1) {
  Serial.println("Cek Suhu");
  if(digitalRead(button) == 0){
    statussuhu = 0;
    delay(500);
  }
    long t = dht.readTemperature();
    if ( isnan(t)) {
    Serial.println("DHT sensor eror!");
    }
        Serial.print("Temperature sekarang: " );
        Serial.print(t); 
        Serial.println("*C\t");
        delay(1000);
     if ( t <= 37 ) {
      digitalWrite(merah, LOW);
      digitalWrite(kuning, LOW);
      digitalWrite(hijau, HIGH);
    }
    else  if ( t > 37 && t < 50) {
      digitalWrite(merah, LOW);
      digitalWrite(kuning, HIGH);
      digitalWrite(hijau, LOW);
    }
    else{
      digitalWrite(merah, HIGH);
      digitalWrite(kuning, LOW);
      digitalWrite(hijau, LOW); 
    }
  }else{
  Serial.println("PRESS BUTTON");
  if(digitalRead(button) == 0){
    statussuhu = 1;
    delay(500);
  }
      digitalWrite(merah, LOW);
      digitalWrite(kuning, LOW);
      digitalWrite(hijau, LOW);
      delay(1000);
  }

}
