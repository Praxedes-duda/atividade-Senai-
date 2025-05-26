#include <Arduino.h>
#include "temporizador.h"

temporizador::temporizador(unsigned long tempo_ms)
{
    intervalo = tempo_ms;
}

void temporizador::iniciar()
{
    ultimoTempo = millis();
    Serial.println("Temporizador Iniciado com sucesso");
}

bool temporizador::pronto()
{
    unsigned long agora = millis();
    if (agora - ultimoTempo >= intervalo)
    {
        ultimoTempo = agora;
        return true;
    }
    return false;
}

void temporizador::reiniciar()
{
    ultimoTempo = millis();
}

void temporizador::definirIntervalo(unsigned long tempo_ms)
{
    intervalo = novoIntervalo;
}