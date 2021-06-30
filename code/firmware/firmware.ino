#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "./src/LightController.h"
#include "./src/Webserver.h"
#include <FastLED.h>
#include <TM1637Display.h>
#include <WiFi.h>
#include "SPIFFS.h"


const char* ssid = "ALK_mobil";
const char* password = "urlaubingseng20";

// Define the connections pins for display:
#define CLK 18
#define DIO 5

// Create display object:
TM1637Display display = TM1637Display(CLK, DIO);

// time settings
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 7200;

LightController lightController = LightController();
Webserver webserver = Webserver(lightController);

void initFS() {
  if (!SPIFFS.begin()) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  else{
   Serial.println("SPIFFS mounted successfully");
  }
}

void setup() {
    Serial.begin(115200);

     // setup display
    display.setBrightness(7); // Set the display brightness (0-7)
    display.clear(); // Clear the display

    initFS();

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi..");
    }

    // Print ESP Local IP Address
    Serial.println(WiFi.localIP());

    // Init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    struct tm timeinfo;

    if(!getLocalTime(&timeinfo)){
      Serial.println("Failed to obtain time");
      display.showNumberDec(0);
      return;
    }

    char timeHour[3];
    strftime(timeHour,3, "%H", &timeinfo);
    char timeMinute[3];
    strftime(timeMinute,3, "%M", &timeinfo);

    int displayTime = atoi(timeHour)*100 + atoi(timeMinute);
    Serial.println(displayTime);
    display.showNumberDecEx(displayTime, 0b11100000, true); //Display the time value;

    webserver.setup();
    webserver.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    display.showNumberDec(0);
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  
  char timeHour[3];
  strftime(timeHour,3, "%H", &timeinfo);
  char timeMinute[3];
  strftime(timeMinute,3, "%M", &timeinfo);
  int displayTime = atoi(timeHour)*100 + atoi(timeMinute);
  Serial.println(displayTime);
  display.showNumberDecEx(displayTime, 0b11100000, true); //Display the time value;
  delay(1000);

}
