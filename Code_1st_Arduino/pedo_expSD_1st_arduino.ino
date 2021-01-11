//This is the program made for the BNS(Blind Navigation System)
//This uses the SD card module and accelerometer which helps in reaching the blind person to reach his/her destination.
/*
Developer - Parv Narang
*/

#include <Servo.h>
int btnup = 2;
int btndn = 3;
Servo servoone,servotwo;
int rtslct=0;
int ypin = A3;            
int count1,count2,steps;
int reached=0;
int  btnprsup;
int  btnprsdn;
int sd1 = 11;
int sd2 = 12;
int sd3 = 13;
int btnprscntup;
void setup()
{
pinMode(btnup,INPUT_PULLUP);
pinMode(btndn,INPUT_PULLUP);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
  
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);


  
Serial.begin(9600);
Serial.begin(9600);
servoone.attach(6);
servotwo.attach(5);

servoone.write(0);
servotwo.write(50);
}

void loop()
{
//Serial.println(analogRead(ypin));

/*Serial.print("\t");
Serial.println();
delay(100);*/
digitalWrite(11,0);
digitalWrite(12,0);
btnprsup= digitalRead(btnup);
btnprsdn= digitalRead(btndn);

if(btnprsup==0)
{
  digitalWrite(11,1);
  btnprscntup++;
  delay(100);
  if(btnprscntup>=3)
  {
    btnprscntup=3;
  }
}
if(btnprsdn==0)
{
  digitalWrite(11,1);
  btnprscntup--;
  delay(100);
  if(btnprscntup<=0)
  {
    btnprscntup=0;
  }
}
else
{
  
}

rtslct = btnprscntup;

if(rtslct>0)
{
  if(analogRead(ypin) >335)
  {
  count1=1;
  //Serial.println("\t foot up");
  }
  
  else
  {
  count2=1;
  //Serial.println("\t foot down");
  delay(5);
  }

if(count1==1 && count2==1)
  {
  steps++;
  count1=0;
  count2=0;
  //Serial.print("\t steps = ");
  //Serial.print("\t");
  Serial.print(steps);
  Serial.println();
  delay(1000);
  }

}


//Serial.println(rtslct);
//Serial.println(btnprsup);
//Serial.println(btnprsdn);

if(rtslct==0)
{ 
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
 norouteselected();

}
          
else if(rtslct==1)
{
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(10,0);
          routehospital();
}

          
else if(rtslct==2)
{
  digitalWrite(8,0);
  digitalWrite(9,1);
  digitalWrite(10,0);
          routemarket();
}
          
else if(rtslct==3)
{
  digitalWrite(8,1);
  digitalWrite(9,1);
  digitalWrite(10,0);
          routetemple();
}


  delay(100);
  
}




void norouteselected()

{ 
          delay(50);         
}


//Routes are assigned here manually where the blind person has to go
//In this case it is hospital, market and temple. You can add any route either to your room or any other place but just observing the steps in every case.

void routehospital()

{
  
 if(reached==0)
          {
         if(steps==5)
          {
            
          //Serial.println("Turn right");
          servoone.write(50);
          delay(150);
          servoone.write(0);
          delay(150);
          }
          
          else if(steps==10)
          {
          //Serial.println("Turn left !!!");
          servotwo.write(0);
          delay(150);
          servotwo.write(50);
          delay(150);
          }
          

          else if(steps==15)
          {
          //Serial.println("Turn right");
          servoone.write(50);
          delay(150);
          servoone.write(0);
          delay(150);
          }
          
          else if(steps==20)
          {
          //Serial.println("Reached Destination!!");
          servotwo.write(0);
          delay(150);
          servotwo.write(50);
          delay(150);
          reached=1;
          }
          }
}



void routemarket()

{
  
   if(reached==0)
          {
         if(steps==5)
          { 
          //Serial.println("Turn right");
          servoone.write(50);
          delay(150);
          servoone.write(0);
          delay(150);
          }
          
          else if(steps==10)
          {
          //Serial.println("Turn left !!!");
          servotwo.write(0);
          delay(150);
          servotwo.write(50);
          delay(150);
          }
          
          else if(steps==15)
          {
          //Serial.println("Turn right");
          servoone.write(50);
          delay(150);
          servoone.write(0);
          delay(150);
          }
          
          else if(steps==20)
          {
          //Serial.println("Reached Destination!!");
          servotwo.write(0);
          delay(150);
          servotwo.write(50);
          delay(150);
          reached=1;
          }
          }

}



void routetemple()

{
  
     if(reached==0)
          {
         if(steps==5)
          {
            
          //Serial.println("Turn right");
          servoone.write(50);
          delay(150);
          servoone.write(0);
          delay(150);
          }
          
          else if(steps==10)
          {
          //Serial.println("Turn left !!!");
          servotwo.write(0);
          delay(150);
          servotwo.write(50);
          delay(150);
          }
          
          else if(steps==15)
          {
          //Serial.println("Turn right");
          servoone.write(50);
          delay(150);
          servoone.write(0);
          delay(150);
          }
          
          else if(steps==20)
          {
          //Serial.println("Reached Destination!!");
          servotwo.write(0);
          delay(150);
          servotwo.write(50);
          delay(150);
          reached=1;
          }
          }
}
