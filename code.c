const int trigpin=2;
const int echopin=4;
long duration;
long distance;

int motor1Pin1=18;
int motor1Pin2=19;
int motor2Pin1=26;
int motor2Pin2=27;

void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

  pinMode(motor1Pin1,OUTPUT);
  pinMode(motor1Pin2,OUTPUT);
  pinMode(motor2Pin1,OUTPUT);
  pinMode(motor2Pin2,OUTPUT);
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor2Pin2,LOW);
}


float measuredistance() {
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
distance= duration*0.034/2;
delay(100);
return distance;
}


void loop(){
  float k= measuredistance();
  if(k<50){
    if(k>10){
    digitalWrite(motor1Pin1,HIGH);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,HIGH);
    digitalWrite(motor2Pin2,LOW);
  }

  else{
    digitalWrite(motor1Pin1,LOW);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,LOW);
    digitalWrite(motor2Pin2,LOW);
  }
  }

  else if(k>50){
    digitalWrite(motor1Pin1,LOW);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,LOW);
    digitalWrite(motor2Pin2,LOW);
  }

}
