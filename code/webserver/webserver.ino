#include <WiFi.h>
#include <FastLED.h>

// Der webserver wird auf Port 80 gesetzt
WiFiServer server(80);

const char* ssid = "ALK_mobil";     // Dein WLAN Netzwerk Name
const char* password = "urlaubingseng20";   // Dein WLAN Passwort

// fastLED configuration:
#define NUM_LEDS 27        // set number of LEDs here
#define LED_PIN 14        
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; // Define the array of leds

// slider
String sliderValue = "0";

// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if (var == "SLIDERVALUE"){
    return sliderValue;
  }
  return String();
}

void printHeader(WiFiClient _client, int statusCode, char* statusMessage) {
    _client.print("HTTP/1.1 ");
    _client.print(statusCode);
    _client.print(" ");
    _client.print(statusMessage);
    _client.println("Content-type:text/html");
    _client.println("Connection: close");
    _client.println();
}

void handleWebserverRequest(WiFiClient _client) {
    String currentLine = "";                   // make a String to hold incoming data from the client
    String header = "";
    while (_client.connected()) {            // Eine Schleife während der client verbunden ist
      if (_client.available()) {             // Wenn bytes von dem Client bereit sind gelesen zu werden,
        char c = _client.read();             // lese diese bytes
        Serial.write(c);                     // Gebe die gelesenen bytes über die Serielle Schnittstelle aus
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            printHeader(_client, 200, "OK");

            if (header.indexOf("GET /lamp/on") >= 0) {
              // ToDo: Add Lamp
              Serial.println("lamp on");
            } else if (header.indexOf("GET /lamp/off") >= 0) {
              Serial.println("lamp off");
            } else if (header.indexOf("GET /timer/on") >= 0) {
              Serial.println("alarm on");
            } else if (header.indexOf("GET /timer/off") >= 0) {
              Serial.println("alarm off");
            }

            // Display the HTML web page
            _client.println("<!DOCTYPE html><html>");
            _client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            _client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            _client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            _client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            _client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            _client.println(".button2 {background-color: #555555;}</style></head>");
            _client.println(".slider { -webkit-appearance: none; margin: 14px; width: 360px; height: 25px; background: #FFD65C; outline: none; -webkit-transition: .2s; transition: opacity .2s;}");
            _client.println(".slider::-webkit-slider-thumb {-webkit-appearance: none; appearance: none; width: 35px; height: 35px; background: #003249; cursor: pointer;}");
             _client.println(".slider::-moz-range-thumb { width: 35px; height: 35px; background: #003249; cursor: pointer; }");

            // Web Page Heading
            _client.println("<body>");
            _client.println("<h1>JeanCloud</h1>");
            _client.println("<h3>Lampe</h3>");
            _client.println("<p><a href=\"/lamp/on\"><button class=\"button\">AN</button></a>");
            _client.println("<a href=\"/lamp/off\"><button class=\"button button2\">AUS</button></a></p>");
            _client.println("<h3>Wecker</h3>");
            _client.println("<p><a href=\"/timer/on\"><button class=\"button\">AN</button></a>");
            _client.println("<a href=\"/timer/off\"><button class=\"button button2\">AUS</button></a></p>");
            _client.println("<p><span id="textSliderValue">%SLIDERVALUE%</span></p>");
            _client.println("<p><input type="range" onchange="updateSliderPWM(this)" id="pwmSlider" min="0" max="255" value="%SLIDERVALUE%" step="1" class="slider"></p>");
            _client.println("<script>");
            _client.println("function updateSliderPWM(element) {");
            _client.println("var sliderValue = document.getElementById("pwmSlider").value;");
            _client.println("document.getElementById("textSliderValue").innerHTML = sliderValue;");
            _client.println("console.log(sliderValue);");
            _client.println("var xhr = new XMLHttpRequest();");
            _client.println("xhr.open("GET", "/slider?value="+sliderValue, true);");
            _client.println("xhr.send();");
            _client.println("}");

            _client.println("</script></body></html>");

            // The HTTP response ends with another blank line
            _client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // header variable leeren
    header = "";
    // Verbindung schließen
    _client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
}

// Arduino setup
void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Locale IP Adresse ausgeben und Web server starten
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

// Arduino loop
void loop(){
  WiFiClient client = server.available();

  if (client) {
     handleWebserverRequest(client);
  }
}
