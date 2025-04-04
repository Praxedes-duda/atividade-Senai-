#include <Arduino.h>  
  
void ligaLed(int pin);                           // declara os prototipos da funcoes para que o compilador entenda que elas existem
void desligaLed(int pin);
void piscaLed(int pin, unsigned long tempo);
int somaDeDoisN(int numeroA, int numeroB);

void setup()                                     //faz que o codigo faça so uma fez 
{
 pinMode(2, OUTPUT);                             // define o led como saida 
 Serial.begin(9600);                             // faz que o serial ligue 
}

void loop()                                     // faz que o codigo se repida varias vezes 
{
  piscaLed(2, 100);
  Serial.print(somaDeDoisN(4, 8));             // faz que o resultado da soma apareca no serial
}



//Criação das funções
// pq tem que colocar o void nesta funcao   
// o que é ligaLed                           
// o que eu escrevo entre os parenteses     
void ligaLed(int pin)                          //O void é usado porque a função não retorna nenhum valor  
{                                             //ligaLed é uma função que recebe algum pino e ativa o LED 
digitalWrite(pin, HIGH);                      
}

void desligaLed(int pin)                      //entre e parênteses e usado para escreve uma variável da função
{
digitalWrite(pin, LOW);
}

void piscaLed(int pin, unsigned long tempo)   // faz que o led piscar, ligando e desligando com um intervalo de tempo terteminado na funcao 
{
  ligaLed(pin);                               // faz que o led ligue e desligue 
  delay(tempo);                               
  desligaLed(pin);
  delay(tempo);
}

int somaDeDoisN(int numeroA, int numeroB)      // e uma funcao inteira com 2 funcoes inteiras dentro que retorna a soma de 2 numeros  
{
int resultado = numeroA + numeroB;
return resultado;
}