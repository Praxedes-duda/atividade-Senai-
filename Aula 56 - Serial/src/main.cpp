#include <Arduino.h>

char palavra[10] = "ola mundo";
char palavra2[10] = {'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o', '\0'};

String palavra3 = "hoje eh quinta";

void setup()
{
  Serial.begin(9600);
  Serial.println();

  Serial.println(palavra);
  Serial.println(palavra2);

  strcpy(palavra, "senai");

  if (strcmp(palavra, "senai") == 0)
  {
    Serial.print("sao iguais");
  }
  if (strncmp(palavra2, "ola", 3) == 0)
  {
    Serial.println("as primeiras latras da palavras e ola");
  }
  if (strstr(palavra2, "mundo"))
  {
    Serial.println("palavra mundo detectada");
  }

  Serial.println(palavra3.length());         // retorna o numaro de letras do objeto da classe String
  Serial.println(palavra3.charAt(8));        // retorna a oitava letra da palavra
  Serial.println(palavra3.substring(8, 14)); // retorna a 8 ate a 14 posicao
  Serial.println(palavra3.indexOf('u'));     // retorna a primeira letra
  Serial.println(palavra3.lastIndexOf('e')); // retorna a ultima letra

  if (palavra3.equals("hoje eh quinta") == 1) // retorna verdadeiro se forem iguais ignorando letras maiusculas e minusculas
    Serial.println("sao iguais");

  if (palavra3.startsWith("hoje") == 1) // retorna verdadeiro se a palavra comeca com determinado texto
    Serial.println("comeca com hoje");

  if (palavra3.endsWith("inta") == 1) // retorna verdadeiro sev a palavra terminar com determinado texto
    Serial.println("termina com inta");

  String valor = "123";
  int valornumerico = valor.toInt(); // converte o valor do texto em valor numerico de "123" para 123 (numero)

  String valor2 = "10.5";
  float valornumerico2 = valor2.toFloat();

  String mensagem = "valor = 50";              
  int tamanho = mensagem.length();  // medir o tamanho do texto
  String extracao = mensagem.substring(8, tamanho);  //extrair  o numero iniciado em uma posicao conhecida ate o fim do texto

  Serial.println(tamanho);
  Serial.println(extracao);

  int numero = extracao.toInt(); //transfprme o conteudo extraido em um numero inteiro 
  Serial.println(numero * 2);  //utilize o numero sem moderacao ... hahahahahahhahahahahhaahahahahahaha

  palavra3.toLowerCase();  //altera todas as letras para minusculas 
  Serial.println(palavra3); 
  palavra3.toUpperCase(); // altera todas pra maiuscula 
  Serial.println(palavra3); 

  String textoled = "led = on ";
  Serial.println(textoled);
  textoled.replace("on", "off"); // substitui uma palavra no texto por outra 
  Serial.println(textoled);  // led = off

  String novafrase = "texto        "; // varios espacos 
  novafrase.trim();  // remove os espacos do fim do texto

  novafrase.concat("adicionado"); //adisiona um texto a sting
  Serial.println(novafrase);

}

void loop()
{
}