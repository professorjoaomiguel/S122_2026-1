/*
 * =====================================================================
 * S122 - Internet das Coisas | Faculdade de Tecnologia SENAI
 * Bibliotecas.h - Definições Globais e Globais de Rede
 * =====================================================================
 */

#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- PINOS DO HARDWARE (EDGE) ---
#define DHTPIN 15         // Pino do DHT22
#define DHTTYPE DHT22     // Tipo do Sensor DHT
#define LDRPIN 34         // Pino Analógico do LDR
#define RELEPIN 2         // Pino do Relé / Ventoinha
#define LEDPIN 4          // LED indicador local

// --- CONFIGURAÇÕES DE REDE (TRANSPORTE) ---
extern const char* ssid;
extern const char* password;
extern const char* mqtt_server;
extern const int mqtt_port;

// --- TÓPICOS MQTT ---
extern const char* TOPIC_TELEMETRIA; // Tópico de envio
extern const char* TOPIC_COMANDO;    // Tópico de escuta (sub)

// --- OBJETOS GLOBAIS ---
extern WiFiClient espClient;
extern PubSubClient client;
extern DHT dht;
extern LiquidCrystal_I2C lcd;

// --- VARIÁVEIS GLOBAIS DE MEDIÇÃO ---
extern float temperatura;
extern float umidade;
extern int luminosidade;
extern bool estadoRele;
extern unsigned long lastSendTime;
extern const unsigned long sendInterval;

#endif
