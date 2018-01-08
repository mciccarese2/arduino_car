void buzz_ON()   //open buzzer
{
  digitalWrite(buzzerPin, LOW);
}
void buzz_OFF()  //close buzzer
{
  digitalWrite(buzzerPin, HIGH);
}
void alarm() {
  buzz_ON();
  delay(2000);
  buzz_OFF();
}

//buzzer sound
void soundAlarm()         
{
  for(int i=0;i<100;i++){
    digitalWrite(buzzerPin,HIGH); //the buzzer sound
    delay(2);
    digitalWrite(buzzerPin,LOW);  //without sound
    delay(2);                     //when delay time changed,the frequency changed
  }
}
