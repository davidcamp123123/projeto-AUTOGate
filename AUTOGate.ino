#include <Servo.h>
Servo servo;
int pos =0; // angulo do morotr
const int trig = 7; // transmissor
const int echo =8;  // receptor


void setup() {
  servo.attach(2);
  pinMode(echo,INPUT); // transmite
  pinMode(trig, OUTPUT); // recebe
  Serial.begin(9600); // inicia a troca de dados

}


void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2); // zera o trasmissor


  digitalWrite(trig,HIGH); //envia
  delay(500); // espera
  digitalWrite(trig,LOW); // desliga

  long duration; //numeros gigantescos
  float distance; // numeros grandes

  duration = pulseIn(echo, HIGH); // mede a duração da onda
  distance = duration * 0.034 / 2; //calculo da duração

  if (distance < 30){ // se distância menor que 30
    servo.write(150);  // motor vira 150
  }else{ // senão
    servo.write(50); // motor volta ao seu estado original
  }


  


}
