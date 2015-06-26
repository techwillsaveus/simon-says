/*
 * SIMON SAYS! (images)
 * A TWSU Gamer game by YOU!
 * This lesson is about arrays and images!
*/

#include <Gamer.h>  // Include the Gamer library

/*
Create an "object" - a copy of the DIY Gamer library,
which contains commands for controlling the display,
buttons, and everything else on your console.
*/
Gamer gamer;

/* You should create your own arrays with your own
   images! */

// These are our arrow images
byte framesSimon[4][8] = {
  { // up
    B00000000,
    B00011000,
    B00111100,
    B01111110,
    B00011000,
    B00011000,
    B00011000,
    B00000000
  },
  { // down
    B00000000,
    B00011000,
    B00011000,
    B00011000,
    B01111110,
    B00111100,
    B00011000,
    B00000000
  },
  { // left
    B00000000,
    B00010000,
    B00110000,
    B01111110,
    B01111110,
    B00110000,
    B00010000,
    B00000000
  },
  { // right
    B00000000,
    B00001000,
    B00001100,
    B01111110,
    B01111110,
    B00001100,
    B00001000,
    B00000000
  }
};

// This is our "GO!" image
byte go[8] = {
  B00000000,
  B01101110,
  B10001010,
  B10001010,
  B10001010,
  B10101010,
  B01101110,
  B00100000
};

// This is our tick image
byte right[8] = {
  B00000001,
  B00000011,
  B00000111,
  B00001110,
  B11011100,
  B11111000,
  B01110000,
  B00100000
};

// This is our cross image
byte wrong[8] = {
  B11000011,
  B01100110,
  B00111100,
  B00011000,
  B00011000,
  B00111100,
  B01100110,
  B11000011
};

void setup() {
  gamer.begin(); // Fire up the Gamer!
}

void loop() {
  for(int i=0;i<4;i++) {
    gamer.clear(); //clear
    delay(100); //wait
    gamer.printImage(framesSimon[i]); //print
    delay(300); //wait
  } //and so on!
  gamer.clear();
  delay(100);
  gamer.printImage(go);
  delay(300);
  gamer.clear();
  delay(100);
  gamer.printImage(right);
  delay(300);
  gamer.clear();
  delay(100);
  gamer.printImage(wrong);
  delay(300);
}
