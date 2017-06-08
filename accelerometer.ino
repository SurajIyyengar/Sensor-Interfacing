void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("X=");
Serial.print(analogRead(A0));
Serial.print("\tY=");
Serial.print(analogRead(A1));
Serial.print("\tZ=");
Serial.println(analogRead(A2));

}
