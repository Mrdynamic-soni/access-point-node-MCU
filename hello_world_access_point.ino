#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include "webpahe.h"
const char* ssid = "realme";
const char* pass = "qwerty12345";

IPAddress staticIP(192,168,43,245);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

void setup()
{
  Serial.begin(115200);
  delay(20);

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(staticIP,NULL,subnet);
  WiFi.softAP(ssid,pass);

  
  server.begin();

  IPAddress ServerIP = WiFi.softAPIP();
  Serial.print("\Server IP is: ");

  server.on("/",handleRoot);

  server.begin();
  Serial.println("HTTP server started");
} 
void loop(){
  server.handleClient();
}
void handleRoot(){
  server.send(200, "text/html", webPahe);
}
