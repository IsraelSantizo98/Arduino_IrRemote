#include <IRremote.h>
//Se define un nombre a los codigos hexadecimales, no se coloca ";" al final
#define btn1 0xFFA25D
#define btn2 0xFF629D
#define btn3 0xFFE21D
#define btn4 0xFF22DD
//Codigo hexadeciemal de mismo botones pero con el codigo que activa a una distancia media
#define btn1l 0xE318261B
#define btn2l 0x511DBB
#define btn3l 0xEE886D7F

//Se definen las variables como int
int Sensor = 11;
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
IRrecv irrecv(Sensor);
decode_results codigo;
void setup() {
  //Se configuran los pines como salida
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();

}
void loop() {
  if(irrecv.decode(&codigo)){
    Serial.println(codigo.value, HEX);
    //Se crea un ciclo para verificar si el codigo es el mismo que el boton que se presione
    if(codigo.value == btn1 || codigo.value == btn1l){
      //Con el !digitalRead se cambia el estado si esta encendido lo apaga y si esta apagado lo enciende
      digitalWrite(relay1, !digitalRead(relay1));
    }
    if(codigo.value == btn2 || codigo.value == btn2l){
      //Con el !digitalRead se cambia el estado si esta encendido lo apaga y si esta apagado lo enciende
      digitalWrite(relay2, !digitalRead(relay2));
    }
    if(codigo.value == btn3 || codigo.value == btn3l){
      //Con el !digitalRead se cambia el estado si esta encendido lo apaga y si esta apagado lo enciende
      digitalWrite(relay3, !digitalRead(relay3));
    }
    if(codigo.value == btn4){
      //Con el !digitalRead se cambia el estado si esta encendido lo apaga y si esta apagado lo enciende
      digitalWrite(relay4, !digitalRead(relay4));
    }
    irrecv.resume(); //Para que el sensor este listo para el proximo comando 
  }
  delay (500);
}
/*
 * Codigos del control, 
 * 1 =  FFA25D
 * 2 =  FF629D
 * 3 =  FFE21D
 * 4 =  FF22DD
 * 5 = 
 * 6 = 
 * 7 = 
 * 8 = 
*/
