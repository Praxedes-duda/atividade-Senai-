#include <Arduino.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <ezTime.h>

const char *SSID = "SALA 10";                   // o nome da rede
const char *SENHA = "info@134";                 // define a senha da rede
const unsigned long tempoesperaconexao = 15000; // tempo de esperar a ultima conecxao
const unsigned long tempoesperareconecxao = 5000;

LiquidCrystal_I2C lcd(0x27, 20, 4);
timezone tempo;

void conectaWiFi(void);
void checkWiFi(void);

void setup()
{

  Serial.begin(9600); // INICIA A SERIAL
  conectaWiFi();
  lcd.init();
  lcd.backlight();
  wait
}

void loop()
{
  checkWiFi();

  if (WiFi.status() == WL_CONNECTED)
    tempocliente.update();
  Serial.println(tempocliente.getFormattedTime());

  delay(1000);

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println(tempo.dateTime());     // todos os dados
    Serial.println(tempo.day());          // dia
    Serial.println(tempo.month());        // mes
    Serial.println(tempo.year());         // ano
    Serial.println(tempo.hour());         // horas
    Serial.println(tempo.minute());       // minutos
    Serial.println(tempo.second());       // segundos
    Serial.println(tempo.hourFormat12()); // hora em PM AM
    Serial.println(tempo.now());          // epo time em segundos  quantos segundos desde 01/01/1970
    Serial.println(tempo.weekday());      // dia da semana domingo = 1
    Serial.println(tempo.dayOFYear());    // dia do ano
    Serial.println(tempo.isAM());         // verdadeiro caso for antes do meio dia
    Serial.println(tempo.isPM());         // verdadeiro caso for depois do meio dia
  }
}

void conectaWiFi()
{
  Serial.printf("conectando ao wifi: %s ", SSID); // MOSTRA SE ESTA CONECTADO A REDE

  WiFi.begin(SSID, SENHA); // INICIA O WIFI

  unsigned long tempoinicialwifi = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - tempoinicialwifi < tempoesperaconexao) // so sai dessa parte se estiver conectado
  {
    Serial.print(".");
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("\nWIFI CONECTADO COM SUSSECO!"); // mostra se esta conectado
    Serial.print("endereco IP: ");                   // mostra o ip do wifi
    Serial.println(WiFi.localIP());                  // mostra o local do ip
  }
}

void checkWiFi() // verifica se esta conectado
{
  unsigned long tempoatual = millis();         // mostra o temppo atual
  static unsigned long tempoultimaconexao = 0; // mostra  o  tempo da ultima atualizacao

  if (tempoatual - tempoultimaconexao > tempoesperaconexao) // verifica se passou o tempo
  {

    if (WiFi.status() != WL_CONNECTED)
    {
      Serial.println("\n conecxao PERDIDA! tentando reconectar.....");
      conectaWiFi();
    }
    tempoultimaconexao = tempoatual;
  }
}