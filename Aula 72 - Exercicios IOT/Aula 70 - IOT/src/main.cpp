#include <Arduino.h>
#include <WiFi.h>

const char *SSID = "MQTT";                      // o nome da rede
const char *SENHA = "info@134";                 // define a senha da rede
const unsigned long tempoesperaconexao = 15000; // tempo de esperar a ultima conecxao
const unsigned long tempoesperareconecxao = 5000;

void conectaWiFi(void);
void checkWiFi(void);







void setup()
{
  Serial.begin(9600); // INICIA A SERIAL
}






void loop()
{
  checkWiFi();
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