#include <SPI.h>
#include <ESP8266WiFi.h>

#define l1 D0
#define l2 D1
#define l3 D2
#define l4 D3

byte ledPin = 2;
char ssid[] = "Next Tech Lab";           // SSID of your home WiFi
char pass[] = "78959248";            // password of your home WiFi

unsigned long askTimer = 0;

IPAddress server(192,168,0,100);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);               // only for debug
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
/*  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());    // Network parameters
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());*/
    pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
pinMode(l4, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop () {
  client.connect(server, 80);   // Connection to the server
  digitalWrite(ledPin, LOW);    // to show the communication only (inverted logic)
  Serial.println(".");
  //client.println("Hello server! Are you sleeping?\r");  // sends the message to the server
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
  client.flush();
  digitalWrite(ledPin, HIGH);
  //delay(2000);                  // client will trigger the communication after two seconds

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
