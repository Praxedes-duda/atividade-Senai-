/*
  nome do arguivo:else if e if
  ator: maria eduarda praxedes
  data:06/03/2025
  decricao:mais detalhes do if 
*/

#define pinLedVermelho 13
#define pinLedLaranja  12
#define pinLedAmarelo  11
#define pinLedVerde    7
#define pinLedAzul     4


void setup()
{
  Serial.begin(9600);
  
 pinMode(pinLedVermelho, OUTPUT);
 pinMode(pinLedLaranja,  OUTPUT);
 pinMode(pinLedAmarelo,  OUTPUT); 
 pinMode(pinLedVerde,    OUTPUT);   
 pinMode(pinLedAzul,     OUTPUT); 
  
 int ar = 4;
   
 switch (ar)  
 
 { 
   
 case 0: 
 digitalWrite(pinLedVermelho, HIGH); 
 Serial.println("bem ruim");
 break;
 case 1: 
 digitalWrite(pinLedLaranja,  HIGH);  
 Serial.println("ruim");
 break;
 case 2: 
 digitalWrite(pinLedAmarelo,  HIGH);
 Serial.println("+/-");
 break;  
 case 3:
 digitalWrite(pinLedVerde,    HIGH);
 Serial.println("bom");
 break;  
 case 4:
 digitalWrite(pinLedAzul,     HIGH); 
 Serial.println("muito bom");
 break;
  
 default: 
 digitalWrite(pinLedVermelho, LOW); 
 digitalWrite(pinLedLaranja,  LOW); 
 digitalWrite(pinLedAmarelo,  LOW);   
 digitalWrite(pinLedVerde,    LOW); 
 digitalWrite(pinLedAzul,     LOW); 
 
 break;  
 
 }
  
}

void loop()
{
  
  
}