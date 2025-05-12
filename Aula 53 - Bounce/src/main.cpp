#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define botaoa 18
#define botaob 19
#define botaoc 23
#define pinled1 15
#define pinled2 2
#define pinled3 4
#define pinled4 5

Bounce botao1 = Bounce();
Bounce botao2 = Bounce();
Bounce botao3 = Bounce();

void setup()
{
  Serial.begin(9600);
  botao1.attach(botaoa, INPUT_PULLUP);
  botao2.attach(botaob, INPUT_PULLUP);
  botao3.attach(botaoc, INPUT_PULLUP);

  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
  pinMode(pinled4, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(">led 1 - 0");
  lcd.setCursor(0, 1);
  lcd.print(" led 2 - 0");
  lcd.setCursor(0, 2);
  lcd.print(" led 3 - 0");
  lcd.setCursor(0, 3);
  lcd.print(" led 4 - 0");
}

void loop()
{
  static bool selecao = 1;
  static int contador = 0;
  static int intledA = 0;
  static int intledB = 0;
  static int intledC = 0;
  static int intledD = 0;

  botao1.update();
  botao2.update();
  botao3.update();

  // botao c

  if (botao3.fell())
  {
    selecao = !selecao;
  }

  // botao b

  if (botao2.fell())
  {
    if (selecao)
    {
      contador++;

      if (contador > 3)
      {
        contador = 0;
      }
    }
  }
  else
  {
    switch (contador)
    {
    case 0:

      if (intledA > 0)
        intledA -= 10;
      break;

    case 1:

      if (intledB > 0)
        intledB -= 10;
      break;

    case 2:

      if (intledC > 0)
        intledC -= 10;
      break;

    case 3:

      if (intledD > 0)
        intledD -= 10;
      break;

    default:
      break;
    }
  }

  // botao a

  if (botao1.fell())
  {
    if (selecao)
    {
      contador--;

      if (contador < 0)
      {
        contador = 3;
      }
    }
  }
  else
  {
    switch (contador)
    {
    case 0:

      if (intledA <= 90)
        intledA += 10;
      break;

    case 1:

      if (intledB <= 90)
        intledB += 10;
      break;

    case 2:

      if (intledC <= 90)
        intledC += 10;
      break;

    case 3:

      if (intledD <= 90)
        intledD += 10;
      break;

    default:
      break;
    }
  }

  //                                                                   !LCD

  if (contador == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print(">");

    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(" ");

    lcd.setCursor(10, 0);
    lcd.print(pinled1);
  }
  else if (contador == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print(">");

    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.setCursor(0, 2);
    lcd.print(" ");

     lcd.setCursor(10, 0);
    lcd.print(pinled2);
  }
  else if (contador == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");

    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(" ");

     lcd.setCursor(10, 0);
    lcd.print(pinled3);
  }
  else
  {
    lcd.setCursor(0, 3);
    lcd.print(">");

    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 0);
    lcd.print(" ");

     lcd.setCursor(10, 0);
    lcd.print(pinled4);
  }
}