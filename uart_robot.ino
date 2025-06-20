#include <SoftwareSerial.h>
SoftwareSerial blt(7, 6);
int m2 = 5;
int m3 = 8;
int m4 = 3;
int m5 = 2;
void left() {
  digitalWrite(m2, 1);
  digitalWrite(m3, 0);
  digitalWrite(m4, 1);
  digitalWrite(m5, 0);
}
void right() {
  digitalWrite(m2, 0);
  digitalWrite(m3, 1);
  digitalWrite(m4, 0);
  digitalWrite(m5, 1);
}
void forward()
{
  digitalWrite(m2,1);
  digitalWrite(m3,0);
  digitalWrite(m4,0);
  digitalWrite(m5,1);
}
void backward()
{
  digitalWrite(m2,0);
  digitalWrite(m3,1);
  digitalWrite(m4,1);
  digitalWrite(m5,0);
}
void stop()
{
  digitalWrite(m2,0);
  digitalWrite(m3,0);
  digitalWrite(m4,0);
  digitalWrite(m5,0);
}
void setup() 
{
  Serial.begin(9600);
  blt.begin(9600);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(m5,OUTPUT);
}
void loop() {
  if (blt.available())
   {
    char data = blt.read();
    Serial.println(data);
    if(data=='F')
    {
      forward();
      Serial.println("forward");
    }
    else if(data=='B')
    {
      backward();
      Serial.println("backward");
    }
    else if(data=='R')
    {
      right();
      Serial.println("right");
    }
    else if(data=='L')
    {
      left();
      Serial.println("left");
    }
    else if(data=='X')
    {
      stop();
      Serial.println("stop");
    }
  }
}