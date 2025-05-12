/*
nome do arguivo:estruturas de decisão 
ator: maria eduarda praxedes
data:25/02/2025
*/

// C++ code
//estruturas de decisao

//****operadores de comparacao***** 

//=  atribiicao, salvar na variavel
//== verificar se dois valores sao iguais 
//!= verifica se dois valores sao diverentes
//<  verificar se eh menor 
//>  verificar se eh maior
//<= verificar se eh menor ou igual 
//>= verificar se maior ou igual 


void setup()
{
 Serial.begin(9600);
 
 int temperatura = 25;
 
 /*
 if(temperatura > 25){
 Serial.println("ta calo");
 }else{ //se nao//
 Serial.println("ta gostosinho");  
 */
   
  if (temperatura > 30){
  Serial.println("ta quante");
  }else if(temperatura <= 30 && temperatura > 24){ // se nao //
  Serial.println("ta bonsinho");
   
  }else if(temperatura <= 24 && temperatura > 18){ // se nao //
  Serial.println("ta de boa");
   
  }else{
   Serial.println("ta friozinho");
   
}
  
}

void loop()
{
  
}