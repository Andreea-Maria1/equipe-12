#include <NewPing.h>
 
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define TRIGGER_PIN2 9
#define ECHO_PIN2 10
#define MAX_DISTANCE 400

 NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); 

int in1 = 2;
int in2 = 4;
int enA = 3;
int in3 = 5;
int in4 = 7;
int enB = 6;
bool ObjectifNonAtteint = true;

void gauche(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 100);
  digitalWrite(enB, 100);
  delay(250);
}

void droite(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 100);
  digitalWrite(enB, 100);
  delay(250);
  ObjectifNonAtteint = false;
}

void droit(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 100);
  digitalWrite(enB, 100);
  delay(100);
}

bool Arrivee();
  unsigned int distance1 = sonar.ping_cm();
  unsigned int dist1 = sonar2.ping_cm();
  if (distance1 < 10){
    return true;
  }
  else{
    return false;
  }


void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enB, 0);
  delay(150);
}

bool ObjetAGauche(){
  unsigned int distance1 = sonar.ping_cm();
  unsigned int dist1 = sonar2.ping_cm();
  if(distance1 > dist1){
    return false;
  }
  else{
    return true;
  }
}

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  if (Arrivee() == true){
    exit(0);
  }
   droit();
  if (ObjetAGauche()){
    droite();
  }
  else{
    gauche();
  }
}
