#ifndef CONSTANTS_DEFINES_TYPES
#define CONSTANTS_DEFINES_TYPES

#include "WiFiS3.h"
#include "Secrets.h"

/*variables*/
uint8_t                 ETHERNET_MAC[]     = { 0xDE, 0x77, 0x42, 0x33, 0x07, 0xED };

/*constants*/
const int                     HTTP_PORT          =  443;
const char                    HTTP_METHOD[]      = "POST";
const char                    HOST_NAME[]        = "www.nestinbase.com";

/*PHP Application*/
const char                    DATA_PATH_NAME_PHP[]   = "/roomclimate/incoming/redirection_data.php";
const char                    STATUS_PATH_NAME_PHP[] = "/roomclimate/incoming/redirection_status.php";
const char                    JSON_LINE_1[]      = "{\"DATA_STATUS\": \"NEW_DATA\",\"BMP280\": {\"temperature\": {\"celsius\": \"";
const unsigned int            JSON_LINE_1_SIZE   = strlen(JSON_LINE_1);
const char                    JSON_LINE_2[]      = "\",\"fahrenheit\": \"";
const unsigned int            JSON_LINE_2_SIZE   = strlen(JSON_LINE_2);
const char                    JSON_LINE_3[]      = "\"},\"atmospheric_pressure\": {\"Pa\": \"";
const unsigned int            JSON_LINE_3_SIZE   = strlen(JSON_LINE_3);
const char                    JSON_LINE_4[]      = "\",\"hPa\": \"";
const unsigned int            JSON_LINE_4_SIZE   = strlen(JSON_LINE_4);
const char                    JSON_LINE_5[]      = "\"}},\"DHT11\": {\"temperature\": {\"celsius\": \"";
const unsigned int            JSON_LINE_5_SIZE   = strlen(JSON_LINE_5);
const char                    JSON_LINE_6[]      = "\",\"fahrenheit\": \"";
const unsigned int            JSON_LINE_6_SIZE   = strlen(JSON_LINE_6);
const char                    JSON_LINE_7[]      = "\"},\"humidity\": {\"%\": \"";
const unsigned int            JSON_LINE_7_SIZE   = strlen(JSON_LINE_7);
const char                    JSON_LINE_8[]      = "\"}},\"PERIODICITY_MINUTES\": \"";
const unsigned int            JSON_LINE_8_SIZE   = strlen(JSON_LINE_8);
const char                    JSON_LINE_9[]      = "\"}";
const unsigned int            JSON_LINE_9_SIZE   = strlen(JSON_LINE_9);
/***********************************************************************************************************/

/*NodeJs Application*/
const char                    SET_SENSORS_DATA_PATH_NODEJS[]   = "/datalogger/set_sensors_data";
const char                    SET_ARDUINO_STATUS_PATH_NODEJS[] = "/datalogger/set_arduino_status";
/***********************************************************************************************************/

const char *                  CA_CERT =\
"-----BEGIN CERTIFICATE-----\n"\
"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\n"\
"-----END CERTIFICATE-----\n";

byte MATRIX_OUTPUT_STATUS_OK[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte MATRIX_OUTPUT_WIFI_CONNECTION_FAILED[8][12] = {
  { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0 }
};

byte MATRIX_OUTPUT_SETUP_FAILED[8][12] = {
  { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
  { 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0 }
};

/*defines*/
#define SERIAL_MONITOR_BOUD_RATE       (unsigned long)9600
#define DHTPIN                         (unsigned int)2
#define DHTTYPE                        (uint8_t)DHT11             


/*types*/
struct Dht11SensorValues {
  char * celsius;
  char * fahrenheit;
  char * humidity;
};

struct Bmp280SensorValues {
  char * celsius;
  char * fahrenheit;
  char * pascal;
  char * hectoPascal;
};


/*functions*/
unsigned int calculateHttpContentLength(Dht11SensorValues dht11SensorValues, Bmp280SensorValues bmp280SensorValues, char * periodicityMinutesChar);
char * FloatToArrayChar(float valueAsFloat);
byte CharArraySize(char * arrayChar);
char * UIntToArrayChar(unsigned int number);
char * ULongToArrayChar(unsigned long number);
void copyMemmoryToBuffer(char * httpResponseStart, char * buffer);

unsigned int calculateHttpContentLength(Dht11SensorValues dht11SensorValues, Bmp280SensorValues bmp280SensorValues, char * periodicityMinutesChar) {
  int length = 0;
  
  length += JSON_LINE_1_SIZE;
  length += JSON_LINE_2_SIZE;
  length += JSON_LINE_3_SIZE;
  length += JSON_LINE_4_SIZE;
  length += JSON_LINE_5_SIZE;
  length += JSON_LINE_6_SIZE;
  length += JSON_LINE_7_SIZE;
  length += JSON_LINE_8_SIZE;
  length += JSON_LINE_9_SIZE;

  length += (int)CharArraySize(dht11SensorValues.celsius);
  length += (int)CharArraySize(dht11SensorValues.fahrenheit);
  length += (int)CharArraySize(dht11SensorValues.humidity);
  length += (int)CharArraySize(bmp280SensorValues.celsius);
  length += (int)CharArraySize(bmp280SensorValues.fahrenheit);
  length += (int)CharArraySize(bmp280SensorValues.pascal);
  length += (int)CharArraySize(bmp280SensorValues.hectoPascal);
  length += (int)CharArraySize(periodicityMinutesChar);

  return length;
}

char * FloatToArrayChar(float valueAsFloat) {
  char * result = (char*)malloc(16 * sizeof(char));
  double valDouble = (double)(valueAsFloat);
  double fractPart;
  double intPart;
  fractPart = modf(valDouble, &intPart);
  double twoDecimals = abs(fractPart * 100); /*100 because two decimals needed*/
  sprintf(result, "%ld.%ld", (long)intPart, (long)twoDecimals);
  return result;
}

byte CharArraySize(char * arrayChar) {
  byte index = 0;
  while(arrayChar[index] != '\0') {
    index++;
  }
  return index;
}

char * UIntToArrayChar(unsigned int number) {
  char * result = (char*)malloc(10 * sizeof(char));
  sprintf(result, "%d", number);
  return result;
}

char * ULongToArrayChar(unsigned long number) {
  char * result = (char*)malloc(10 * sizeof(char));
  sprintf(result, "%lu", number);
  return result;
}

void copyMemmoryToBuffer(char * httpResponseStart, char * buffer) {

  while((*httpResponseStart) != '\0') {
    *buffer = *httpResponseStart;
    httpResponseStart++;
    buffer++;
    *buffer = '\0';
  }

}

#endif /*include protection*/