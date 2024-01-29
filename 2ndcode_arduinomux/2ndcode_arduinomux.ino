// Definir pines de control y salida para el primer Mux
const int mux1ControlPins[] = {2, 3, 4, 5}; // Pines S0-S3 para Mux1
const int mux1OutputPin = A0; // Pin de salida analógica de Mux1

// Definir pines de control y salida para el segundo Mux
const int mux2ControlPins[] = {6, 7, 8, 9}; // Pines S0-S3 para Mux2
const int mux2OutputPin = A1; // Pin de salida analógica de Mux2

// Definir pines para el láser y el micrófono
const int laserPin = 10; // Pin digital para el láser
const int micPin = A2;   // Pin analógico para el micrófono

void setup() {
  // Configurar pines de control como salida
  for (int i = 0; i < 4; i++) {
    pinMode(mux1ControlPins[i], OUTPUT);
    pinMode(mux2ControlPins[i], OUTPUT);
  }

  // Configurar pines de láser y micrófono
  pinMode(laserPin, OUTPUT);
  pinMode(micPin, INPUT);

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

  // Leer el valor analógico
  int sensorValue = analogRead(outputPin);

  // Activar el láser si el valor supera un umbral (puedes ajustar el umbral según sea necesario)
  if (sensorValue > 500) {
    digitalWrite(laserPin, HIGH);
    
    // Leer el valor del micrófono
    int micValue = analogRead(micPin);
    
    // Si el valor del micrófono supera un umbral, activar el sonido
    if (micValue > 200) {
      // Activar el sonido (puedes usar un módulo de sonido o un buzzer aquí)
      // Ejemplo: activarSonido();
      Serial.println("Sonido activado");
    }
    
    // Esperar un breve periodo de tiempo antes de desactivar el láser
    delay(500);
    digitalWrite(laserPin, LOW);
  }
}