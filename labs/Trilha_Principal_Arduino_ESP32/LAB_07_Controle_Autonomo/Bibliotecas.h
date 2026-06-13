/**
 * LAB 07: Lógica de Controle e Atuadores
 * UC S122 - Internet das Coisas | SENAI Porto Alegre
 * 
 * Arquivo: Bibliotecas.h (Declaração de Pinos, Objetos e Externs)
 */

#ifndef _BIBLIOTECAS_H_
#define _BIBLIOTECAS_H_

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definições de pinos de hardware
#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34

// Atuadores adicionados neste laboratorio
#define PINO_VENTOINHA 12 // LED (Ventoinha) no pino 12
#define PINO_BUZZER 4     // Buzzer do Alarme no pino 4

// Declarações extern para objetos globais
extern DHT dht;
extern LiquidCrystal_I2C lcd;

// Declarações extern para variáveis globais de dados
extern float temp;
extern float umid;
extern int luzPerc;

#endif
