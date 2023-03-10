/*
 * This is the Arduino code for TM1637 4 digits display.
 *  * 
 * Written by Ahmad S. for Robojax Video
 * Date: Dec 06, 2017, in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 */

/*
 * Original code from https://github.com/avishorp/TM1637
 * Modified for Robojax video on Dec 06, 2017

 */
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 5
#define DIO 4

// The amount of time (in milliseconds) between tests

const int tiltSwitchPin = 19; // Configurar el pin digital para el tilt switch
int valorTiltSwitch = 0; // Variable para almacenar el valor del tilt switch
bool tiltSwitchCerrado = false;

TM1637Display display(CLK, DIO);


void setup()
{
   Serial.begin(115200); 
   display.setBrightness(0x0f);
}

void loop()
{
 
  valorTiltSwitch = digitalRead(tiltSwitchPin); // Leer el valor del tilt switch
  tiltSwitchCerrado = (valorTiltSwitch == HIGH); // Actualizar el estado del tilt switch

  if (tiltSwitchCerrado) {
    int valor = analogRead(1234); // Leer el valor del pin A0
    display.showNumberDec(valor); // Mostrar el valor en el display
  } else {
    display.clear(); // Limpiar el display si el tilt switch está abierto
  }

  delay(100);
}
