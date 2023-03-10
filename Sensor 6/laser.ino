//Sensor Laser

const pin = 2;

void setup(){
  pinMode(pin, OUTPUT); //Define la ssalida del pin
}

void loop(){
  digitalWrite(pin, HIGH); //poner el pin en HIGH
  delay(5000);             //Esperar 5 segundos
  digitalWrite(pin, LOW);  //Poner el pin en LOW
  delay(20000);            //Esperar 20 segundos
}
