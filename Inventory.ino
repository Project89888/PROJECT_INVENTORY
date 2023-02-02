#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
const char * myWriteAPIKey = "FP1S211HSE2GHHT3";
const char *ssid =  "Phone_1_1129";     // Enter your WiFi Name
const char *pass =  "Yesh@123"; // Enter your WiFi Password
unsigned long myChannelNumber = 1886103;
WiFiClient client;

int trigPin = 12;//D6
int echoPin = 14;//D5
int Product=0;
void setup() {
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(115200);
  ThingSpeak.begin(client);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
     {
            delay(550);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
}

void loop(){
     Product1();
  }

void Product1(){
delay(500);// reading will be taken after ....miliseconds
Serial.println("\n");
int duration, distance;
    digitalWrite (trigPin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin, LOW);
    duration = pulseIn (echoPin, HIGH);
    distance = (duration/2) / 29.1;
   
    if (distance <10) {  // Change the number for long or short distances. //23
    Product=10;
    Serial.println("\n");
    Serial.print(Product); 
    Serial.print("  Product");
    }
    if (distance >10 && distance <16) {  // Change the number for long or short distances.
    Product=9;
    Serial.println("\n");
    Serial.print(Product);
    Serial.print("  Product"); 
    }
    if (distance >16 && distance <21) {  // Change the number for long or short distances.
    Product=8;
    Serial.println("\n");
    Serial.print(Product);
    Serial.print("  Product"); 
    }
    if (distance >21 && distance <26) {  // Change the number for long or short distances.
    Product=7;
    Serial.println("\n");
    Serial.print(Product);
    Serial.print("  Product"); 
    }
    if (distance >26 && distance <31) {  // Change the number for long or short distances.
    Product=6;
    Serial.println("\n");
    Serial.print(Product); 
    Serial.print("  Product");
    }
    if (distance >31 && distance <36) {  // Change the number for long or short distances.
    Product=5;
    Serial.println("\n");
    Serial.print(Product); 
    Serial.print("  Product");
    }
    if (distance >36 && distance <41) {  // Change the number for long or short distances.
    Product=4;
    Serial.println("\n");
    Serial.print(Product); 
    Serial.print("  Product");
    }
    if (distance >41 && distance <46) {  // Change the number for long or short distances.
    Product=3;
    Serial.println("\n");
    Serial.print(Product); 
    Serial.print("  Product");
    }
    if (distance >46 && distance <51) {  // Change the number for long or short distances.
    Product=2;
    Serial.println("\n");
    Serial.print(Product); 
    Serial.print("  Product");
    }
    if (distance >51 && distance <56) {  // Change the number for long or short distances.
    Product=1;
    Serial.println("\n");
    Serial.print(Product); 
    Serial.print("  Product");
    }
    if(distance >56){
    Product= 0; 
    Serial.println("\n");    
    Serial.print(Product);
    Serial.print("  Product");
    }
    ThingSpeak.writeField(myChannelNumber,1,Product, myWriteAPIKey);
 
      }