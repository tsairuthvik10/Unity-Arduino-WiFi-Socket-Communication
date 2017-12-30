/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>

const char* ssid = "D-Link_DIR-600M";
const char* password = "12345678";
int led1 = 2;
int loopCounter=0;
IPAddress ip(192, 168, 0, 5);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);
WiFiClient client;
 char thisChar = 0;
// int timer = 0;
// int lastTimer = 0;
// int checkInterval = 100000;
//  
// boolean alreadyConnected = false;
 
  void lightOn() {
   digitalWrite(led1, HIGH);
 }
 
 void lightOff() {
   digitalWrite(led1, LOW);
 }
 
 void lightFlashOn() {
  lightOn();
       delay(50);
       lightOff();
       delay(50);
       lightOn();
       delay(50);
       lightOff();
 }
 
 void lightFlashOff() {
       lightOn();
       delay(50);
       lightOff();
       delay(50);
       lightOn();
       delay(50);
       lightOff();
       delay(50);
       lightOn();
       delay(50);
       lightOff();
       delay(50);
       lightOn();
       delay(50);
       lightOff();
 }

void setup() {
  Serial.begin(115200);
  delay(10);
    pinMode(led1, OUTPUT);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
  
}



void loop() {
  
  // Check if a client has connected
  while(client == NULL){
      client = server.available();
        lightFlashOn();
        Serial.println("new client");
  }

  // Wait until the client sends some data
  
  while(!client.available()){
    delay(1000);
    Serial.println("Waiting");
  }

//timer = millis(); // timer equals current time
//   // When the client sends the first byte, say hello:
//   if (client) { //if there is a client
//     if (!alreadyConnected) { //and its not already connected
//       client.flush();          // clead out the input buffer:
//       Serial.println("Client has connected to Arduino");
//       client.println("Hello Client, From Server!"); 
//       lightFlashOn();
//       alreadyConnected = true; // remember the client is now connected
//       
//     } 
//   } else { // if there is no client
//     
//     if (alreadyConnected){      // if there has just been a client, set alreadyConnected to false and flash the lights off
//     alreadyConnected = false;
//     lightFlashOff();
//     }
//     client.println("Light off");  // tell Unity light is off
//     alreadyConnected = false;
//     if (timer - lastTimer > checkInterval) { // if the current time minus the last time is more than the check interval
//     Serial.println("No client available"); 
//     lastTimer = timer;
//     } 
//     
//   }
      
           if (client.available()) {   // if a client is available
           thisChar = client.read();   // Read the bytes incoming from the client:
           client.flush();  
       
                if (thisChar == 49) {        // if the character is a 1
                        
                         Serial.println("Light on"); 
                          client.println("Light on"); // tell Unity light is on
                                  digitalWrite(led1, HIGH);             // switch light on
                                  return;
                  } else {
         
                          if (thisChar == 48) {      // if the character is a 0
                                 
                                 Serial.println("Light off");       // tell Unity light is off
                                 client.println("Light off");     // switch light off
                                    digitalWrite(led1, LOW);
                                    return;
       
                            } else {
                                 Serial.println(thisChar);
                                 Serial.print("incorrect command"); 
                                 //server.write("incorrect command");
                                 }
   
                           }


  // Send the response to the client


  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed

           }
       

      
           }

