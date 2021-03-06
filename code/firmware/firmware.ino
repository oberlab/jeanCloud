#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <FastLED.h>
#include <SPIFFS.h>
#include <TM1637Display.h>
#include <WiFi.h>
#include <time.h>
#include "./src/hardware/LightController.h"
#include "./src/network/MDNSController.h"
#include "./src/AlarmController.h"
#include "./src/PasswordController.h"
#include "./src/hardware/System.h"
#include "./src/Webserver.h"

char *name = "Konsti's JeanCloud";
char *hostname = "jeancloud";
char *passwort = "passwort123";

// Define the connections pins for display:
#define CLK 18
#define DIO 5

// Create display object:
TM1637Display display = TM1637Display(CLK, DIO);

// time settings
#define MY_NTP_SERVER "de.pool.ntp.org"  
#define MY_TZ "CET-1CEST,M3.5.0/02,M10.5.0/03" // https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv


MDNSController mdnsController = MDNSController(hostname, name);
LightController lightController = LightController();
AlarmController alarmController = AlarmController(&lightController);
Webserver webserver = Webserver(80, lightController, &alarmController, &display);
Webserver apWebserver = Webserver(80, lightController, &alarmController, &display);

bool isSetup = false;

struct Button
{
  uint8_t pin;
  uint32_t numberKeyPresses;
  bool pressed;
};

Button buttonRight = {12, 0, false};
Button buttonLeft = {33, 0, false};

void IRAM_ATTR buttonRightIRS()
{
  buttonRight.numberKeyPresses += 1;
  buttonRight.pressed = true;
}

void IRAM_ATTR buttonLeftIRS()
{
  buttonLeft.numberKeyPresses += 1;
  buttonLeft.pressed = true;
}

void setup()
{
  Serial.begin(115200);

  // setup display
  display.setBrightness(7); // Set the display brightness (0-7)
  display.clear();          // Clear the display

  System::initFS();

  PasswordController passwordController = PasswordController("/wifi.txt");

  pinMode(buttonRight.pin, INPUT_PULLUP);
  pinMode(buttonLeft.pin, INPUT_PULLUP);
  attachInterrupt(buttonRight.pin, buttonRightIRS, FALLING);
  attachInterrupt(buttonLeft.pin, buttonLeftIRS, FALLING);

  if (!passwordController.isExisting())
  {
    isSetup = true;
  }
  else
  {
    isSetup = !System::connectToWifi(&passwordController);
  }

  if (isSetup)
  {
    WiFi.disconnect();
    WiFi.mode(WIFI_AP);
    WiFi.softAP(name, passwort);

    mdnsController.setup();

    apWebserver.setupAP();
    apWebserver.begin();
    Serial.println(WiFi.softAPIP());
  }

  if (isSetup)
  {
    return;
  }

  // Setup jeancloud.local domain for local network
  mdnsController.setup();

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Init and get the time
  configTzTime(MY_TZ, MY_NTP_SERVER);

  struct tm timeinfo;

  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    display.showNumberDec(0);
    return;
  }

  char timeHour[3];
  strftime(timeHour, 3, "%H", &timeinfo);
  char timeMinute[3];
  strftime(timeMinute, 3, "%M", &timeinfo);

  int displayTime = atoi(timeHour) * 100 + atoi(timeMinute);
  Serial.println(displayTime);
  display.showNumberDecEx(displayTime, 0b11100000, true); //Display the time value;

  webserver.setup();
  webserver.begin();
}

void loop()
{

  // Don't Execute anything if it is setting up
  if (isSetup)
  {
    lightController.bounce();
    return;
  }

  EVERY_N_MILLIS(600)
  {
    if (buttonRight.pressed && buttonLeft.pressed)
    {
      alarmController.stopAlarm();
    }
    else
    {
      if (buttonRight.pressed)
      {
        alarmController.snooze();
        buttonRight.pressed = false;
      }

      if (buttonLeft.pressed)
      {
        alarmController.snooze();
        buttonLeft.pressed = false;
      }
    }
  }

  // put your main code here, to run repeatedly:
  EVERY_N_MILLIS(200)
  {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
      Serial.println("Failed to obtain time");
      display.showNumberDec(0);
      return;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

    char timeHour[3];
    strftime(timeHour, 3, "%H", &timeinfo);
    char timeMinute[3];
    strftime(timeMinute, 3, "%M", &timeinfo);
    int displayTime = atoi(timeHour) * 100 + atoi(timeMinute);
    display.showNumberDecEx(displayTime, 0b11100000, true); //Display the time value;
    alarmController.loop(atoi(timeHour), atoi(timeMinute));
  }
}
