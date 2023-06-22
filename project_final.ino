#include <TinyGPSPlus.h>
#include<SoftwareSerial.h>
#define sensorpin A0
int rx = 3, tx = 4,RX=5,TX=6;
SoftwareSerial bluetooth(rx, tx);
SoftwareSerial gpsport(RX, TX);
TinyGPSPlus gps;
int motorRightA = 8;    //Right Motor-clockwise
int motorRightB = 9;   //Right Motor-anticlockwise
int motorLeftA = 11;    //Left Motor-clockwise
int motorLeftB = 10;    //Left Motor-
char bt = 0;       //Bluetooth Control
void setup()
{

  pinMode(motorRightA, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorLeftB, OUTPUT);
  bluetooth.begin(9600);
  gpsport.begin(9600);
  Serial.begin(9600);
}
void loop() {

  control();
  temperature();
  speedometer();
}

// All the Controls of the Soccer Bot
void control() {
  if (Serial.available() > 0)
  {
    bt = Serial.read();
    if (bt == 'F')       //move forwards
    {
      digitalWrite(motorRightA, HIGH);
      digitalWrite(motorLeftA,  0);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftB, 1);

    }

    else if (bt == 'S')     //stop!
    {
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftA, LOW);
      digitalWrite(motorLeftB, LOW);

    }
    else if (bt == 'R')    //right
    {
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftA, 0);
      digitalWrite(motorLeftB, 1);

    }
    else if (bt == 'L')     //left
    {
      digitalWrite(motorRightA, HIGH);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftA, LOW);
      digitalWrite(motorLeftB, LOW);

    }
    else if (bt == 'G')    //forward right
    {
      digitalWrite(motorRightA, HIGH);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftA, 1);
      digitalWrite(motorLeftB, 0);

    }
    else if (bt == 'I')    //forward left
    {
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorRightB, HIGH);
      digitalWrite(motorLeftA, 0);
      digitalWrite(motorLeftB, 1);

    }
    else if (bt == 'B')       //move backwards
    {
      digitalWrite(motorRightB, HIGH);
      digitalWrite(motorLeftB, 0);
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorLeftA, 1);


    }
  }
}
void temperature() {
  float tempC =((analogRead(sensorpin) * (5.0 / 1024.0))*100);
//  int randnumber=random(0,10);
  bluetooth.print(tempC/2);
  bluetooth.print(";"); // send semicolon as termination character

}

void speedometer() {
//  if(gps.encode(gpsport.read())){
//    bluetooth.print(gps.speed.kmph());
//    bluetooth.print(";");
//    bluetooth.print(gps.location.lat(), 6);
//     bluetooth.print(";");
//    bluetooth.print(gps.location.lng(), 6);
//     bluetooth.print(";");
//  }
  
}
