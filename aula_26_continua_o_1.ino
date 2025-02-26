/*
  nome do arguivo:exercicios 1
  ator: maria eduarda praxedes
  data:25/02/2025
  decricao:

*/
void setup()
{
Serial.begin(9600);
 int resultado = map(2712, 0, 1023, 0, 100);
 resultado = constrain(resultado, 20, 80);
 Serial.println(resultado);
}

void loop()
{
  
}