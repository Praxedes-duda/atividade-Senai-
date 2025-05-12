#include <Arduino.h>
#include <BluetoothSerial.h>

#define led 2

BluetoothSerial BT;

void setup()
{
  pinMode(2, OUTPUT);
  BT.begin("ESPpraxedes");
}

void loop()
{
  static bool estadoled = false;
  BT.println("oieeee");
  delay(1000);

  if (BT.available())
  {
    String mensagem = BT.readStringUntil('\n');
    mensagem.trim();

    if (mensagem.equals("liga"))
    {
      estadoled = true;
      BT.println("led ligado");
    }
    else if (mensagem.equals("desliga"))
    {
      estadoled = false;
      BT.println("led desligado");
    }
  }
  digitalWrite(2, estadoled);
}
