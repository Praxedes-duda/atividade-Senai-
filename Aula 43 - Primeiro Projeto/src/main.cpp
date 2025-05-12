#include <Arduino.h>
#define pinLed 2
#define botao 19

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  bool estadoatualbotao = digitalRead(botao);
  static bool estadoanteriorbotao = 1; 
  static bool ultimaacao = 1;

  static unsigned long tempoulatimaalteracao = 0; 
  unsigned long tempoatual = millis(); 
  const unsigned long tempofiltro = 50;

  static int contagem = 0; 
  
  //! inicia o tratamento de ruido do botao 

  //*detecta mudanca no estado do botao 
  if(estadoatualbotao != estadoanteriorbotao)
  {
    tempoulatimaalteracao = tempoatual; //* atualiza o tempo da ultima mudanca 
  }
  //* verifica se o novo estado se manteve estavel por tempo suficiente 
  if((tempoatual - tempoulatimaalteracao) > tempofiltro)
  {
//* verifica se ainda nao processamos essa nova acao 
if (estadoatualbotao != ultimaacao)
{
ultimaacao = estadoatualbotao;
//*se o botao foi pressionado nivel logico low 
if(!estadoatualbotao)
{
  contagem++;
  Serial.println(contagem);
}
//* se o botao foi solto nivel logico HIGH, nemhuma acao por enquanto 
else 
{

}
}
//*Atualizacao o estado anterior para a proxima iteracao
estadoanteriorbotao = estadoatualbotao;

   }
}