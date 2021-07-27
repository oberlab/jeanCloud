#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include "./src/LightController.h"
#include "./src/Webserver.h"
#include "./src/AlarmController.h"
#include "./src/PasswordController.h"
#include <FastLED.h>
#include <TM1637Display.h>
#include <WiFi.h>
#include "SPIFFS.h"

char* name = "Alex's JeanCloud";
char* passwort = "passwort123";

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
AlarmController alarmController = AlarmController();
Webserver webserver = Webserver(80, lightController, &alarmController);
Webserver apWebserver = Webserver(80, lightController, &alarmController);

bool isSetup = false;

void initFS() {
  if (!SPIFFS.begin()) {
    Serial.println("An error has occurred while mounting SPIFFS");
  } else {
    Serial.println("SPIFFS mounted successfully");
  }
}

bool connectToWifi(PasswordController *passwordController) {
    int connectionTries = 0;
    WiFi.begin(passwordController->getSSID().c_str(), passwordController->getPassword().c_str());
    while (WiFi.status() != WL_CONNECTED && connectionTries <= 20) {
      delay(1000);
      Serial.println(passwordController->getSSID().c_str());
      Serial.println(passwordController->getPassword().c_str());
      Serial.print("Connecting to WiFi.. Try: " + connectionTries);
      Serial.println(connectionTries);
      connectionTries++;
    }

    return WiFi.status() == WL_CONNECTED;
}

void setup() {
    Serial.begin(115200);

     // setup display
    display.setBrightness(7); // Set the display brightness (0-7)
    display.clear(); // Clear the display

    initFS();

    PasswordController passwordController = PasswordController("/wifi.txt");
    
    if (!passwordController.isExisting()) {
      isSetup = true;
    } else {
      isSetup = !connectToWifi(&passwordController);
    }

    if (isSetup) {
      WiFi.disconnect();
      WiFi.mode(WIFI_AP);
      WiFi.softAP(name, passwort);

      apWebserver.setupAP();
      apWebserver.begin();
      Serial.println(WiFi.softAPIP());
    }

    if (isSetup) { return; }

    if (!MDNS.begin("jeanCloud")) {
        Serial.println("Error setting up MDNS responder!");
        while(1) {
            delay(1000);
        }
    }
    Serial.println("mDNS responder started");
  
    MDNS.setInstanceName(name);
    MDNS.addService("http", "tcp", 80);
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

  // Don't Execute anything if it is setting up
  if (isSetup) { return; }

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
  alarmController.makeNoise(alarmController.checkAlarm(atoi(timeHour), atoi(timeMinute), alarmController.getAlarmStatus()));

  delay(500);
}
