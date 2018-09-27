const int sensor = 2;
const int LED = 4;
 
void setup() {
  //configurar pin como entrada con resistencia pull-up interna
  pinMode(sensor, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}
 
void loop() {
  control_sensor();
}

void control_sensor(){
  int value = digitalRead(sensor);
 
  if (value == LOW) {
    /* si el sensor está activado, quiere decir que la puerta está cerrada,
    por lo tanto el led debe de estar apagado, al abrirse la puera, se enciende el led*/
    digitalWrite(LED, LOW);   
  } else {
    digitalWrite(LED, HIGH);
  }
 
  delay(1000);
}

