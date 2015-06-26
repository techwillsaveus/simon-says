/*
 * SIMON SAYS! (playing sequences)
 * A TWSU Gamer game by YOU!
 * This lesson is about making and playing sequences!
*/

#include <Gamer.h> // Include the Gamer library

/*
Create an "object" - a copy of the DIY Gamer library,
which contains commands for controlling the display,
buttons, and everything else on your console.
*/
Gamer gamer;

/*
This is where the sequence will
be stored. We have to give it a
length to start off with, so we'll
call it 50 as barely anyone will
be able to score 50!
*/
byte sequence[50];
int sequenceLength = 0;  // How long is the sequence so far?
int delayTime = 300;  // How fast does the game go?

/* These arrays should be replaced by the previously
   created ones (which contains the arrows). */

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
  addToSequence();
  gamer.clear();
  delay(delayTime);
  boolean success = true;
  int key = waitForButtonPress();
  gamer.clear();
  delay(100);
  gamer.printImage(framesSimon[key]);
  if (key != sequence[0]) {
    success = false;
  }
  delay(delayTime);
  
  if(success) {
    gamer.printImage(right);
  }
  else {
    gamer.printImage(wrong);
    delay(1000);
  }
  delay(500);
}

int waitForButtonPress() {
  int key = 4;
  //let's wait until another key has been pressed
  while(key==4) {
    if(gamer.isPressed(UP)) key=0;
    if(gamer.isPressed(DOWN)) key=1;
    if(gamer.isPressed(LEFT)) key=2;
    if(gamer.isPressed(RIGHT)) key=3;
  }
  return key;
}

void addToSequence() {
  sequence[0] = random(0,4);
  gamer.clear(); // ...clear the screen...
  delay(delayTime);
  gamer.printImage(framesSimon[sequence[0]]);
  delay(delayTime);
}

