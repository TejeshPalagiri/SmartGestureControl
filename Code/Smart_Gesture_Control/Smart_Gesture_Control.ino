int echo = 5;
int trig = 4;
float cm = 0;
long duration = 0;
#define BLYNK_PRINT Serial  //Defines the object that is used for printing(To get the information about the HDK whether it is connected or not)
#include<BlynkSimpleEsp8266.h>  //To use BLYNK app functionalities
#include<ESP8266WiFi.h> //To connect to WiFi
char auth[] = "Qt1dzc1BzY4HGhIXUJQpRmnzRXI7uN1g"; //The authentication code we got in mail to connect with the app
char ssid[] = "JioFi_10319F1";  //Wi-Fi Network name
char pass[] = "359@tejesh";     //EncryptionCode(Password)
BLYNK_WRITE(V1)
{
  uint16_t x = param[0].asInt();    //Getting the x co-ordinate from the joystick
  uint16_t y = param[1].asInt();    //Getting the y co-ordinate from the joystick
  if(x == 1023)            
  {
    Serial.println("Right");
  }
  if(x == 0)
  {
    Serial.println("Left");
  }
  if(y == 0){
    Serial.println("Down");
  }
  if(y == 1023)
  {
    Serial.println("Up");
  }
  
}
BLYNK_WRITE(V2)
{
  if(param.asInt() == 1)
  {
    Serial.println("mouseleft");
  }
}
BLYNK_WRITE(V3)
{
  if(param.asInt() == 1)
  {
    Serial.println("mouseright");
  }
}
BLYNK_WRITE(V4)
{
  if(param.asInt() == 1)
  {
    Serial.println("stop");
  }
}
BLYNK_WRITE(V5)
{
  if(param.asInt() == 1)
  {
    Serial.println("a");
  }
}
BLYNK_WRITE(V6)
{
  if(param.asInt() == 1)
  {
    Serial.println("delete");
  }
}
BLYNK_WRITE(V7)
{
  if(param.asInt() == 1)
  {
    Serial.println("enter");
  }
}
BLYNK_WRITE(V8)
{
  if(param.asInt() == 1)
  {
    Serial.println("lock");
  }
}

void setup() {
  Serial.begin(115200);             //Starting the serial monitor to get the data that is bieng sent by the Octabrix
  Blynk.begin(auth,ssid,pass);      //Connecting the Octabrix to the wifi
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}  
     
void loop() {
  Blynk.run();        //It makes to get the input from the Blynk App
  BLYNK_WRITE(V1);    //Data we got from the Joystick will be sent to the function
  BLYNK_WRITE(V2);    //Left Click of mouse
  BLYNK_WRITE(V3);    //Right Click of mouse
  BLYNK_WRITE(V4);    //Space
  BLYNK_WRITE(V5);    //Getting some Text
  BLYNK_WRITE(V6);    //Delete Key
  BLYNK_WRITE(V7);    //Enter Key
  BLYNK_WRITE(V8);
  digitalWrite(trig,LOW);
  delay(20);
  digitalWrite(trig,HIGH);
  delay(20);
  digitalWrite(trig,LOW);
  pinMode(echo,INPUT);
  duration=pulseIn(echo,HIGH);
  cm=(duration/2)*0.0343;
  //Serial.println(cm);
  if(cm < 15 && cm > 0)
  {
    Serial.println("stop");delay(1000);
  }
  if(cm > 15 && cm < 30)
  {
    Serial.println("next");delay(1000);
  }
  if(cm > 30)
  {
    //Serial.println("lock");delay(1000);
  }
}
