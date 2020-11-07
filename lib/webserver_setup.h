#ifndef wifi_setup_h
#define wifi_setup_h

#include <Arduino.h>

#include <ArduinoJson.h>
#include <ESP8266WebServer.h>
#include <MFRC522.h>

#include "html.h"
//#include "rfid.h"

byte readcard[4];

//init webserver
ESP8266WebServer server ( 80 );

#define RST_PIN         D3         // Configurable, see typical pin layout above
#define SS_PIN          D8        // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

String indexPage(){
  return main_page;
}

String jsonApiHandler(){
  DynamicJsonBuffer jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  JsonObject& rfidData = json.createNestedObject("rfiddata");
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent() ) {
    rfidData["cardUID"] = "0000";
    rfidData["memberid"] = "123";
    rfidData["firstname"] = "john";
    rfidData["lastname"] = "Doe";
  } 
  if( ! mfrc522.PICC_ReadCardSerial() ) {
    rfidData["cardUID"] = "0000";
    rfidData["memberid"] = "123";
    rfidData["firstname"] = "john";
    rfidData["lastname"] = "Doe";
  }


  unsigned long UID_unsigned;
  UID_unsigned = mfrc522.uid.uidByte[0] << 24;
  UID_unsigned += mfrc522.uid.uidByte[1] << 16;
  UID_unsigned += mfrc522.uid.uidByte[2] << 8;
  UID_unsigned += mfrc522.uid.uidByte[3];
  rfidData["cardUID"] = UID_unsigned;
  String output;
  json.printTo(output);
  return output;

}

// Handle request for root document ("/")
void rootHandler(){
  server.send ( 200, "text/html", indexPage() );
}

// Handle request for jsonapi document ("/fishtank.json")
void apiHandler(){ 
  server.send ( 200, "application/json", jsonApiHandler() );
}
#endif
