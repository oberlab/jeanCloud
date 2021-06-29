// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>

// Replace with your network credentials
const char* ssid = "ALK_mobil";
const char* password = "urlaubingseng20";

const int output = 2;

String sliderValue = "0";
String sliderValue2 = "0";
String sliderValue3 = "0";
String sliderValue4 = "0";

const char* PARAM_INPUT = "value";

// fastLED configuration:
#define NUM_LEDS 27        // set number of LEDs here
#define LED_PIN 14        
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; // Define the array of leds

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>ESP Web Server</title>
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 2.3rem;}
    p {font-size: 1.9rem;}
    body {max-width: 400px; margin:0px auto; padding-bottom: 25px;}
    .slider { -webkit-appearance: none; margin: 14px; width: 360px; height: 25px; background: #FFD65C;
      outline: none; -webkit-transition: .2s; transition: opacity .2s;}
    .slider::-webkit-slider-thumb {-webkit-appearance: none; appearance: none; width: 35px; height: 35px; background: #003249; cursor: pointer;}
    .slider::-moz-range-thumb { width: 35px; height: 35px; background: #003249; cursor: pointer; } 
  </style>
</head>
<body>
  <h2>JeanCloud</h2>
  <p> Helligkeit <span id="textSliderValue">%SLIDERVALUE%</span></p>
  <p><input type="range" onchange="updateSliderPWM(this)" id="pwmSlider" min="0" max="255" value="%SLIDERVALUE%" step="1" class="slider"></p>
  <p> Rot <span id="textSliderValue2">%SLIDERVALUE2%</span></p>
  <p><input type="range" onchange="updateSliderPWM2(this)" id="pwmSlider2" min="0" max="255" value="%SLIDERVALUE2%" step="1" class="slider"></p>
  <p> Gruen <span id="textSliderValue3">%SLIDERVALUE3%</span></p>
  <p><input type="range" onchange="updateSliderPWM3(this)" id="pwmSlider3" min="0" max="255" value="%SLIDERVALUE3%" step="1" class="slider"></p>
  <p> Blau <span id="textSliderValue4">%SLIDERVALUE4%</span></p>
  <p><input type="range" onchange="updateSliderPWM4(this)" id="pwmSlider4" min="0" max="255" value="%SLIDERVALUE4%" step="1" class="slider"></p>
<script>
function updateSliderPWM(element) {
  var sliderValue = document.getElementById("pwmSlider").value;
  document.getElementById("textSliderValue").innerHTML = sliderValue;
  console.log(sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider?value="+sliderValue, true);
  xhr.send();
}
function updateSliderPWM2(element) {
  var sliderValue2 = document.getElementById("pwmSlider2").value;
  document.getElementById("textSliderValue2").innerHTML = sliderValue2;
  console.log(sliderValue2);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider2?value="+sliderValue2, true);
  xhr.send();
}
function updateSliderPWM3(element) {
  var sliderValue3 = document.getElementById("pwmSlider3").value;
  document.getElementById("textSliderValue3").innerHTML = sliderValue3;
  console.log(sliderValue3);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider3?value="+sliderValue3, true);
  xhr.send();
}
function updateSliderPWM4(element) {
  var sliderValue4 = document.getElementById("pwmSlider4").value;
  document.getElementById("textSliderValue4").innerHTML = sliderValue4;
  console.log(sliderValue4);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider4?value="+sliderValue4, true);
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";

// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if (var == "SLIDERVALUE"){
    return sliderValue;
  } else if (var == "SLIDERVALUE2"){
    return sliderValue2;
  } else if (var == "SLIDERVALUE3"){
    return sliderValue3;
  } else if (var == "SLIDERVALUE4"){
    return sliderValue4;
  };
  
  return String();
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // setup LEDs
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  fill_solid( leds, NUM_LEDS, CRGB(sliderValue2.toInt(), 255, 255)); // r g b
  FastLED.setBrightness(sliderValue.toInt());
  FastLED.show();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Send a GET request to <ESP_IP>/slider?value=<inputMessage>
  server.on("/slider", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/slider?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      sliderValue = inputMessage;
      fill_solid( leds, NUM_LEDS, CRGB(sliderValue2.toInt(), sliderValue3.toInt(), sliderValue4.toInt()));
      FastLED.setBrightness(sliderValue.toInt());
      FastLED.show();
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });

  server.on("/slider2", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/slider?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      sliderValue2 = inputMessage;
      fill_solid( leds, NUM_LEDS, CRGB(sliderValue2.toInt(), sliderValue3.toInt(), sliderValue4.toInt()));
      FastLED.setBrightness(sliderValue.toInt());
      FastLED.show();
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });

  server.on("/slider3", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/slider?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      sliderValue3 = inputMessage;
      fill_solid( leds, NUM_LEDS, CRGB(sliderValue2.toInt(), sliderValue3.toInt(), sliderValue4.toInt()));
      FastLED.setBrightness(sliderValue.toInt());
      FastLED.show();
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });

  server.on("/slider4", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/slider?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      sliderValue4 = inputMessage;
      fill_solid( leds, NUM_LEDS, CRGB(sliderValue2.toInt(), sliderValue3.toInt(), sliderValue4.toInt()));
      FastLED.setBrightness(sliderValue.toInt());
      FastLED.show();
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });
  
  // Start server
  server.begin();
}
  
void loop() {
  
}
