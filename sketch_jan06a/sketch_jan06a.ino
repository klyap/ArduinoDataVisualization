#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN    6    // Digital IO pin connected to the NeoPixels.
#define WAIT  1000

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(155, PIXEL_PIN, NEO_GRB + NEO_KHZ800);


// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  Serial.begin(9600);     // opens serial port for reading file, sets data rate to 9600 bps
  pixels.begin();
  pixels.show(); // Initialize all pixels to 'off'
}

// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255

//hard coded data arrays:
//supposed to flash blue green blue grren
//uint32_t unstable[] = {pixels.Color(0, 255, 0), pixels.Color(0, 255, 0),pixels.Color(0, 255, 0),pixels.Color(0, 255, 0),pixels.Color(0, 255, 0),pixels.Color(255, 0, 0),pixels.Color(255, 0, 0),pixels.Color(255, 0, 0),pixels.Color(255, 0, 0),pixels.Color(255, 0, 0),pixels.Color(255, 0, 0)};
//supposed to flash off red off red
//uint32_t stable[] = {pixels.Color(0, 0, 0), pixels.Color(0, 0, 0),pixels.Color(0, 0, 0),pixels.Color(0, 0, 0),pixels.Color(0, 0, 0),pixels.Color(0, 0, 255),pixels.Color(0, 0, 255),pixels.Color(0, 0, 255),pixels.Color(0, 0, 255),pixels.Color(0, 0, 255)};

int incomingByte;
char testByte;
int counter = 0;
void loop() {
  lightController(WAIT);

  // Using hard coded data
  //lightController(unstable, 500);
  //lightController(stable, 500);
}

//void lightController(uint32_t color[], uint8_t wait) {     //using hard coded data
void lightController(uint8_t wait) {

  //for (int j=0;j<TIME;j++){

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  if (Serial.available() > 0) {
    
    
    for(int i=1;i<pixels.numPixels();i++){
      if (Serial.available() > 0) {
         counter++;
         //Serial.println(counter);
        // read the incoming byte:
        incomingByte = Serial.read();
        //incomingByte = 0;  //for debugging
        //testByte = Serial.read();
        //Serial.println(incomingByte);          //testing
        //Serial.println(testByte);
        
        incomingByte = incomingByte-'0';
       //Serial.println(incomingByte);          //testing
        /**
        char buf[4];
        Serial.println("received:");
        Serial.println(itoa(incomingByte, buf, 10));
        **/
delay(1);
        
        if (incomingByte == 0){
          //Serial.println(i);
          pixels.setPixelColor(i-1, pixels.Color(0,0,0));
        }
        else if (incomingByte == 1){
          //Serial.println(i);
          pixels.setPixelColor(i-1, pixels.Color(255,20,147)); //pink
        }
        else if (incomingByte == 2){
          //Serial.println(i);
          pixels.setPixelColor(i-1, pixels.Color(255, 69, 0)); //orange
        }
        else if (incomingByte == 3){
          //Serial.println(i);
          pixels.setPixelColor(i-1, pixels.Color(255, 215, 0)); //yellow
        }
        else if (incomingByte == 4){
          //Serial.println(i);
          pixels.setPixelColor(i-1, pixels.Color(124,252,50)); //green
        }
        else if (incomingByte == 5){
          //Serial.println(i);
          pixels.setPixelColor(i-1, pixels.Color(0,255,255)); //blue
        }  else{
          pixels.setPixelColor(i-1, pixels.Color(0,0,0));
        
        }
        

      }
      
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(wait); // Delay for a period of time (in milliseconds).
    }  

  //}
  
}

