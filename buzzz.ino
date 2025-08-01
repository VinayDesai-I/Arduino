#include <Servo.h>

const int IR 2
const int LED 4
const int BUZZ 7
const int MOTOR 8

Servo servo1;
unsigned long dopentime = 0;
bool dopen = false;
/*bool dclose = false;*/
unsigned long tdopentime =  0;
/*unsigned long dclosetime = 0;*/
int spos = 180;
/*int o = 3;*/

void setup()
{
  
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  servo1.attach(MOTOR, 500, 2500);
  servo1.write(spos);
  Serial.begin(9600);
  
}

void loop()
{
  boolean sensoris = digitalRead(IR);  
  
  if (sensoris == HIGH)
  {
    digitalWrite(LED, HIGH);
    if (!dopen)
    {
      dopentime = millis();
      dopen = true;
    }
    
    Serial.println(dopentime);
  }
  else
  {
    digitalWrite(LED, LOW);
    //digitalWrite(BUZZ, LOW);
    if (spos >= 2 && spos <= 20){
        digitalWrite(BUZZ, HIGH);
    }
    else {
        digitalWrite(BUZZ, LOW);
    }
    if (dopen)
    {
      tdopentime += (millis() - dopentime);
    }

    if(!dopen and spos < 90) {
      spos++;
      servo1.write(spos);
    }
    //servo1.write(0);
    dopen = false;
    
    Serial.println(tdopentime);
  }
  
  if (dopen and (millis() - dopentime > 5000))
  {
    /*if (millis() % 3 == 0) {
      digitalWrite(BUZZ, HIGH); 
    }
    else {
      digitalWrite(BUZZ, LOW);
    }*/

    //digitalWrite(BUZZ, HIGH);
    if (spos >= 69 && spos <= 89) {
        digitalWrite(BUZZ, HIGH);
    }
    else {
        digitalWrite(BUZZ, LOW);
    }
    if (dopen and spos > 0) {
      spos--;
      servo1.write(spos);
    }
    
    /*for (int pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);  // waits 15 ms for the servo to reach the position
    }*/
    /*servo1.write(90);
    delay(1000);
    dclose = true;*/
    /*dclosetime = millis();*/
  }
}
