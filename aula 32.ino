/*
  nome do arguivo:aula 32
  ator: maria eduarda praxedes
  data:10/03/2025
  decricao:tempo sem delay
*/


#define pinLedVerde 3
#define pinLedAmarelo 7
#define pinLedVermelho  11

unsigned long tempoAnterior = 0; 
int estadoSemaforo = 0;          

void setup() {
    pinMode(pinLedVermelho, OUTPUT);
    pinMode(pinLedVerde, OUTPUT);
    pinMode(pinLedAmarelo, OUTPUT);
}

void loop() {
    unsigned long tempoAtual = millis();  
    
    switch (estadoSemaforo) {
      
     case 0: 
     
     if (tempoAtual - tempoAnterior >= 5000) {
         digitalWrite(pinLedVermelho, LOW);
         digitalWrite(pinLedVerde, HIGH);
         estadoSemaforo = 1;
         tempoAnterior = tempoAtual;
    } else {
         digitalWrite(pinLedVermelho, HIGH);
         digitalWrite(pinLedVerde, LOW);
         digitalWrite(pinLedAmarelo, LOW);
}
      break;

       case 1: 
      
       if (tempoAtual - tempoAnterior >= 5000) {
          digitalWrite(pinLedVerde, LOW);
          digitalWrite(pinLedAmarelo, HIGH);
          estadoSemaforo = 2;
          tempoAnterior = tempoAtual;
         
            }
        break;

        case 2: 
      
       if (tempoAtual - tempoAnterior >= 2000) {
           digitalWrite(pinLedAmarelo, LOW);
           digitalWrite(pinLedVermelho, HIGH);
           estadoSemaforo = 0;
           tempoAnterior = tempoAtual;
         
         
            }
      
            break;
    }
}