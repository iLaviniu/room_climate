#ifndef ETHERNET_SERVICE
#define ETHERNET_SERVICE

#include "Types.h"


/*constants*/





/*defines*/





/*types*/




/*functions*/
void sendDataHttpRequestPHP(WiFiClient *clientLocal, char * localHttpResponse, Dht11SensorValues dht11SensorValuesLocal, Bmp280SensorValues bmp280SensorValuesLocal, unsigned long periodMinutesDataSending);
void sendStatusHttpRequestPHP(WiFiClient *clientLocal, char * localHttpResponse);

void sendDataHttpRequestPHP(WiFiClient *clientLocal, char * localHttpResponse, Dht11SensorValues dht11SensorValuesLocal, Bmp280SensorValues bmp280SensorValuesLocal, unsigned long periodMinutesDataSending) {
  char failedMessage[] = "connection_failed!\0";
  byte failedMessageIndex;
  bool startReading = false;
  char * periodicityMinutesChar = ULongToArrayChar(periodMinutesDataSending);
  unsigned int contentLength = calculateHttpContentLength(dht11SensorValuesLocal, bmp280SensorValuesLocal, periodicityMinutesChar);
  char * contentLengthChar = UIntToArrayChar(contentLength);
  char c;
  int responseCounter = 0;

  /*connect to web server on port HTTP_PORT:*/
  if(clientLocal->connect(HOST_NAME, HTTP_PORT)) {

    clientLocal->print(HTTP_METHOD);
    clientLocal->print(" ");
    clientLocal->print(DATA_PATH_NAME_PHP);
    clientLocal->print(" ");
    clientLocal->println("HTTP/1.1");
    clientLocal->print("Host: ");
    clientLocal->println(HOST_NAME);
    clientLocal->println("Connection: close");
    clientLocal->println("Content-Type: text/html");
    clientLocal->print("Content-Length: ");
    clientLocal->println(contentLengthChar);
    clientLocal->println(""); /*end HTTP header*/

    /*send HTTP body*/
    clientLocal->print(JSON_LINE_1);
    clientLocal->print(bmp280SensorValuesLocal.celsius);
    clientLocal->print(JSON_LINE_2);
    clientLocal->print(bmp280SensorValuesLocal.fahrenheit);
    clientLocal->print(JSON_LINE_3);
    clientLocal->print(bmp280SensorValuesLocal.pascal);
    clientLocal->print(JSON_LINE_4);
    clientLocal->print(bmp280SensorValuesLocal.hectoPascal);
    clientLocal->print(JSON_LINE_5);
    clientLocal->print(dht11SensorValuesLocal.celsius);
    clientLocal->print(JSON_LINE_6);
    clientLocal->print(dht11SensorValuesLocal.fahrenheit);
    clientLocal->print(JSON_LINE_7);
    clientLocal->print(dht11SensorValuesLocal.humidity);
    clientLocal->print(JSON_LINE_8);
    clientLocal->print(periodicityMinutesChar);
    clientLocal->println(JSON_LINE_9);

    /*wait for the response*/
    while(!clientLocal->available());
    
    while(clientLocal->available()) {
      
      c = clientLocal->read();

      if(c == '>') {
        startReading = false;
      }

      if(startReading == true) {
        responseCounter++;

        if(responseCounter <= 35) {
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

  /*free all allocated memory for contentLengthChar and periodicityMinutesChar*/
  free(contentLengthChar);
  free(periodicityMinutesChar);
}

void sendStatusHttpRequestPHP(WiFiClient *clientLocal, char * localHttpResponse) {
  char failedMessage[] = "connection_failed!\0";
  byte failedMessageIndex;
  bool startReading = false;
  char c;
  int responseCounter = 0;

  /*connect to web server on port HTTP_PORT:*/
  if(clientLocal->connect(HOST_NAME, HTTP_PORT)) {

    clientLocal->print(HTTP_METHOD);
    clientLocal->print(" ");
    clientLocal->print(STATUS_PATH_NAME_PHP);
    clientLocal->print(" ");
    clientLocal->println("HTTP/1.1");
    clientLocal->print("Host: ");
    clientLocal->println(HOST_NAME);
    clientLocal->println("Connection: close");
    clientLocal->println("Content-Type: text/html");
    clientLocal->println("Content-Length: 24");
    clientLocal->println(""); /*end HTTP header*/

    /*send HTTP body*/
    clientLocal->println("{\"ARDUINO_STATUS\": \"OK\"}");

    /*wait for the response*/
    while(!clientLocal->available());

    while(clientLocal->available()) {

      c = clientLocal->read();

      if(c == '>') {
        startReading = false;
      }

      if(startReading == true) {
        responseCounter++;

        if(responseCounter <= 35) {
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