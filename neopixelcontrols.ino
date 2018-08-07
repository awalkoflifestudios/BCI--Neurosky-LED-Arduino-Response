#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN    8

#define PIXEL_COUNT 18

int incomingByte = 0;

int waitTime = 10;



Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ400);

void setup() {

  Serial.begin(9600);

  strip.begin();

  strip.show();

  pinMode(PIXEL_PIN, OUTPUT);

}



void loop() {

  if (Serial.available() > 0 ) {

    incomingByte = Serial.parseInt();



    Serial.print ("arduino ");

    Serial.println (incomingByte);

    startShow();

  }

}

// put your main code here, to run repeatedly:



void startShow() {

  switch (incomingByte) {

    case 1: fadeInAndOut(0,132,128, waitTime);  // teal

      break;

    case 0: fadeInAndOut(253,0,245, waitTime);   // magenta

      break;

  }

}



void fadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {



  for(uint8_t b=0; b <255; b++) {

     for(uint8_t i=0; i < strip.numPixels(); i++) {

        strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);

     }

     strip.show();

     delay(wait);

  }



  for(uint8_t b=255; b > 0; b--) {

     for(uint8_t i=0; i < strip.numPixels(); i++) {

        strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);

     }

     strip.show();

     delay(wait);

  }

}
