//robokits rki-3155 on arduino uno

//program to obtain the angle of orientation of the joystick
#include <Math.h>

int swtch=8;
//value which the joystick returned at centre position
int x0=515;
int y0=525;
void setup() {
  // put your setup code here, to run once:
pinMode(swtch,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("X= ");
int x=analogRead(A0)-x0;
Serial.println(x);
Serial.print("Y= ");
int y=-analogRead(A1)+y0;
Serial.println(y);
Serial.print("Switch= ");
Serial.println(digitalRead(swtch));

if(x==0&&y==0)
Serial.println("rest position");
else
{
Serial.print("Angle= ");
double angle=180.0/3.141528*atan((double)abs(y)/(double)abs(x));
if(x<0&&y>0)
Serial.println(90.0+angle);
else if(x<=0&&y<=0)
Serial.println(180+angle);
else if(x>0&&y<0)
Serial.println(angle+270);
else
Serial.println(angle);
}

delay(500);
}
