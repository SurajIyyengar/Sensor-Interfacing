//arduino mega 2560 and gsm-gps sim 808


void setup() {
  // put your setup code here, to run once:
Serial1.begin(115200);
 Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available())
{
  Serial1.write(Serial.read());
}
while(Serial1.available())
{
  Serial.print((char)Serial1.read());
  //Serial.write(Serial1.read());
}
}
