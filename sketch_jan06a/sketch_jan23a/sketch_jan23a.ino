#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN    6    // Digital IO pin connected to the NeoPixels.
#define WAIT  200

// Parameter 1 = number of pixels2 in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels2, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels2, not v2)
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(155, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(155, 7, NEO_GRB + NEO_KHZ800);


// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  Serial.begin(9600);     // opens serial port for reading file, sets data rate to 9600 bps
  pixels2.begin();
  pixels.begin();
  pixels2.show();
  pixels.show(); // Initialize all pixels2 to 'off'
}

// pixels2.Color takes RGB values, from 0,0,0 up to 255,255,255

//hard coded data arrays:
//supposed to flash blue green blue grren
//uint32_t unstable[] = {pixels2.Color(0, 255, 0), pixels2.Color(0, 255, 0),pixels2.Color(0, 255, 0),pixels2.Color(0, 255, 0),pixels2.Color(0, 255, 0),pixels2.Color(255, 0, 0),pixels2.Color(255, 0, 0),pixels2.Color(255, 0, 0),pixels2.Color(255, 0, 0),pixels2.Color(255, 0, 0),pixels2.Color(255, 0, 0)};
//supposed to flash off red off red
//uint32_t stable[] = {pixels2.Color(0, 0, 0), pixels2.Color(0, 0, 0),pixels2.Color(0, 0, 0),pixels2.Color(0, 0, 0),pixels2.Color(0, 0, 0),pixels2.Color(0, 0, 255),pixels2.Color(0, 0, 255),pixels2.Color(0, 0, 255),pixels2.Color(0, 0, 255),pixels2.Color(0, 0, 255)};

