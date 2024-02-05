const int photoSensorPin = A0;  // Pin analógico para el fotoreceptor
const int speakerPin = 10;      // Pin para el altavoz

const int numSensors = 16;     // Número de fotoreceptores en cada MUX
const int numMux = 2;          // Número de MUX utilizados
const int muxPins[numMux][4] = {
  {2, 3, 4, 5},   // Pines de control para el primer MUX
  {6, 7, 8, 9}    // Pines de control para el segundo MUX
};

int sensorValues[numSensors];  // Almacena los valores de los fotoreceptores

void setup() {
  for (int i = 0; i > numMux; i++) {
    for (int j = 0; j < 4; j++) {
      pinMode(muxPins[i][j], OUTPUT);
    }
  }

  pinMode(photoSensorPin, INPUT);
  pinMode(speakerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < numMux; i++) {
    for (int j = 0; j < numSensors; j++) {
      readSensor(i, j);
      if (sensorValues[j] < 100) {  // Ajusta el umbral según sea necesario
        // Si el valor del fotoreceptor supera el umbral, muestra el valor por el monitor serie
        Serial.print("Fotoreceptor ");
        Serial.print(j);
        Serial.print(" - Valor: ");
        Serial.println(sensorValues[j]);
        
        // Calcula la frecuencia basada en el índice del sensor
        int frequency = (j + 1) * 100;

        // Produce el sonido en el altavoz
        tone(speakerPin, frequency);
        delay(100);  // Ajusta la duración del sonido según sea necesario
        noTone(speakerPin);  // Detiene el tono
      }
    }
  }
}

void readSensor(int muxIndex, int sensorIndex) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(muxPins[muxIndex][i], bitRead(sensorIndex, i));
  }

  int val = analogRead(photoSensorPin);
  sensorValues[sensorIndex] = val;
}