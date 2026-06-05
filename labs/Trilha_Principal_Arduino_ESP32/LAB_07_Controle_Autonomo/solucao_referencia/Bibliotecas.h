/**
 * LAB 07: Lógica de Controle e Atuadores (GABARITO / SOLUÇÃO DE REFERÊNCIA)
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

// Atuadores
#define PINO_VENTOINHA 11
#define PINO_BUZZER 8

// Declarações extern para objetos globais
extern DHT dht;
extern LiquidCrystal_I2C lcd;

// Declarações extern para variáveis globais de dados
extern float temp;
extern float umid;
extern int luzPerc;

#endif
