#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int pos0 = 102;
int pos180 = 512;

int i;

void setup() 
{
  Serial.begin(9600);
  Serial.println("GPIO test!");
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(1000);
  iP();
  delay(2000);
//  setServo(0,0);
//  delay(2000);
//  setServo(0,60);
}

String str;

void loop() 
{
  str = "";
  
  while(Serial.available()>0)
  {
    str = Serial.readString();
  }
  str.toLowerCase();
  delay(100);
  Serial.println(str);
  Serial.println(str.length());
//  Serial.println(i);
  if(str == "thumb open" || str == "open thumb finger")
  {
    thumbOpen();
    delay(1000);
  }
  if(str == "index open" || str == "open index finger")
  {
    indexOpen();
    delay(1000);
  }
  if(str == "middle open" || str == "open middle finger")
  {
    middleOpen();
    delay(1000);
  }
  if(str == "ring open" || str == "open ring finger")
  {
    ringOpen();
    delay(1000);
  }
  if(str == "little open" || str == "open little finger")
  {
    littleOpen();
    delay(1000);
  }
  if(str == "thumb close" || str == "close thumb finger")
  {
    thumbClose();
    delay(1000);
  }
  if(str == "index close" || str == "close index finger")
  {
    indexClose();
    delay(1000);
  }
  if(str == "middle close" || str == "close middle finger")
  {
    middleClose();
    delay(1000);
  }
  if(str == "ring close" || str == "close ring finger")
  {
    ringClose();
    delay(1000);
  }
  if(str == "little close" || str == "close little finger")
  {
    littleClose();
    delay(1000);
  }
  if(str == "open all" || str == "all open")
  {
    openAll();
    delay(1000);
  }
  if(str == "close all" || str == "all close")
  {
    closeAll();
    delay(1000);
  }
  if(str == "thumbs up")
  {
    thumbsUp();
    delay(1000);
  }
  if(str == "victory sign" || str == "victory")
  {
    victory();
    delay(1000);
  }
  if(str == "rock on" || str == "rock")
  {
    rockOn();
    delay(1000);
  }
  if(str == "call me" || str == "call")
  {
    callMe();
    delay(1000);
  }
  if(str == "hold" || str == "hold it")
  {
    closeAll();
    delay(1000);
  }
}
void setServo(int servo, int angle) 
{
  int duty;
//  duty = map(angle, 0, 180, pos0, pos180); //(angle, minAgl, maxAgl, min_Given_Angle, max_Given_Angle)

  duty = map(angle, 0, 180, pos0, pos180); 
  
  pwm.setPWM(servo, 0, duty); // (pin,0,duty)...^
}

void iP()
{
  allOpen1by1();
}

void thumbOpen()
{
  setServo(0,20);
}

void thumbClose()
{
  setServo(0,120);
}

void indexOpen()
{
  setServo(1,20);
}

void indexClose()
{
  setServo(1,120);
}

void middleOpen()
{
  setServo(2,20);
}

void middleClose()
{
  setServo(2,120);
}

void ringOpen()
{
  setServo(3,20);
}

void ringClose()
{
  setServo(3 ,120);
}

void littleOpen()
{
  setServo(4,20);
}

void littleClose()
{
  setServo(4,120);
}

void allOpen1by1()
{
  thumbOpen();
  delay(500);
  indexOpen();
  delay(500);
  middleOpen();
  delay(500);
  ringOpen();
  delay(500);
  littleOpen();
}

void allClose1by1()
{
  littleClose();
  delay(500);
  ringClose();
  delay(500);
  middleClose();
  delay(500);
  indexClose();
  delay(500);
  thumbClose();
}

void openAll()
{
  if(i>20)
  {
    for(i=120; i>=20; i--)
    {
      setServo(0,i);
      setServo(1,i);
      setServo(2,i);
      setServo(3,i);
      setServo(4,i);
    }
  }
}
void closeAll()
{
  if(i<120)
  {
    for(i=20; i<=120; i++)
    {
      setServo(0,i);
      setServo(1,i);
      setServo(2,i);
      setServo(3,i);
      setServo(4,i);
    }
  }
}
void allOpenClose()
{
  allOpen1by1();
  delay(3000);
  allClose1by1();
}

void thumbsUp()
{
  allClose1by1();
  delay(2000);
  thumbOpen();
}

void victory()
{
  allClose1by1();
  delay(2000);
  indexOpen();
  middleOpen();
}

void rockOn()
{
  allClose1by1();
  delay(2000);
  thumbOpen();
  indexOpen();
  littleOpen();
}

void callMe()
{
  allClose1by1();
  delay(2000);
  thumbOpen();
  littleOpen();
}
