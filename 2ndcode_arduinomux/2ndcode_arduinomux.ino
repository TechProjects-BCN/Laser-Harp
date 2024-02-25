#include <Arduino.h>

// Definiciones de pines para los multiplexores
#define MUX1_S0 2
#define MUX1_S1 3
#define MUX1_S2 4
#define MUX1_S3 5
#define MUX1_OUT 0 // Pin analógico para salida del primer mux

#define MUX2_S0 6
#define MUX2_S1 7
#define MUX2_S2 8
#define MUX2_S3 9
#define MUX2_OUT 1 // Pin analógico para salida del segundo mux

#define SPEAKER_PIN 11
 // Pin para el altavoz

// Definiciones de frecuencias para cada fotoreceptor
#define NUM_SENSORS 32
float frequencies[NUM_SENSORS];

void setup() {
  pinMode(MUX1_S0, OUTPUT);
  pinMode(MUX1_S1, OUTPUT);
  pinMode(MUX1_S2, OUTPUT);
  pinMode(MUX1_S3, OUTPUT);
  pinMode(MUX2_S0, OUTPUT);
  pinMode(MUX2_S1, OUTPUT);
  pinMode(MUX2_S2, OUTPUT);
  pinMode(MUX2_S3, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  
  // Inicialización de los pines de los multiplexores
  digitalWrite(MUX1_S0, LOW);
  digitalWrite(MUX1_S1, LOW);
  digitalWrite(MUX1_S2, LOW);
  digitalWrite(MUX1_S3, LOW);
  digitalWrite(MUX2_S0, LOW);
  digitalWrite(MUX2_S1, LOW);
  digitalWrite(MUX2_S2, LOW);
  digitalWrite(MUX2_S3, LOW);

  // Inicialización de las frecuencias
  for (int i = 0; i < NUM_SENSORS; i++) {
    frequencies[i] = 100.0 + i * 100.0; // Frecuencias de 100 Hz en 100 Hz
  }
}

void loop() {
  // Escaneo de fotoreceptores
  for (int i = 0; i < NUM_SENSORS; i++) {
    float sensorValue = readSensor(i);
    if (sensorValue < 500) { // Ajusta este valor según la sensibilidad de tus fotoreceptores
      // Si el fotoreceptor está tapado, reproduce la frecuencia asociada
      tone(SPEAKER_PIN, frequencies[i]);
      while (analogRead(MUX1_OUT) < 500) {
        // Espera hasta que el sensor deje de estar tapado
      }
      noTone(SPEAKER_PIN);
    }
  }
}

float readSensor(int sensorNumber) {
  // Determina qué multiplexor y canal leer basado en el número de sensor
  int mux1Channel = sensorNumber % 16;
  int mux2Channel = sensorNumber / 16;
  
  // Configura los pines del multiplexor
  digitalWrite(MUX1_S0, mux1Channel & 0x01);
  digitalWrite(MUX1_S1, mux1Channel & 0x02);
  digitalWrite(MUX1_S2, mux1Channel & 0x04);
  digitalWrite(MUX1_S3, mux1Channel & 0x08);
  digitalWrite(MUX2_S0, mux2Channel & 0x01);
  digitalWrite(MUX2_S1, mux2Channel & 0x02);
  digitalWrite(MUX2_S2, mux2Channel & 0x04);
  digitalWrite(MUX2_S3, mux2Channel & 0x08);
  
  // Lee el valor del sensor y devuelve su valor
  int sensorValue = analogRead(MUX1_OUT);
  return sensorValue;
}