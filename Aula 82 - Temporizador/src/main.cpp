#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "temporizador.h"

int contador = 0;

const int mqtt_port = 1883;
const char *mqtt_server = "Broker.hivemq.com";
const char *mqtt_client_id = "NoMe_Do_MeU_EsP9o";
const char *mqtt_topic_sub = "senai134/mesa02/praxedes/espsub";
const char *mqtt_topic_pub = "senai134/mesa02/praxedes/esppub";

WiFiClient espClient;
PubSubClient client(espClient);
temporizador temp(1000);

void setup()
{
    Serial.begin(9600);
    temp.iniciar();
}

void loop()
{

     client.loop();

     if (temp.pronto())
     {
         String mensagem = "Mensagem número " + String(contador++);
         client.publish("esp32/cronometro", mensagem.c_str());
         Serial.println("Enviado: " + mensagem);
     }
}
