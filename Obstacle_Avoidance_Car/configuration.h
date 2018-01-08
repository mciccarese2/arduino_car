#define send;

#define Echo A1
#define Trig A0

#define LED 13 // Use the onboard Uno LED

#define pinMotor1 9
#define pinMotor2 8
#define pinMotor3 7
#define pinMotor4 6
/*define channel enable output pins*/
#define ENA 10
#define ENB 5

#define buzzerPin 2

const int ABS = 180;
const int TURN_SPEED = 150;
const int FWD_SPEED = 255;

int rightDistance = 0, leftDistance = 0, middleDistance = 0 ;
const int distancelimit = 30; //distance limit for obstacles in front
const int sideDistanceLimit = 20; //minimum distance in cm to obstacles at both sides (the car will allow a shorter distance sideways)
const int turntime = 800; //Time the robot spends turning (miliseconds)
