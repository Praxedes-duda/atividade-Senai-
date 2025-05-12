/*
nome do arguivo:estruturas de decisão 
ator: maria eduarda praxedes
data:26/02/2025
*/

void setup()
{
 Serial.begin(9600);
  
 int peso = 80;
 float altura = 1.65;
 float resultado = 0;
 float resultadoimc = 0;
  
 
  resultado = altura*2 ;
   //criar a variavel que vai guardar o resultado
   //colocar o valor dentro da variavel
   //variavel = oq eu quero guardar
  
 /*resultadoimc = peso / resultado;
 Serial.print(resultadoimc);
}


  resultadoimc = peso / sq(altura);
  Serial.println(IMC);*/
   
   if(resultadoimc < 17){
    Serial.println("Muito baixo do ideal");

  }else if(resultadoimc >= 17 && resultadoimc < 18.49){
    Serial.println("Abaixo do peso");
    
  }else if(resultadoimc >= 18.5 && resultadoimc < 24.99){
    Serial.println("Peso normal");
     
    }else if(resultadoimc >= 25.00 && resultadoimc < 29.99){
    Serial.println("Peso normal");
  
  }else if(resultadoimc >= 30 && resultadoimc < 34.99){
     Serial.println("Obesidade grau 1");
    
  }else if(resultadoimc >= 35 && resultadoimc < 36.99){
    Serial.println("Obesidade grau 2");
    
  }else if(resultadoimc > 40){
    Serial.println("Obesidade grau 3");
  }
}
void loop()
{
  
}