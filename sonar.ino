
//HC SR04 with arduino uno

int trig=2;
int duration,distance;
int echo=3;
//As soon as the SONAR is triggered by the arduino the SONAR sends a 8 cycle SONIC burst after at the end of the echo is turned on. The echo goes low when the
//reflected sound is received at the SONAR
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig,LOW);
delay(5);

digitalWrite(trig,HIGH);
delay(1000);
digitalWrite(trig,LOW);

duration = pulseIn(echo, HIGH);
//Serial.println(duration);
distance = duration*0.034/2;
if (distance >= 400|| distance <= 0){
 Serial.println("-1");
 }
 else {
 Serial.println(distance);
 }

delay(50);
}
