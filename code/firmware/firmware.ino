#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "./src/LightController.h"
#include "./src/Webserver.h"
#include <FastLED.h>
#include <WiFi.h>
#include "SPIFFS.h"


const char* ssid = "ALK_mobil";
const char* password = "urlaubingseng20";

// fastLED configuration:
#define NUM_LEDS 27        // set number of LEDs here
#define LED_PIN 14
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; // Define the array of ledsw

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

    initFS();

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi..");
    }

    // Print ESP Local IP Address
    Serial.println(WiFi.localIP());

    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    fill_solid( leds, NUM_LEDS, CRGB(lightController.getRed(), lightController.getGreen(), lightController.getBlue()));
    FastLED.setBrightness(255);
    FastLED.show();

    webserver.setup();
    webserver.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
