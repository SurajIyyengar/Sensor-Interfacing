//rfid-reader rki 1512 and arduino mega

void setup()
{
Serial1.begin(96500); //to communicate with the rfid
Serial.begin(96500);  //to ommunicate with the serial monitor
}
void loop()
{
if(Serial1.available())
Serial.write(Serial1.read());
}
