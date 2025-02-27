/*
  nome do arguivo:exercicios 2 e 3 
  ator: maria eduarda praxedes
  data:25/02/2025
  decricao:

*/
int numeroA = 271;
int numeroB = 0;
int resultado = 0;
float resultadoReal = 0;

void setup()
{
 
  
  Serial.begin(9600);
  resultado = map(numeroA, 0, 1023, 0, 100); 
  Serial.println(resultado);
  
  resultado = constrain(resultado, 20, 80);
  Serial.println(resultado);
  
  
  
  numeroB +=1;
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB +=1; 
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
  
  numeroB -=1;
  Serial.println(numeroB);
  
}

void loop()
{
 
}
