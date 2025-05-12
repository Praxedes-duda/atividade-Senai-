#include <Arduino.h>
#include <ArduinoJson.h>

JsonDocument doc;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
 if (Serial.available())
 {
  String msg = Serial.readStringUntil('\n');
  msg.trim();
  deserializeJson(doc, msg);

  float temperatura = doc ["temperatura"];
  int umidade = doc["umidade"];
  String estados = doc["estados"];

  Serial.printf("a tempratura e: %.1f \n \r", temperatura);
  Serial.printf("a umidade esta em: %d% \n \r", umidade);
  Serial.printf("o estado esta %s \n \r", estados);
  
 
 }

}