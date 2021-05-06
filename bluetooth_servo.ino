#include<SoftwareSerial.h>
#include<Servo.h>
Servo x;
int bttx=9;
int btrx=10;
SoftwareSerial bluetooth(bttx,btrx);
void setup()
{
  x.attach(11);
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  if(bluetooth.available() > 0)
  {
    int pos=bluetooth.read();
    Serial.println(pos);
    x.write(pos);
  }
}
