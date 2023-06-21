
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
int pingreen = 11;
int pinyel = 10;
int pinred = 9;

void setup() {
  pinMode(pingreen, OUTPUT);
  pinMode(pinyel, OUTPUT);
  pinMode(pinred, OUTPUT);
  Serial.begin(9600);
  
  if (!bmp.begin()) {
    Serial.println("BMP180 Sensor nicht gefunden. Überprüfe die Verbindung!");
    while (1);
  }
}

void loop() {
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0;

  Serial.print(temperature);
  Serial.print("°C,\n");
  Serial.print(pressure);
  Serial.print("hPa\n");

  if (temperature <23){
    digitalWrite(pingreen, HIGH);
    digitalWrite(pinyel, LOW);
    digitalWrite(pinred, LOW);
  }
  else if (temperature >23 && temperature <27){
    digitalWrite(pingreen, LOW);
    digitalWrite(pinyel, HIGH);
    digitalWrite(pinred, LOW);
  }
  else{
      digitalWrite(pinyel, LOW);
      digitalWrite(pingreen, LOW);
      digitalWrite(pinred, HIGH);
  }

  delay(100);
}

      

