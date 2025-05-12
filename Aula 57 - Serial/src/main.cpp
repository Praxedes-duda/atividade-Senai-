#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop()
{
  static bool piscaled = false;
  static bool estadoled = false;
  static int velocidade = 200;

  if (Serial.available())
  {
    String texto = Serial.readStringUntil('\n');
    Serial.printf("vc digital: %s\n\r", texto);
    texto.trim();

    if (texto.equals("liga"))
    {
      estadoled = true;
      piscaled = false;
    }

    else if (texto.equals("desliga"))
    {
      estadoled = false;
      piscaled = false;
    }

    else if (texto.equals("pisca"))
    {
      piscaled = true;
    }

    else if (texto.equals("rapido"))
    {
      piscaled = true;
      velocidade -= 100;
    }

    else if (texto.equals("devagar"))
    {
      piscaled = true;
      if (velocidade > 1000)
      {
        velocidade = 1000;
        Serial.println("ja esta no limite");
      }
    }
    else if (texto.startsWith("velocidade = "))
    {
      int tamanho = texto.length();
      String extracao = texto.substring(13, tamanho);
      int vel = extracao.toInt();

      if (vel >= 0 && vel <= 100)
      {
        velocidade = map(vel, 0, 100, 1000, 50);
      }
      else
      {
        Serial.println("valores aceitos somente entre o e 100")
      }
    }
    else
    {
      Serial.println("comando nao encontrado");
    }
  }
  if (piscaled == true)
  {
    unsigned long tempoatual = millis();
    static unsigned long tempoinicial = 0;

    if (tempoatual - tempoinicial >= velocidade)
    {
      estadoled = !estadoled;
      tempoinicial = tempoatual;
    }
  }

  digitalWrite(2, estadoled);
}

// void loop()
// {
//   if (Serial.available())
//   {
//     char caracter = Serial.read();
//     Serial.printf("recebido letra: %c\n\r ", caracter);

//     if(caracter == 'a')
//     {
//       digitalWrite(2, HIGH);
//     }
//     else if(caracter == 'b')
//     {
//       digitalWrite(2, LOW);
//     }
//   }

// }