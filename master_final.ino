#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <SPI.h>

#define l1 D0
#define l2 D1
#define l3 D2
#define l4 D3

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "ULbUhXP9jViMQ-4uO-UUey6iGexd5G2q";

// Your WiFi credentials.
// Set password to "" for open networks.
byte ledPin = 2;
char ssid[] = "Next Tech Lab";               // SSID of your home WiFi
char pass[] = "78959248";               // password of your home WiFi
WiFiServer server(80);    

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1

IPAddress ip(192, 168, 0, 100);            // IP address of the server
IPAddress gateway(192,168,0,1);           // gateway of your network
IPAddress subnet(255,255,255,0);  
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
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
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
     // String request = client.readStringUntil('\r');    // receives the message from the client
     // Serial.print("From client: "); Serial.println(request);
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
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
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
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
     // String request = client.readStringUntil('\r');    // receives the message from the client
     // Serial.print("From client: "); Serial.println(request);
      client.flush();
      client.println("BACKWARD\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                // tarminates the connection with the client
  }
  }
}
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
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
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
     // String request = client.readStringUntil('\r');    // receives the message from the client
     // Serial.print("From client: "); Serial.println(request);
      client.flush();
      client.println("LEFT\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                // tarminates the connection with the client
  }
  }
}
BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
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
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
     // String request = client.readStringUntil('\r');    // receives the message from the client
     // Serial.print("From client: "); Serial.println(request);
      client.flush();
      client.println("RIGHT\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                // tarminates the connection with the client
  }
  }
}
BLYNK_WRITE(V5)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
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
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
     // String request = client.readStringUntil('\r');    // receives the message from the client
     // Serial.print("From client: "); Serial.println(request);
      client.flush();
      client.println("STOP\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                // tarminates the connection with the client
  }
  }
}

void setup()
{
  pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
pinMode(l4, OUTPUT);
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
   // Serial.begin(115200);                   // only for debug
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  server.begin();                         // starts the server
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
 /* WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
     // String request = client.readStringUntil('\r');    // receives the message from the client
     // Serial.print("From client: "); Serial.println(request);
      client.flush();
      client.println("FORWARD\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                // tarminates the connection with the client
  }*/

}
