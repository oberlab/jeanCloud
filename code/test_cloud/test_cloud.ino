// Include the libraries:
#include <TM1637Display.h>
#include <FastLED.h>

// Define the connections pins for display:
#define CLK 18
#define DIO 5

// Define the pin for the buzzer and configurate it:
#define BUZ 32
int freq = 2000;
int channel = 0;
int resolution = 8;

// fastLED configuration:wq
#define NUM_LEDS 27        // set number of LEDs hewqre
#define LED_PIN 14        
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; // Define the array of leds

// fading configuration for the light
int dim = 0;
int dimincr = 1;
bool up = true;

// Create andisplay object:
TM1637Display display = TM1637Display(CLK, DIO);



void setup() {  
  // setup display
  display.setBrightness(7); // Set the display brightness (0-7)
  display.clear(); // Clear the display
  // setup LEDs
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  // setup buzzer
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(BUZ, channel);
}

void pulseLight(int r, int g, int b, int dimincrement) {
  fill_solid( leds, NUM_LEDS, CRGB(r, g, b));
  if (dim < 255 & up) {dim = dim + dimincr;}
  if (dim < 255 & !up) {dim = dim - dimincr;}
  if (dim == 255) { up = false; dim = dim - dimincr; }
  if (dim == 0) { up = true; }

  FastLED.setBrightness(dim);
  FastLED.show();
}

void loop() {
  pulseLight(255, 255, 255, dimincr); //Start LED pulsing
  display.showNumberDec(dim); //Display the dimincr value;
  if (dim == 0){
    ledcWrite(channel, 150);
    ledcWriteTone(channel, 4000);
    delay(200);
    ledcWriteTone(channel, 0);
    delay(200);
    ledcWriteTone(channel, 4000);
    delay(200);
    ledcWriteTone(channel, 0);
  }
  delay(10);
  
}
