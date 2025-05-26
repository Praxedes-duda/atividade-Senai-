#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

class temporizador
{
    
private:
    unsigned long intervalo;
    unsigned long novoIntervalo;
    unsigned long ultimoTempo;
    

public:
    temporizador(unsigned long tempo_ms = 1000);
    bool pronto();
    void iniciar();
    void reiniciar();
    void definirIntervalo(unsigned long tempo_ms);
    
};

#endif