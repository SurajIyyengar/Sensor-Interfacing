//gsm-gps sim 808 module and arduino mega 2560


String phn, message;
//-------------------------------
void setup() 
{
Serial1.begin(115200);
Serial.begin(115200);
}
//-----------------------------------------------------
void loop() 
{
 switch (Serial.readString().charAt(0))
{
  case 's':
      {
         askPhn();
         askMessage();
         sendMessage();
       }
  break;
 case 'r':
        receiveMessage();
     break;
}
 while(Serial1.available()>0)       //to print the message received
    Serial.write(Serial1.read());     
}
//----------------------------------------------------
void askPhn()
{
  Serial.print("Enter the phone number in +91xxxxxxxxxx format\n");
  //weird \n reading
  Serial.read();
  while(!Serial.available());
  phn=Serial.readStringUntil('\n');
  //to read the \n
  Serial.read();
}
//----------------------------------------------------
void askMessage()
{
  Serial.println("Enter the message");
  //weird \n reading
  Serial.read();
  while(!Serial.available());
  message=Serial.readStringUntil('\n');
  //to read the \n
  Serial.read();                    
}
//----------------------------------------------------
void receiveMessage()
{
   Serial1.write("AT+CNMI=2,2,0,0,0");  //to receive live message 
  delay(1000);
}
//----------------------------------------------------
void sendMessage()
{
  int i=0;
  Serial1.println("AT+CMGF=1");        //text mode
  delay(1000);
  
  Serial1.print("AT+CMGS=\"");         // to enter phone number
  while(phn[i]!='\0')
  Serial1.write(phn[i++]);             //enter phn in quotes
  Serial1.print("\"\n");               //end quote
  delay(1000);
  
  i=0;
  while(message[i]!='\0')
  Serial1.write(message[i++]);         //enter the message to the gsm module
  Serial1.println();
  delay(1000);
  
  Serial1.println((char)26);           //ctrl+Z eof
  delay(1000);
}


