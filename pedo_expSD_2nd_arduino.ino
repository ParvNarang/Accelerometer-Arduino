//This is the program made for the BNS(Blind Navigation System)
//This uses the SD card module and accelerometer which helps in reaching the blind person to reach his/her destination.
/*
Developer - Parv Narang
*/

#include "SD.h"
#include "TMRpcm.h"
#include "SPI.h"
#define SD_ChipSelectPin 10

TMRpcm tmrpcm;
int reached = 0;

int i = 0;
int j = 0;
int k = 0;

int steps;

void setup()
{
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);

  tmrpcm.speakerPin = 9;

  if (!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }

  i = 0;
  j = 0;
  k = 0;
}

void loop()
{

  if (Serial.available())
  {
    String str = Serial.readString();
    steps = str.toInt();
    Serial.print("\t steps = ");
    Serial.print("\t");
    Serial.print(str);
    Serial.println();

  }

  if (digitalRead(2) == 0 && digitalRead(3) == 0 && digitalRead(4) == 0)
  {
    norouteselected();
    delay(50);
  }
  else if (digitalRead(2) == 1 && digitalRead(3) == 0 && digitalRead(4) == 0)
  {
    routehospital();
    delay(50);
  }
  else if (digitalRead(2) == 0 && digitalRead(3) == 1 && digitalRead(4) == 0)
  {
    routemarket();
    delay(50);
  }
  else if (digitalRead(2) == 1 && digitalRead(3) == 1 && digitalRead(4) == 0)
  {
    routetemple();
    delay(50);
  }

}

void norouteselected()
{

  tmrpcm.setVolume(6);
  tmrpcm.play("slctrt.wav");
  delay(7000);

}

void routehospital()
{
  for (; j < 1; j++)
  {
    tmrpcm.setVolume(6);
    tmrpcm.play("gthsptl.wav");
    delay(2000);
  }

  if (steps == 5)
  {

    Serial.println("Turn right");
    tmrpcm.setVolume(6);
    tmrpcm.play("tr.wav");
    delay(1000);
  }

  else if (steps == 10)
  {
    Serial.println("Turn left !!!");
    tmrpcm.setVolume(6);
    tmrpcm.play("tl.wav");
    delay(1000);
  }

  else if (steps == 15)
  {
    Serial.println("Turn right");
    tmrpcm.setVolume(6);
    tmrpcm.play("tr.wav");
    delay(1000);
  }

  else if (steps == 20)
  {
    Serial.println("Reached Destination!!");
    tmrpcm.setVolume(6);
    tmrpcm.play("rchddstn.wav");
    delay(2100);
    reached = 1;
  }

}

void routemarket()
{
  for (; j < 1; j++)
  {
    tmrpcm.setVolume(6);
    tmrpcm.play("gtmrkt.wav");
    delay(2000);
  }

  if (steps == 5)
  {

    Serial.println("Turn right");
    tmrpcm.setVolume(6);
    tmrpcm.play("tr.wav");
    delay(1000);
  }

  else if (steps == 10)
  {
    Serial.println("Turn left !!!");
    tmrpcm.setVolume(6);
    tmrpcm.play("tl.wav");
    delay(1000);
  }

  else if (steps == 15)
  {
    Serial.println("Turn right");
    tmrpcm.setVolume(6);
    tmrpcm.play("tr.wav");
    delay(1000);
  }

  else if (steps == 20)
  {
    Serial.println("Reached Destination!!");
    tmrpcm.setVolume(6);
    tmrpcm.play("rchddstn.wav");
    delay(2100);
    reached = 1;
  }

}

void routetemple()

{
  for (; k < 1; k++)
  {
    tmrpcm.setVolume(6);
    tmrpcm.play("gttmpl.wav");
    delay(2000);
  }

  if (steps == 5)
  {
    Serial.println("Turn right");
    tmrpcm.setVolume(6);
    tmrpcm.play("tr.wav");
    delay(1000);
  }

  else if (steps == 10)
  {
    Serial.println("Turn left !!!");
    tmrpcm.setVolume(6);
    tmrpcm.play("tl.wav");
    delay(1000);
  }

  else if (steps == 15)
  {
    Serial.println("Turn right");
    tmrpcm.setVolume(6);
    tmrpcm.play("tr.wav");
    delay(1000);
  }

  else if (steps == 20)
  {
    Serial.println("Reached Destination!!");
    tmrpcm.setVolume(6);
    tmrpcm.play("rchddstn.wav");
    delay(2100);
    reached = 1;
  }
}
