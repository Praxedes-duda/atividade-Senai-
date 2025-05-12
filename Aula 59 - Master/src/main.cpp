#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;

uint8_t endSlave[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};   //endereco do dispositivo a ser conectado

void setup()
{
  Serial.begin(9600); // inicia a Serial.

  //!                   ↓ indica que eh master
  if (BT.begin("ESPpraxedes", true)) // inicia a conecxao bluetooth
  {
    Serial.println("Bluetooth iniciado c0m sucesso!");
  }
  else
  {
    Serial.println("Erro na inicializacao do Bluetooth!");
  }

  if (BT.connect(endSlave))  //conecta ao dispositivo
  {
    Serial.println("conectado com sucesso!");
  }
  else
  {
    Serial.println("nao foi possivel conectar ao dispositivo");
  }
}

void loop()
{
  if (Serial.available())
  {
    String mensagemEnviar = Serial.readStringUntil('\n'); // le a serial ate encontrar um enter
    mensagemEnviar.trim();                                // tira os espacos 
    BT.println(mensagemEnviar);                           //pega a mensagem e joga no blut do coleguinha 
  }
  if (BT.available())
  {
    String mensagemRecebida = BT.readStringUntil('\n');
    mensagemRecebida.trim();
    Serial.println("mensagem recebida: " + mensagemRecebida);

    if (mensagemRecebida.equals("liga"))
    {
      /* code */
    }
    else if (mensagemRecebida.equals("desliga"))
    {
      /* code */
    }
    
  }
  
}