#include <ESP8266SSDP.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <SPI.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>


#include "lib/webserver_setup.h"

String hostname="CardProgrammer";

void setup() {
  WiFi.hostname( hostname );
  WiFiManager wifiManager;
  Serial.begin(115200
 );        // Initialize serial communications with the PC
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
  wifiManager.setBreakAfterConfig(true);
  if (!wifiManager.autoConnect("CardProgrammer")) {
    Serial.println("failed to connect, we will fire up config mode");
    delay(3000);
    wifiManager.startConfigPortal("CardProgrammer");
    delay(5000);
  }

  Serial.print ( "IP address: " ); Serial.println ( WiFi.localIP() );
  Serial.println(F("FabLab Bruchsal RFID Programmer "));
  server.on ( "/", rootHandler );
  server.on ( "/rfiddata.json", apiHandler );
  server.begin();
  Serial.println ( "HTTP server started" );
}

void loop() {
  server.handleClient();
}
