#include <avr/sleep.h>  // Liberia para ahorro de energía

int sensor = 2;
int led = 4;

const int ALARMA = 3;   //buzzer

int potenciometro = A1;
int valor_pote = 0;

 
void setup() {
  pinMode(sensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(ALARMA, OUTPUT);
 

}
 
void loop() {
/* si el sensor está activado, quiere decir que la puerta está cerrada,
    por lo tanto la alarma esta apagada, al abrirse la puerta
    se abre el sensor y se enciende la alarma*/

  sleep_enable();   // Iniciar el modo de bajo consumo para Arduino
  sleep_mode();
  
  int value = digitalRead(sensor);
    
  if (value == HIGH){
      Alarma();
  }
  
}

void Alarma (){
  /* Dependiendo del valor del potenciometro aumentará o disminuirá 
   la velovidad del sonido, esto para indicar el estado de emergencia.*/ 
  valor_pote = analogRead(potenciometro);
 
         
      tone(ALARMA, 200);
      delay(valor_pote);  
      digitalWrite(led,HIGH);
 
      noTone(ALARMA);
      delay(valor_pote);   
      digitalWrite(led,LOW);
  
}



