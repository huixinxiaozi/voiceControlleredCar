#include <SoftwareSerial.h>
int IN1 = 6; 
int IN2 = 7; 
int IN3 = 8;
int IN4 = 9;
SoftwareSerial mySerial(10,11);   //RX.TX
String receive_data;

void setup(){
  mySerial.begin(115200);
  Serial.begin(115200);
  receive_data = "";
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop(){
  while (mySerial.available() > 0) {
    receive_data = String(receive_data) + String(char(mySerial.read()));
  }
    //digitalWrite(IN1, LOW); //OFF
    //digitalWrite(IN2, LOW);
  if (String(receive_data).indexOf("dakainuanqi") >= 0) {
    Forward();
    Serial.println("打开暖气");
    receive_data = "";

  } else if (String(receive_data).indexOf("guanbinuanq") >= 0) {
    Stop();
    Serial.println("关闭暖气");
    receive_data = "";
  }
  if (String(receive_data).indexOf(String("dakaicfeng")) >= 0) {
    Reverse();
    Serial.println("打开吹风");
    receive_data = "";

  } else if (String(receive_data).indexOf(String("guanbicfeng")) >= 0) {
    Stop();
    Serial.println("关闭吹风");
    receive_data = "";
  }
  }

//==============FUNC============
void Forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);  
  Serial.println("Motor 2 Forward");
  Serial.println();
}

void Reverse()
{
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  Serial.print("Motor 2 Reverse");
  Serial.println();
  
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
  Serial.println("Motor 2 Reverse");
  Serial.println();
}

void Stop()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    Serial.print("Motor 1 Stop");
    Serial.println();
    
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    Serial.println("Motor 2 Stop");
    Serial.println();
}

