#include <Arduino.h>
#define led 2

float polegadas(float);
float formula(float);
int hipotenusa(int cateto1, int cateto2);
float tamanhotv(float, float);

void setup()
{
  Serial.begin(9600);
  //  int hipotenu = hipotenusa(3,4);
  //  Serial.print(hipotenu);
  //  pinMode(2, OUTPUT);
  //  float conta = formula(50);
  //  Serial.println(conta);
  Serial.print(polegadas(50));
}

void loop()
{
}
int hipotenusa(int cateto1, int cateto2)
{
  int resultado = sq(cateto1) + sq(cateto2);
  return sqrt(resultado);
}
float formula(float graus)
{
  float fahrenheit = ((graus * 9 / 5) + 32);
  return fahrenheit;
}

float polegadas(float milimetros)
{

  float polegadas = milimetros / 25.4;
  return polegadas;
}
float tamamanhotv( float altura)
{
  float resultado = sq(tamamanhotv(50)) - sq(altura);
  return sqrt(polegadas);
}