#include <Servo.h>
Servo myservo;//δημιουργείται το αντικείμενο που ελέγχει το servo

void setup()
{
  myservo.attach(9);//ο σερβοκινητήρας συνδέεται στο pin 9
  myservo.write(0);//γυρίζει στις 0 μοίρες
  delay(1000);//περιμένει 1 sec
}

void loop()
{  
  myservo.write(15);//γυρίζει στις 15 μοίρες
  delay(1000);//περιμένει 1 sec

  myservo.write(30);//γυρίζει στις 30 μοίρες 
  delay(1000);//περιμένει 1 sec
  
  myservo.write(45);//γυρίζει στις 45 μοίρες 
  delay(1000);//περιμένει 1 sec

  myservo.write(60);//γυρίζει στις 60 μοίρες 
  delay(1000);//περιμένει 1 sec

  myservo.write(75);//γυρίζει στις 75 μοίρες 
  delay(1000);//περιμένει 1 sec

  myservo.write(90);//γυρίζει στις 90 μοίρες
  delay(1000);//περιμένει 1 sec

  myservo.write(75);//γυρίζει στις 75 μοίρες 
  delay(1000);//περιμένει 1 sec

  myservo.write(60);//γυρίζει στις 60 μοίρες
  delay(1000);//περιμένει 1 sec

  myservo.write(45);//γυρίζει στις 45 μοίρες
  delay(1000);//περιμένει 1 sec

  myservo.write(30);//γυρίζει στις 30 μοίρες
  delay(1000);//περιμένει 1 sec

  myservo.write(15);//γυρίζει στις 15 μοίρες 
  delay(1000);//περιμένει 1 sec

  myservo.write(0);//γυρίζει στις 0 μοίρες
  delay(1000);//περιμένει 1 sec
  for(int num=0;num<=180;num++)
  {
     myservo.write(num);//γυρίζει 'num' μοίρες (0 έως 180)
     delay(10);//control servo speed
  }
  for(int num=180;num>=0;num--)
  {
     myservo.write(num);//γυρίζει 'num' μοίρες (180 έως 0)
     delay(10);//ελέγχει την ταχύτητα του σερβοκινητήρα
  }
}