int incomingByte;
char testByte;
void loop() {
  //pixels2.setPixelColor(1, pixels2.Color(50,0,0));
  //pixels2.show();
  
  lightController(WAIT);

  // Using hard coded data
  //lightController(unstable, 500);
  //lightController(stable, 500);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
//    return strip.Color(WheelPos + 150, WheelPos + 50, 0);
   return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

uint32_t Wheel2(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
//    return strip.Color(WheelPos + 150, WheelPos + 50, 0);
   return pixels2.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return pixels2.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return pixels2.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

void lightController(uint8_t wait) {

          // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels2 minus one.
  //if (Serial.available() > 0) {
    int counter = 0;
    
    
    while(counter < 155){
//    while(counter < pixels2.numPixels()){
//    for(int i=1;i<pixels2.numPixels();i++){
      if (Serial.available() > 0) {
        
        // read the incoming byte:
        incomingByte = Serial.read();
        incomingByte = incomingByte-'0';
        //Serial.println(incomingByte);          //testing

        //delay(5);
        
          if (incomingByte == 0){
            //Serial.println(i);
            
            pixels.setPixelColor(counter, pixels.Color(0,0,0));
          }
          else if (incomingByte == 1){
            //Serial.println(i);
//            byte t1 = 150;
//            byte t2 = 103;
            pixels.setPixelColor(counter, Wheel2(0)); //pink
//            pixels.setPixelColor(counter, pixels.Color(255,0,0)); //pink
          }
          else if (incomingByte == 2){
            //Serial.println(i);
            pixels.setPixelColor(counter, Wheel2(0)); //orange
          }
          else if (incomingByte == 3){
            //Serial.println(i);
            pixels.setPixelColor(counter, Wheel2(20)); //yellow
          }
          else if (incomingByte == 4){
            //Serial.println(i);
            pixels.setPixelColor(counter, Wheel2(20)); //green
          }
          else if (incomingByte == 5){
            //Serial.println(i);
            pixels.setPixelColor(counter, Wheel2(40)); //blue
          }
          else if (incomingByte == 6){
            //Serial.println(i);
            pixels.setPixelColor(counter, Wheel2(40)); //blue
          }
          else if (incomingByte == 7){
            //Serial.println(i);
            pixels.setPixelColor(counter, Wheel2(60)); //blue
          }
          else if (incomingByte == 8){
            //Serial.println(i);
            pixels.setPixelColor(counter, Wheel2(60)); //blue
          }
          else if (incomingByte == 9){
            //Serial.println(i);
            pixels.setPixelColor(counter, Wheel2(84)); //blue
          }  else{
            pixels.setPixelColor(counter, Wheel2(84));
          
          }
          
          counter++;
          //if (counter == 155){
          //  break;
          //}
      }
}

//next file
counter = 0;
    while(counter < 155){
//    while(counter < pixels2.numPixels()){
//    for(int i=1;i<pixels2.numPixels();i++){
      if (Serial.available() > 0) {
        
        // read the incoming byte:
        incomingByte = Serial.read();
        incomingByte = incomingByte-'0';
        //Serial.println(incomingByte);          //testing

        //delay(5);
          if (incomingByte == 0){
            //Serial.println(i);
            
            pixels2.setPixelColor(counter, pixels2.Color(0,0,0));
          }
          else if (incomingByte == 1){
            //Serial.println(i);
//            byte t1 = 150;
//            byte t2 = 103;
            pixels2.setPixelColor(counter, Wheel2(0)); //pink
//            pixels2.setPixelColor(counter, pixels2.Color(255,0,0)); //pink
          }
          else if (incomingByte == 2){
            //Serial.println(i);
            pixels2.setPixelColor(counter, Wheel2(0)); //orange
          }
          else if (incomingByte == 3){
            //Serial.println(i);
            pixels2.setPixelColor(counter, Wheel2(20)); //yellow
          }
          else if (incomingByte == 4){
            //Serial.println(i);
            pixels2.setPixelColor(counter, Wheel2(20)); //green
          }
          else if (incomingByte == 5){
            //Serial.println(i);
            pixels2.setPixelColor(counter, Wheel2(40)); //blue
          }
          else if (incomingByte == 6){
            //Serial.println(i);
            pixels2.setPixelColor(counter, Wheel2(40)); //blue
          }
          else if (incomingByte == 7){
            //Serial.println(i);
            pixels2.setPixelColor(counter, Wheel2(60)); //blue
          }
          else if (incomingByte == 8){
            //Serial.println(i);
            pixels2.setPixelColor(counter, Wheel2(60)); //blue
          }
          else if (incomingByte == 9){
            //Serial.println(i);
            pixels2.setPixelColor(counter, Wheel2(84)); //blue
          }  else{
            pixels2.setPixelColor(counter, Wheel2(84));
          
          }
          
          counter++;
          //if (counter == 155){
          //  break;
          //}
      }
}

      pixels.show(); // This sends the updated pixel color to the hardware.
      pixels2.show(); // This sends the updated pixel color to the hardware.
    delay(wait); // Delay for a period of time (in milliseconds).

    /**
    //insert here
      while(1){
      //for(int i=1;i<pixels.numPixels();i++){
      if (Serial.available() > 0) {
        
        // read the incoming byte:
        incomingByte = Serial.read();
        
        incomingByte = incomingByte-'0';
        Serial.println(incomingByte);          //testing
        
        delay(5);
        
        if (incomingByte == 0){
          //Serial.println(i);
          pixels.setPixelColor(counter, pixels.Color(0,0,0));
        }
        else if (incomingByte == 1){
          //Serial.println(i);
          pixels.setPixelColor(counter, pixels.Color(255,20,147)); //pink
        }
        else if (incomingByte == 2){
          //Serial.println(i);
          pixels.setPixelColor(counter, pixels.Color(255, 69, 0)); //orange
        }
        else if (incomingByte == 3){
          //Serial.println(i);
          pixels.setPixelColor(counter, pixels.Color(255, 215, 0)); //yellow
        }
        else if (incomingByte == 4){
          //Serial.println(i);
          pixels.setPixelColor(counter, pixels.Color(124,252,50)); //green
        }
        else if (incomingByte == 5){
          //Serial.println(i);
          pixels.setPixelColor(counter, pixels.Color(0,255,255)); //blue
        }  else{
          pixels.setPixelColor(counter, pixels.Color(0,0,0));
        
        }
        
      }
      
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(wait); // Delay for a period of time (in milliseconds).
    counter++;
    //if (counter == 155){
    //        break;
    //}
  **/
  }
  

  
  

