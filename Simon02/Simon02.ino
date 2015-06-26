/*
 * SIMON SAYS! (recognising button presses)
 * A TWSU Gamer game by YOU!
 * This lesson is about button presses!
*/

#include <Gamer.h>  // Include the Gamer library

/*
Create an "object" - a copy of the DIY Gamer library,
which contains commands for controlling the display,
buttons, and everything else on your console.
*/
Gamer gamer;

/* This array should be replaced by a previously
   created one (which contains the arrows). */

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

void setup() { 
  gamer.begin(); // Fire up the Gamer!
}

void loop() {
  int key = waitForButtonPress();
  gamer.clear();
  delay(100);
  gamer.printImage(framesSimon[key]);
  /* This gets the arrow that was just pressed from
     the array. */
}

/* We are going to wait for a button press in this
   function, then we are going to return it once a
   button has been pressed. */
   
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
