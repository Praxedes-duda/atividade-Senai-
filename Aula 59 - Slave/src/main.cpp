#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;

void setup()
 {
Serial.begin(9600);
pinMode(2, OUTPUT);
 
  if (BT.begin("ESPpraxedes"))
{
  Serial.println("iniciado com iniciado com sucesso");
  Serial.println(BT.getBtAddressString());
}
else
{
  Serial.println("erro ao conectar");
}
 }
void loop()
{
  static bool piscaLed = false;
  static bool estadoLed = false;
  static int Velocidade = 200;

  if (Serial.available())
  {
    String mensagemEnviar = Serial.readStringUntil('\n'); // ler a Serial ate encontrar um enter
    mensagemEnviar.trim();                                // tratamento da msm
    BT.println(mensagemEnviar);                           // enviar a msm ao bluetooth
  }

  if (BT.available())
  {
    String mensagemRecebida = BT.readStringUntil('\n');      // ler os caracteres recebidos no bluettoth ate encontrar um enter
    mensagemRecebida.trim();                                 // tratar a mensagem
    Serial.println("Mensagem recebida " + mensagemRecebida); // enviar ao serial que recebeu a msm

    if (mensagemRecebida.equals("liga"))
    {
      estadoLed = true;
      piscaLed = false;
    }
    else if (mensagemRecebida.equals("desliga"))
    {
      estadoLed = false;
      piscaLed = false;
    }
    else if (mensagemRecebida.equals("pisca"))
    {
      piscaLed = true;
    }
    else
    {
      Serial.println("Comando Nao Encontrado");
    }
  }

  if (piscaLed == true)
  {
    unsigned long tempoAtual = millis();
    static unsigned long tempoInicial = 0;

    if (tempoAtual - tempoInicial >= Velocidade)
    {
      estadoLed = !estadoLed;
      tempoInicial = tempoAtual;
    }
  }

  digitalWrite(2, estadoLed);
}
