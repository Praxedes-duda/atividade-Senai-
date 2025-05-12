/*
  nome do arguivo:matematica
  ator: maria eduarda praxedes
  data:24/02/2025
  decricao:

*/

int numeroA = 10;
int numeroB = 3;
int resultado = 0; 
float resultadoReal = 0;
  
  void setup()
{
  Serial.begin(9600); //baud rete bot's por segundo (bps)
    
    
  //*****SOMA*****
    resultado = numeroA + numeroB;
    Serial.print("a soma do numeroA com o numeroB eh: ");
    Serial.println(resultado);
    
    //*****subtração****
     resultado = numeroB - numeroA;
     Serial.print("a subtracao de numero b pelo a eh: ");
     Serial.println(resultado);
    
     //*****multiplicacao*******
    resultado = numeroA * numeroB;
    Serial.print("a meltiplicacao do numero a pelo numero b eh:");
    Serial.println(resultado);
    
    //****divisao*******
    
    resultado = numeroA / numeroB;
    Serial.print("a divisao de A por B eh: ");
    Serial.println(resultado);
    resultado = numeroA % numeroB; // retorna o resto da divisao 
    Serial.print("e sobra ");
    Serial.println(resultado);
    
   //divisao com numeros decimais 
    
   resultadoReal = (float)numeroA / (float)numeroB;
   Serial.println(resultadoReal,1); //mostra apenas uma casa decimal 
   
    
   //*****potenciacao********
    
    resultadoReal = pow(numeroA, numeroB); // nemeroA elevado a numeroA
    Serial.print("numero A elevado a numero B: ");
    Serial.println(resultadoReal,0); //sem casas decimais 
    
    //*****ao quadrado********
    
    resultado = sq(numeroB); //square (quadrado)
    Serial.print("numeroB ao quadrado: ");
    Serial.println(resultado); 
    
    //******raiz quadrada*****
    
    resultadoReal = sqrt(numeroA); //square root (raiz quadrada)
    Serial.print("a raiz quadrada de numeroA");
    Serial.println(resultadoReal);
    
    //********modulo*******
    
    resultado = abs(numeroA * -1);
    Serial.println(resultado);
    
    //*****restricao******
    
    resultado = constrain(numeroA, 4, 8);
    Serial.println(resultado);
    resultado = constrain(numeroB,4, 8);
    Serial.println(resultado);
    resultado = constrain(numeroA, 0, 100); // dento do limite 
    Serial.println(resultado);
      
    //******remapeamento********
      
     resultado = map(511, 0, 1023, 0, 100);
    //map(valor,deMenor,deMaior,paraMenor,paraMaior);
    Serial.println(resultado);
    
    
    //*****operadores de atribuicao****
    
    
    //incremento (+1)
    // numeroA = numeroA +1;
    numeroA++; //pos incremento 
    ++numeroA; //pre incremento8ijn 
    
    int valor =1;
    Serial.println(valor++);
    Serial.println(valor);
    
    //****decretamento*****
    
    numeroA--;
    --numeroA;
      
    //numeroA = numeroA + 3;
    numeroA += 3;
      
    //numeroA = numeroA - 3;  
    numeroA -= 3; 
    
    //numeroA = numeroA * 3;
     numeroA *= 3;
    
    //numeroA = numeroA / 5;
    numeroA /= 5;
}