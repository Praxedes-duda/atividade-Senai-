#include <Arduino.h>

#define led 2
#define botao 0 


void setup()
{
    delay(5000);
    pinMode(2, OUTPUT);
    pinMode(0, INPUT_PULLUP);

    bool estadoBotao = digitalRead(0);

    while (estadoBotao = 0)
{
digitalWrite(led, HIGH);
delay(300);
digitalWrite(led, LOW);
delay(300);
}

}
\
void loop() {
 
}

