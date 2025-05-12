/*
  nome do arguivo:else if e if
  ator: maria eduarda praxedes
  data:07/03/2025
  decricao:tempo sem delay
*/

#define Vermelho 13
#define verde 12

 unsigned long tempoAtual;

 long tempoPercorrido = 0;
 long tempoPercorrido1 = 0;
 long tempovermelho = 1000;
 long tempoverde = 500;

void setup()
{
  
 Serial.begin(9600);
  
 pinMode(Vermelho, OUTPUT);
 pinMode(verde, OUTPUT);
  
  
}

void loop()
{
 
  tempoAtual = millis(); 
  
  if (tempoAtual - tempoPercorrido > tempovermelho) { 
      tempoPercorrido = tempoAtual;
      digitalWrite(verde, !digitalRead(verde));
  
  }
  
  
   if (tempoAtual - tempoPercorrido1 > tempoverde) { 
      tempoPercorrido1 = tempoAtual;
      digitalWrite(Vermelho, !digitalRead(Vermelho));
  
   } 
  
  
  
}