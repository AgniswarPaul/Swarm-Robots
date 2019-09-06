#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <SPI.h>

#define l1 D0
#define l2 D1
#define l3 D2
#define l4 D3

char auth[] = "ULbUhXP9jViMQ-4uO-UUey6iGexd5G2q"; //auth token of blynk

byte ledPin = 2;
char ssid[] = "Next Tech Lab";  
char pass[] = "78959248";               
WiFiServer server(80);    //port

IPAddress ip(192, 168, 0, 100);  //ip address of master and slave should be same
IPAddress gateway(192,168,0,1);  //gateway should be same      
IPAddress subnet(255,255,255,0);  //subnet should be same
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
  
  if (pinValue == 1){
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,LOW);
  digitalWrite(l4,HIGH);
   WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW);  
      Serial.println(".");

      client.flush();
      client.println("FORWARD\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                // tarminates the connection with the client
  }
  } 
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
  Serial.print("V2 Slider value is: ");
  Serial.println(pinValue);
  
  if (pinValue == 1){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,LOW);
   WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW); 
      Serial.println(".");
      client.flush();
      client.println("BACKWARD\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();         
  }
  }
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V3 to a variable
  Serial.print("V3 Slider value is: ");
  Serial.println(pinValue);
  
  if (pinValue == 1){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,LOW);
   WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW);  
      Serial.println(".");
      client.flush();
      client.println("LEFT\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                  
  }
  }
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V4 to a variable

  Serial.print("V4 Slider value is: ");
  Serial.println(pinValue);
  if (pinValue == 1){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,HIGH);
   WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW); 
      Serial.println(".");
      client.flush();
      client.println("RIGHT\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();          
  }
  }
}

BLYNK_WRITE(V5)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V5 to a variable
  Serial.print("V5 Slider value is: ");
  Serial.println(pinValue);
  
  if (pinValue == 1){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,HIGH);
   WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW);  
      Serial.println(".");
      client.flush();
      client.println("STOP\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();     
  }
  }
}

void setup()
{
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  WiFi.config(ip, gateway, subnet);      
  WiFi.begin(ssid, pass);         
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    }
  server.begin();                        
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  Blynk.run();
  BLYNK_WRITE(V1);
  BLYNK_WRITE(V2);
  BLYNK_WRITE(V3);
  BLYNK_WRITE(V4);
  BLYNK_WRITE(V5);
}
