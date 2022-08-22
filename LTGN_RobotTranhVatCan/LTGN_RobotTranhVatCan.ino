// Robot tranh vat can
// Lap trinh ghep noi may tinh_Pham Duy Hung
//Dinh Quang Lam 
// Msv: 19021478
// K64_DA_CLC1_UET_VNU



#include <NewPing.h>
#include <Servo.h>
Servo myservo;
#define trig_pin A0 
#define echo_pin A1
#define maximum_distance 2000
  
NewPing sonar(trig_pin, echo_pin, maximum_distance);
const int LeftMotorForward = 5;
const int LeftMotorBackward = 4;
const int RightMotorForward = 3;
const int RightMotorBackward = 2;
char labview;

int data1;
int data2;
int data3;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
}

void loop() 
{
  labview = Serial.read();
  if (labview == '1')
  {
    autosensing();
  }
  else if(labview == 's')
  {
    moveStop();
  }
}

int readPing()
{
  delay(20);
  int cm = sonar.ping_cm();
  return cm;
}

void moveStop()
{
  Serial.println("STOPPED");
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward()
{
  Serial.println("MOVING FORWARD");
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveBackward()
{
  moveStop();
  Serial.println("MOVING BACKWARD");
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
}

void moveRight()
{
  moveStop();
  Serial.println("MOVING TO THE RIGHT");
  digitalWrite(LeftMotorForward, LOW); 
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, HIGH);
}

void moveLeft()
{
  moveStop();
  Serial.println("MOVING TO THE LEFT");
  digitalWrite(RightMotorForward, LOW); 
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
}

void servoFront()
{
  Serial.println("LOOKING FRONT");
  myservo.write(90);
  delay(500);
}

void servoRight()
{
  myservo.write(0);
  Serial.println("LOOKING RIGHT");
  delay(500);
}

void servoLeft()
{
  Serial.println("LOOKING LEFT");
  myservo.write(180);
  delay(500);
}

void autosensing()
{
  int data = readPing();
  if (data < 30)
  {
    moveStop();
    Serial.println("Searching way ... ");
    servoRight();
    data1 = readPing();

    servoFront();
    data2 = readPing();

    servoLeft();
    data3 = readPing();

    servoFront();
    delay(100);

    if (data1 > 40)
    {
      moveBackward();
      delay(300);
      moveRight();
      delay(500);
      moveForward();
    }
    else if (data2 > 40)
    {
      moveForward();
    }
    else if (data3 > 40)
    {
      moveBackward();
      delay(300);
      moveLeft();
      delay(500);
      moveForward();
    }
  }
  else
  {
    moveForward();
  }
}
