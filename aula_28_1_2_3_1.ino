/*
autor:maria eduarda praxedes 
nome do progama: aula 28 
descricao: 
*/

#define pinLedVerde 13
#define pinLedVermelho 11
#define pinLedAzul 9


void setup()
{
   Serial.begin(9600); 
 
//*********1111*************
  
  pinMode(13, OUTPUT); 
  int temperatura = 34;
  if (temperatura > 30)
  {
  digitalWrite(pinLedVerde,HIGH);
    
	}
  
  //********22222***********
  
  pinMode(11, OUTPUT);
  int bateria = 18;
  if (bateria < 20)
  {
  digitalWrite(pinLedVermelho,HIGH);
  }
  

 //********3333*************
 
  
  int numero1 = 2; 
  int resultado = 2; 
  
  resultado = numero1 % 2; 
  pinMode(pinLedAzul, OUTPUT);
  if (resultado== 0){
  digitalWrite(pinLedAzul,HIGH);
  }
    
  
  //**********444444444**********

  int numero2 = 27; 
     
  if (numero2 >0){ 
  Serial.println("positivo");
  }else if (numero2 <0){
  Serial.println("negativo");  
  }
    
 //**********55555555***********
  
  int Salario = 950;
  if(Salario < 1000){
  Serial.println("Maria Eduarda , Auxiliar de TI, com o salario igual a: ");
   Serial.print(((Salario * 10) / 100) + Salario);
  }
  


    
//**********666666666**********
    
 int salario = 501;
 float almento = 1.3;
 int resultado1 = 0;

 if (salario >= 500){
Serial.println("nao tera reajuste");
resultado1 = salario;
 Serial.println(resultado1);
}

 if (salario < 500){
 resultado = salario * almento;
 Serial.println("o seu salario foi reajustado para ");
 Serial.println(resultado);
  }   




//*********77777777**********

int numero01 = 300;
int numero02 = 250;
  
  if (numero1 > numero2){  
  Serial.print("o numero1 e maior que o numero2");
}
if (numero02 < numero01){
Serial.print("o numero2 e menor ");
}

//***********888888*************


    int nota1 = 6;
    int nota2 = 7;
    int nota3 = 5;
    int nota4 = 8;
    float media = 0;
  
  
  media = (nota1 + nota2 + nota3 + nota4) / 4;
    Serial.println("Resultado: ");
  
  if(media >= 7){
    Serial.println("Aprovado");
  }
  
  if(media < 7 && media >= 5){
    Serial.println("Recuperacao");
  }
  
  if(media <= 5){
    Serial.println("Reprovado");
  }

}


void loop()
{
 
}