//www.elegoo.com
//2016.09.12 testare
#include <Servo.h> //servo library
#include "configuration.h"
#include "motor.h"
#include "alarm.h"
Servo myservo; // create servo object to control servo
/*Ultrasonic distance measurement Sub function*/
int watch() {
  long howfar;
  digitalWrite(Trig, LOW);
  delayMicroseconds(5);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(15);
  digitalWrite(Trig, LOW);
  howfar = pulseIn(Echo, HIGH);
  howfar = howfar * 0.01657; //how far away is the object in cm
  return round(howfar);
}

void setup()
{
  myservo.attach(3);// attach servo on pin 3 to servo object
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
  pinMode(pinMotor3, OUTPUT);
  pinMode(pinMotor4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LED, OUTPUT);
  stop_Stop();

  // set up the LCD's number of columns and rows:
  //lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
}
void loop()
{
  myservo.write(90);//setservo position according to scaled value
  delay(100);
  middleDistance = watch();
#ifdef send
  Serial.print("middleDistance=");
  Serial.println(middleDistance);
#endif
  if (middleDistance <= distancelimit)
  {
    stop_Stop();
    alarm();
    myservo.write(10);//10°-180°
    delay(100);
    rightDistance = watch();
#ifdef send
    Serial.print("rightDistance=");
    Serial.println(rightDistance);
#endif
    myservo.write(90);
    myservo.write(180);
    delay(500);
    leftDistance = watch();
#ifdef send
    Serial.print("leftDistance=");
    Serial.println(leftDistance);
#endif
    delay(500);
    myservo.write(90);
    delay(500);
    // if (rightDistance > leftDistance) {
    if ((rightDistance > sideDistanceLimit || leftDistance < sideDistanceLimit) || rightDistance > leftDistance)
    {
      alarm();
      go_Right(TURN_SPEED);
      delay(turntime);
    }
    // else if (rightDistance < leftDistance)
    if ((leftDistance > sideDistanceLimit || rightDistance < sideDistanceLimit) || rightDistance < leftDistance)
    {
      alarm();
      go_Left(TURN_SPEED);
      delay(turntime);
    }
    
    //else if ((rightDistance <= sideDistanceLimit) || (leftDistance <= sideDistanceLimit))
    if ((rightDistance <= sideDistanceLimit) || (leftDistance <= sideDistanceLimit))
    {
      alarm();
      go_Back(TURN_SPEED);
      delay(turntime);
    }
    else
    {
      go_Forward(FWD_SPEED);
    }
  }
  else {
    go_Forward(FWD_SPEED);
  }
}



