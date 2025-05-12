#include <Arduino.h>
#include <ezTime.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

const char *SSID = "SALA 09";                   // o nome da rede
const char *SENHA = "info@134";                 // define a senha da rede
const unsigned long tempoesperaconexao = 15000; // tempo de esperar a ultima conecxao
const unsigned long tempoesperareconecxao = 5000;

LiquidCrystal_I2C lcd(0x27, 20, 4);
Timezone Tempo;

void conectaWiFi(void);
void checkWiFi(void);

void setup()
{

  Serial.begin(9600); // INICIA A SERIAL
  conectaWiFi();
  lcd.init();
  lcd.backlight();
  conectaWiFi();
  Tempo.setLocation("America/Sao_Paulo");
  waitForSync();
}

void loop()
{
  checkWiFi();
  /*
    if (WiFi.status() == WL_CONNECTED)
      tempocliente.update();
    Serial.println(tempocliente.getFormattedTime());
  */

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println(Tempo.dateTime());     // todos os dados
    Serial.println(Tempo.day());          // dia
    Serial.println(Tempo.month());        // mes
    Serial.println(Tempo.year());         // ano
    Serial.println(Tempo.hour());         // horas
    Serial.println(Tempo.minute());       // minutos
    Serial.println(Tempo.second());       // segundos
    Serial.println(Tempo.hourFormat12()); // hora em PM AM
    Serial.println(Tempo.now());          // epo time em segundos  quantos segundos desde 01/01/1970
    Serial.println(Tempo.weekday());      // dia da semana domingo = 1
    Serial.println(Tempo.dayOfYear());    // dia do ano
    Serial.println(Tempo.isAM());         // verdadeiro caso for antes do meio dia
    Serial.println(Tempo.isPM());         // verdadeiro caso for depois do meio dia
  }

  delay(1000);
  lcd.setCursor(8, 0);
  lcd.print("/");
  lcd.setCursor(9, 0);
  lcd.print(Tempo.month());

  lcd.setCursor(10, 0);
  lcd.print("/");
  lcd.print(Tempo.year());

  if (Tempo.day() < 10)
  {
    lcd.setCursor(0, 0);
    lcd.print("hj eh:");
    lcd.print("0");
    lcd.print(Tempo.day());
  }

  else
  {
    lcd.setCursor(0, 0);
    lcd.print("hj eh:");
    lcd.print(Tempo.day());
    lcd.print("/");
  }

  lcd.setCursor(0, 1);
  lcd.print("agora sao:");

  if (Tempo.hour() < 10)
  {
    lcd.print("0");
  }
  lcd.print(Tempo.hour());
  lcd.print(":");

  if (Tempo.minute() < 10)
  {
    lcd.print("0");
  }
  lcd.print(Tempo.minute());
  lcd.print(":");

  if (Tempo.second() < 10)
  {
    lcd.print("0");
  }
  lcd.print(Tempo.second());

  lcd.setCursor(0, 2);
  lcd.print("hj eh:");
  lcd.print(Tempo.weekday());

  lcd.setCursor(0, 3);
  if (WiFi.status() == WL_CONNECTED)
  {
    lcd.print("WiFi:Conectado ");
  }
  else
  {
    lcd.print("WiFi:Desconectado tente novamente");
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