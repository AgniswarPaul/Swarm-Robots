#include <SPI.h>
#include <ESP8266WiFi.h>

#define l1 D0
#define l2 D1
#define l3 D2
#define l4 D3

byte ledPin = 2;
char ssid[] = "Next Tech Lab";           
char pass[] = "78959248";           

unsigned long askTimer = 0;

IPAddress server(192,168,0,100);      //ip address of master and slave should be same
WiFiClient client;

void setup() {
  Serial.begin(115200);               
  WiFi.begin(ssid, pass);           
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
pinMode(l4, OUTPUT);
pinMode(ledPin, OUTPUT);
}

void loop () {
  client.connect(server, 80);   
  digitalWrite(ledPin, LOW);    
  Serial.println(".");
  
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
  client.flush();
  digitalWrite(ledPin, HIGH);
 
  if (answer == "FORWARD" ){
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,LOW);
  digitalWrite(l4,HIGH);
  }
  else if (answer == "BACKWARD"){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,LOW);
  }
  else if (answer == "LEFT"){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,LOW);
  }
  else if (answer =="RIGHT"){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,HIGH);
  }
  else if (answer =="STOP"){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,HIGH);
  }
}
