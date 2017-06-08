//arduino mega 2560 and sim808 gps-gsm module

String latitude= "0000.00";
String longitude= "00000.00";
char North_or_South='R';
char East_or_West='K';

double lati, longi;

void setup() {

Serial.begin(115200);
Serial1.begin(115200);

//turn on the power of the gps
Serial1.println("AT+CGPSPWR=1");

//cold reset the gps
Serial1.println("AT+CGPSRST=0");

/*
 * 
 
 The hot start is when the GPS device 
 remembers its last calculated position and 
 the satellites in view, the almanac used (information
 about all the satellites in the constellation),
 the UTC Time and makes an attempt to lock onto 
 the same satellites and calculate a new position 
 based upon the previous information. This is the
 quickest GPS lock but it only works if you are
 generally in the same location as you were when 
 the GPS was last turned off.

The warm start is when the GPS device remembers 
its last calculated position, almanac used, and
UTC Time, but not which satellites were in view.
It then performs a reset and attempts to obtain 
the satellite signals and calculates a new position.
The receiver has a general idea of which satellites 
to look for because it knows its last position and 
the almanac data helps identify which satellites are
visible in the sky. This takes longer than a hot start
but not as long as a cold start.

And finally, the cold start is when the GPS device dumps
all the information, attempts to locate satellites and 
then calculates a GPS lock. This takes the longest because
there is no known information.
*/
}

void loop() {

//get the info in $GPGGA- mode is 2
Serial1.println("AT+CGPSINF=2");

while(!Serial1.available());
String s=Serial1.readStringUntil('\n');     //gets the gpgga value

  latitude=s.substring(23,32);
  North_or_South=s.charAt(33);
  longitude=s.substring(35,45);
  East_or_West=s.charAt(46);
  Serial.println(s);
  lati=latitude.toDouble();
  longi=longitude.toDouble();
   Serial.print("Latitude= ");
   Serial.print(lati);
   Serial.print(" ");
   Serial.print(North_or_South);
   Serial.print("\tLongitude= ");
   Serial.print(longi);
   Serial.print(" ");
   Serial.print(East_or_West);
   Serial.println();

   delay(2000);
}

