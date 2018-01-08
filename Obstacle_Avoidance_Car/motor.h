/*define forward function*/
void go_Forward(int speed)
{
  digitalWrite(ENA, ABS);
  digitalWrite(ENB, ABS);
  digitalWrite(pinMotor1, LOW); //digital output
  digitalWrite(pinMotor2, speed);
  digitalWrite(pinMotor3, LOW);
  digitalWrite(pinMotor4, speed);
  Serial.println("Forward");
}
/*define back function*/
void go_Back(int speed)
{
  digitalWrite(ENA, ABS);
  digitalWrite(ENB, ABS);
  digitalWrite(pinMotor1, speed);
  digitalWrite(pinMotor2, LOW);
  digitalWrite(pinMotor3, speed);
  digitalWrite(pinMotor4, LOW);
  Serial.println("Back");
}
void stop_Stop()
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop");
}

/*define left function*/
void go_Left(int speed)
{
  digitalWrite(ENA, ABS);
  digitalWrite(ENB, ABS);
  digitalWrite(pinMotor1, LOW);
  digitalWrite(pinMotor2, speed);
  digitalWrite(pinMotor3, speed);
  digitalWrite(pinMotor4, LOW);
  Serial.println("Left");
}
/*define right function*/
void go_Right(int speed)
{
  digitalWrite(ENA, ABS);
  digitalWrite(ENB, ABS);
  digitalWrite(pinMotor1, speed);
  digitalWrite(pinMotor2, LOW);
  digitalWrite(pinMotor3, LOW);
  digitalWrite(pinMotor4, speed);
  Serial.println("Right");
}

/*set motor speed */
void set_Motorspeed(int speed_L,int speed_R)
{
  analogWrite(ENA,speed_L); 
  analogWrite(ENB,speed_R);   
}


