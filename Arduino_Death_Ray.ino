/*
 *  Two servo sweep with LED
 *  Servo1 pin 9
 *  Servo2 pin 10
 *  LED pin 12 + GND
 * 
 *  Serial Controller
 */
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

int pos1 = 0;
int pos2 = 0;


void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
  pinMode(12, OUTPUT);

  Serial.begin(19200);
  Serial.println("Serial Started\n");
}
int servoX = 0;
int servoY = 0;
int LED = 0;
int X = 0;
int Y = 0;
int L = 0;
int T = 0;
void loop() {
  if(Serial.available())
    {
      while(true)
        { 
          T = Serial.parseInt();
          if(T=360)
            {
              break;
            }
        }
      T=0;
      X = Serial.parseInt();
      Y = Serial.parseInt();
      L = Serial.parseInt();
      if(X > 5 && X < 175)
        {
          servoX = 180 - X;
        }
      if(Y > 5 && Y < 175)
        {
          servoY = 180 - Y;
        }
      if(L == 1)
        {
          LED = 0;
        }
       if(L == 2)
        {
          LED = 1;
        }
      delay(5);
    }
   myservo2.write(servoY);
   delay(5);
   myservo1.write(servoX);
   if(LED)
    {
      digitalWrite(12, HIGH);
    }
   else
    {
      digitalWrite(12, LOW);
    }
}
