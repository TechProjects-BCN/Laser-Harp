// Definir los pines de control y salida para el primer Mux
const int mux1ControlPins[] = {2, 3, 4, 5}; // Pines S0-S3 para Mux1
const int mux1OutputPin = A0; // Pin de salida analógica de Mux1

// Definir los pines de control y salida para el segundo Mux
const int mux2ControlPins[] = {6, 7, 8, 9}; // Pines S0-S3 para Mux2
const int mux2OutputPin = A1; // Pin de salida analógica de Mux2

void setup() {
  // Configurar pines de control como salida
  for (int i = 0; i < 4; i++) {
    pinMode(mux1ControlPins[i], OUTPUT);
    pinMode(mux2ControlPins[i], OUTPUT);
  }

  // Inicializar comunicación serie para mostrar valores en el Monitor Serie
  Serial.begin(9600);
}

void loop() {
  // Leer valores del primer Mux
  for (int channel = 0; channel < 16; channel++) {
    readMuxValue(mux1ControlPins, mux1OutputPin, channel);
    // Procesar el valor según sea necesario
    delay(1000); // Pausa para evitar lecturas rápidas
  }

  // Leer valores del segundo Mux
  for (int channel = 0; channel < 16; channel++) {
    readMuxValue(mux2ControlPins, mux2OutputPin, channel);
    // Procesar el valor según sea necesario
    delay(1000); // Pausa para evitar lecturas rápidas
  }
}

// Función para leer el valor analógico desde el Mux
void readMuxValue(const int controlPins[], int outputPin, int channel) {
  // Seleccionar el canal en el Mux
  for (int i = 0; i < 4; i++) {
    digitalWrite(controlPins[i], (channel >> i) & 1);
  }

  // Leer y mostrar el valor analógico
  int sensorValue = analogRead(outputPin);
  Serial.print("Canal ");
  Serial.print(channel);
  Serial.print(": ");
  Serial.println(sensorValue);
}
