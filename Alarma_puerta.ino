int sensor = 2;
int led = 4;

const int ALARMA = 3;   //buzzer
 
void setup() {
  //configurar pin como entrada con resistencia pull-up interna
  pinMode(sensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(ALARMA, OUTPUT);
}
 
void loop() {
  int value = digitalRead(sensor);

 /* si el sensor está activado, quiere decir que la puerta está cerrada,
    por lo tanto el led debe de estar apagado, al abrirse la puerta
    se abre el sensor y se enciende el led*/
    
  if (value == LOW) {
    digitalWrite(led, LOW);   
  } else {
    digitalWrite(led, HIGH);
  }
   delay(500);    //control

  if ( value == HIGH)
     Alarma();
}

void Alarma (){
   
  tone(ALARMA, 261.63);
  delay(250);
 
  noTone(ALARMA);
  //delay(300);

}

