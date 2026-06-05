/**
 * LAB 06: Comunicação I2C e Fatiamento M3F (GABARITO / SOLUÇÃO DE REFERÊNCIA)
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo: Bibliotecas.h (Declaração de Pinos, Objetos e Externs)
 */

#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definições de pinos de hardware
#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34
#define PINO_LED_ALERTA 12 // LED de Alerta do Desafio (Vermelho)

// Declarações extern para objetos globais (compartilhados entre as abas)
extern DHT dht;
extern LiquidCrystal_I2C lcd;

// Declarações extern para variáveis globais de dados
extern float temp;
extern float umid;
extern int luzPerc;

#endif
