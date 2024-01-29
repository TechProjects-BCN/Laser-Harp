const int altavozPin = 9; // El pin al que está conectado el altavoz
const int fotoPin = A0;  // Pin analógico donde está conectado el fotorresistor
const int fotoPin2 = A1;
const int fotoPin3 = A2;
const int fotoPin4 = A3;
const int fotoPin5 = A4;
const int fotoPin6 = A5;
const int fotoPin7 = A6;
const int fotoPin8 = A7;
const int fotoPin9 = A8;
const int fotoPin10 = A9;
const int fotoPin11 = A10;
const int fotoPin12 = A11;
const int fotoPin13 = A12;
const int fotoPin14 = A13;
const int fotoPin15 = A14;
const int fotoPin16 = A15;
void setup() {
  
  Serial.begin(9600);
}

void loop() {
  int valorLuz = analogRead(fotoPin);  // Lee el valor analógico del fotorresistor
  int valorLuz2 = analogRead(fotoPin2);
  int valorLuz3 = analogRead(fotoPin3);
  int valorLuz4 = analogRead(fotoPin4);
  int valorLuz5 = analogRead(fotoPin5);
  int valorLuz6 = analogRead(fotoPin6);
  int valorLuz7 = analogRead(fotoPin7);
  int valorLuz8 = analogRead(fotoPin8);
  int valorLuz9 = analogRead(fotoPin9);
  int valorLuz10 = analogRead(fotoPin10);
  int valorLuz11 = analogRead(fotoPin11);
  int valorLuz12 = analogRead(fotoPin12);
  int valorLuz13 = analogRead(fotoPin13);
  int valorLuz14 = analogRead(fotoPin14);
  int valorLuz15 = analogRead(fotoPin15);
  int valorLuz16 = analogRead(fotoPin16);



  Serial.println(valorLuz);            // Imprime el valor en el monitor serial (opcional)
  Serial.println(valorLuz2);   
 int frecuencia1 = 200; // Puedes ajustar esto para cambiar la nota
 int frecuencia2 = 300;
 int frecuencia3 = 400;
 int frecuencia4 = 500;
 int frecuencia5 = 600;
 int frecuencia6 = 700;
 int frecuencia7 = 800;
 int frecuencia8 = 900;
 int frecuencia9 = 1000;
 int frecuencia10 = 1100;
 int frecuencia11 = 1200;
 int frecuencia12 = 1300;
 int frecuencia13 = 1400;
 int frecuencia14 = 1500;
 int frecuencia15 = 1600;
 int frecuencia16 = 1700;

 

  // Define un umbral para encender el LED solo si la luz es suficiente
  int umbralEncendido = 150;

  if (valorLuz > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia1);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  } 

  if (valorLuz2 < umbralEncendido ){
  tone(altavozPin, frecuencia2);

   //Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz3 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia3);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  } 
  if (valorLuz4 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia4);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  } 
  if (valorLuz5 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia5);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz6 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia6);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz7 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia7);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz8 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia8);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz9 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia9);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz10 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia10);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz11 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia11);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz12 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia12);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz13 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia13);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz14 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia14);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz15 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia15);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  if (valorLuz16 > umbralEncendido ) {
     // Genera la nota en el altavoz
  tone(altavozPin, frecuencia16);
  // Espera un segundo
  delay(1000);
  // Detén la generación de la nota
  noTone(altavozPin);
  }
  
  else {
    digitalWrite(altavozPin, LOW);   // Apaga el LED si la luz no es suficiente
  }
 // if (valorLuz2 < umbralEncendido) {
   // digitalWrite(ledPin, HIGH);  // Enciende el LED si la luz es suficiente
  //} else {
    //digitalWrite(ledPin, LOW);   // Apaga el LED si la luz no es suficiente
  //}
}