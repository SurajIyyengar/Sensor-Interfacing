//robokits rki-1510 on arduino uno

#include <SoftwareSerial.h>
SoftwareSerial gps(10,11);    //rx,tx
String latitude= "0000.00";
String longitude= "00000.00";
char North_or_South='R';
char East_or_West='K';

double lati, longi;

void setup() 
{
  Serial.begin(9600);
  gps.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(!gps.available());
//Serial.println(gps.readStringUntil('\n'));
String s=gps.readStringUntil('\n');

/*
  eg3. $GPGGA,hhmmss.sss,llll.llll,a,yyyyy.yyyy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh
1    = UTC of Position
2    = Latitude
3    = N or S
4    = Longitude
5    = E or W
6    = GPS quality indicator (0=invalid; 1=GPS fix; 2=Diff. GPS fix)
7    = Number of satellites in use [not those in view]
8    = Horizontal dilution of position
9    = Antenna altitude above/below mean sea level (geoid)
10   = Meters  (Antenna height unit)
11   = Geoidal separation (Diff. between WGS-84 earth ellipsoid and
       mean sea level.  -=geoid is below WGS-84 ellipsoid)
12   = Meters  (Units of geoidal separation)
13   = Age in seconds since last update from diff. reference station
14   = Diff. reference station ID#
15   = Checksum
 */
if(s.startsWith("$GPGGA"))        
{
  Serial.println(s);
  Serial.println("\n\n\n\n");
  latitude=s.substring(18,27);
  North_or_South=s.charAt(28);
  longitude=s.substring(30,39);
  East_or_West=s.charAt(41);

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
 }

 
}


 
