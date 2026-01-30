#ifndef ETHERNET_SERVICE_NODE_JS
#define ETHERNET_SERVICE_NODE_JS

#include <ArduinoJson.h>

/*constants*/





/*defines*/





/*types*/




/*functions*/
void sendDataHttpRequestNodeJs(WiFiClient *clientNodeJs, char * localHttpResponse, Dht11SensorValues dht11SensorValuesLocal, Bmp280SensorValues bmp280SensorValuesLocal);
void sendStatusHttpRequestNodeJs(WiFiClient *clientNodeJs, char * localHttpResponse);

void sendDataHttpRequestNodeJs(WiFiClient *clientNodeJs, char * localHttpResponse, Dht11SensorValues dht11SensorValuesLocal, Bmp280SensorValues bmp280SensorValuesLocal)
{
  char failedMessage[] = "connection_failed!\0";
  byte failedMessageIndex;
  char c;
  bool startReading = false;
  int responseCounter = 0;

  StaticJsonDocument<300> doc;
  doc["request_key"]       = "protected_data";
  doc["bmp_280_temp_c"]    = bmp280SensorValuesLocal.celsius;
  doc["bmp_280_temp_f"]    = bmp280SensorValuesLocal.fahrenheit;
  doc["bmp_280_atmo_pa"]   = bmp280SensorValuesLocal.pascal;
  doc["bmp_280_atmo_hpa"]  = bmp280SensorValuesLocal.hectoPascal;
  doc["dht_11_temp_c"]     = dht11SensorValuesLocal.celsius;
  doc["dht_11_temp_f"]     = dht11SensorValuesLocal.fahrenheit;
  doc["dht_11_humidity"]   = dht11SensorValuesLocal.humidity;
  String jsonPayload;
  serializeJson(doc, jsonPayload);

  /*connect to web server on port HTTP_PORT:*/
  if(clientNodeJs->connect(HOST_NAME, HTTP_PORT)) {

    clientNodeJs->print(HTTP_METHOD);
    clientNodeJs->print(" ");
    clientNodeJs->print(SET_SENSORS_DATA_PATH_NODEJS);
    clientNodeJs->print(" ");
    clientNodeJs->println("HTTP/1.1");
    clientNodeJs->print("Host: ");
    clientNodeJs->println(HOST_NAME);
    clientNodeJs->println("Connection: close");
    clientNodeJs->println("Content-Type: application/json");
    clientNodeJs->print("Content-Length: ");
    clientNodeJs->println(jsonPayload.length());
    clientNodeJs->println(""); /*end HTTP header*/

    /*send HTTP body*/
    clientNodeJs->println(jsonPayload);

    /*wait for the response*/
    while(!clientNodeJs->available());
    
    while(clientNodeJs->available()) {

      c = clientNodeJs->read();

      if(c == '>') {
        startReading = false;
      }

      if(startReading == true) {
        responseCounter++;

        if(responseCounter <= 130) {
          *localHttpResponse = c;
          localHttpResponse++;
          *localHttpResponse = '\0';
        } else {
          startReading = false;
        }
      }

      if(c == '<') {
        startReading = true;
      }
    }

  } else {
    /*if not connected:*/
    failedMessageIndex = 0;
    while(failedMessage[failedMessageIndex] != '\0') {
      *localHttpResponse = failedMessage[failedMessageIndex];
      localHttpResponse++;
      *localHttpResponse = '\0';
      failedMessageIndex++;
    }
  }
}

void sendStatusHttpRequestNodeJs(WiFiClient *clientNodeJs, char * localHttpResponse)
{
  char failedMessage[] = "connection_failed!\0";
  byte failedMessageIndex;
  char c;
  bool startReading = false;
  int responseCounter = 0;

  StaticJsonDocument<100> doc;
  doc["request_key"] = "protected_data";
  doc["arduino_status"] = "ok";
  String jsonPayload;
  serializeJson(doc, jsonPayload);

  /*connect to web server on port HTTP_PORT:*/
  if(clientNodeJs->connect(HOST_NAME, HTTP_PORT)) {

    clientNodeJs->print(HTTP_METHOD);
    clientNodeJs->print(" ");
    clientNodeJs->print(SET_ARDUINO_STATUS_PATH_NODEJS);
    clientNodeJs->print(" ");
    clientNodeJs->println("HTTP/1.1");
    clientNodeJs->print("Host: ");
    clientNodeJs->println(HOST_NAME);
    clientNodeJs->println("Connection: close");
    clientNodeJs->println("Content-Type: application/json");
    clientNodeJs->print("Content-Length: ");
    clientNodeJs->println(jsonPayload.length());
    clientNodeJs->println(""); /*end HTTP header*/

    /*send HTTP body*/
    clientNodeJs->println(jsonPayload);

    /*wait for the response*/
    while(!clientNodeJs->available());

    while(clientNodeJs->available()) {
      
      c = clientNodeJs->read();

      if(c == '>') {
        startReading = false;
      }

      if(startReading == true) {
        responseCounter++;

        if(responseCounter <= 130) {
          *localHttpResponse = c;
          localHttpResponse++;
          *localHttpResponse = '\0';
        } else {
          startReading = false;
        }
      }

      if(c == '<') {
        startReading = true;
      }

    }
  } else {
    /*if not connected:*/
    failedMessageIndex = 0;
    while(failedMessage[failedMessageIndex] != '\0') {
      *localHttpResponse = failedMessage[failedMessageIndex];
      localHttpResponse++;
      *localHttpResponse = '\0';
      failedMessageIndex++;
    }
  }
}

#endif /*include protection*/