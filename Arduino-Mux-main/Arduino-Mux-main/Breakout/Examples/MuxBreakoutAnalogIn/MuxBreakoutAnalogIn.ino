#include "MuxBreakout1.h"
#include "MuxBreakout2.h"
const int SPEAKER_PIN = 9; // Puedes cambiar el pin si lo necesitas

// Inicializa los dos Mux Breakouts
MuxBreakout muxBreakout1;
MuxBreakout muxBreakout2;

void setup()
{
    // Configura el primer multiplexor
    muxBreakout1.setMode(ANALOG_IN);

    // Configura el segundo multiplexor
    muxBreakout2.setMode(ANALOG_IN);

    Serial.begin(19200);
    pinMode(SPEAKER_PIN, OUTPUT);
}

// Arrays para almacenar los valores analógicos después de recibirlos
int IO1AnalogVals[16];
int IO2AnalogVals[16];

void loop()
{
    // Leer las entradas analógicas del primer multiplexor
    for (int i = 0; i < 16; i++)
    {
        IO1AnalogVals[i] = muxBreakout1.analogReadMB(i);
    }

    // Leer las entradas analógicas del segundo multiplexor
    for (int i = 0; i < 16; i++)
    {
        IO2AnalogVals[i] = muxBreakout2.analogReadMB(i);
    }

    // Imprimir los valores del primer multiplexor para inspección
    //Serial.print("IO1 analog values: ");
    for (int i = 0; i < 16; i++)
    {
        //Serial.print(IO1AnalogVals[i]);
        //Serial.print('\t');
    }
    Serial.println();

    // Imprimir los valores del segundo multiplexor para inspección
    Serial.print("IO2 analog values: ");
    for (int i = 0; i < 16; i++)
    {
        Serial.print(IO2AnalogVals[i]);
        Serial.print('\t');
    }
    Serial.println();

    const int frequencies[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600};

    // Generar tonos basados en los valores del primer multiplexor
    for (int i = 0; i < 16; i++)
    {
        if (IO1AnalogVals[i] < 150)
        {
            tone(SPEAKER_PIN, frequencies[i]);
            delay(200);
        }
        else
        {
            noTone(SPEAKER_PIN);
        }
    }

    // Generar tonos basados en los valores del segundo multiplexor
    for (int i = 0; i < 16; i++)
    {
        if (IO2AnalogVals[i] < 150)
        {
            tone(SPEAKER_PIN, frequencies[i]);
            delay(200);
        }
        else
        {
            noTone(SPEAKER_PIN);
        }
    }
}