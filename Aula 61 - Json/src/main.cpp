#include <Arduino.h>
#include <ArduinoJson.h>
#include <Bounce2.h>
#define pinbotao 0

Bounce botaoboot = Bounce();
JsonDocument doc;

void setup()
{
  Serial.begin(9600);
  // Serial.println("");
  botaoboot.attach(pinbotao, INPUT_PULLUP);
  randomSeed(analogRead(5));
}

void loop()
{
  botaoboot.update();
  
  static int contagem = 0;

  if (botaoboot.fell())
  {
    contagem++;
  }
  const char *estados[] = {"ok", "alerta", "erro"};

  float temperatura = random(200, 350) / 10.0;
  int umidade = random(40, 80);
  int opcoes = random(0, 3);

  doc["temperatura"] = temperatura;
  doc["umidade"] = umidade;
  doc["estados"] = estados[opcoes];
  doc["pressionamento"] = contagem;

  unsigned long tempoatual = millis();
  static unsigned long tempoinicial = 0;

  if (tempoatual - tempoinicial > 5000)
  {
    serializeJson(doc, Serial);
    Serial.println("");
    tempoinicial = tempoatual;
  }
}
