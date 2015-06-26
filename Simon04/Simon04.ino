/*
 * SIMON SAYS! (structure)
 * A TWSU Gamer game by YOU!
*/

#include <Gamer.h>  // Include the Gamer library

/*
Create an "object" - a copy of the DIY Gamer library,
which contains commands for controlling the display,
buttons, and everything else on your console.
*/
Gamer gamer;

/* These are the other variables from the previous
   lessons. */
   
byte sequence[50];
int sequenceLength = 0;
int delayTime = 300;

// Include your arrays here!

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
  gamer.begin();  // Fire up the Gamer!
  setupScore();  // This is for the "Advanced" tab
  resetSimon();  // Reset the game so that it's ready
}

void loop() {
  // Let's add a countdown!
  for(int i=3;i>0;i--) {
    showScore(i);
    delay(delayTime);
  }
  gamer.printImage(go); //GO!
  delay(delayTime);
  addToSequence();
  gamer.clear();
  delay(delayTime);
  boolean success = true;
  // We'll say they're right until proven otherwise.
  for(int i=0;i<sequenceLength;i++) {
    int key = waitForButtonPress();
    // NOW, the comparison...
    // HAVE THEY GOT IT RIGHT???
    gamer.clear(); // Quickly clear
    delay(100); // So the next arrow is separate
    gamer.printImage(framesSimon[key]);
    if(key != sequence[i]) {
      success = false; //they got it wrong
      break; //skip the rest of the sequence
    }
  }
  delay(delayTime);
  // Let's make it faster!
  // We'll reduce the delay by 1/40th
  delayTime-=(delayTime/40);
  if(success) { // Did they get the whole way through?
    gamer.printImage(right); // Print a tick!
    sequenceLength++; // Make it HARDER!
  } else { // They got it wrong...
    gamer.printImage(wrong);
    delay(500);
    showScore(sequenceLength); // Show their score
    delay(500);
    resetSimon(); // And reset
  }
  delay(500);
}

void resetSimon() {
  
  /*
  Now, when the game is over, we'll run this to reset
  the game so it can be played again!
  */
  
  gamer.clear();      // Clear the gamer screen
  delay(100);
  for(byte b=0;b<sequenceLength;b++) sequence[b]=0;
  sequenceLength=0;   // Clear the sequence and set its length to 0
  delayTime = 300;    // Set it back to normal speed.
  sequence[0] = random(0,4);
  sequenceLength++;
}

/* Include addToSequence() and waitForButtonPress()
   here! */
   
void addToSequence() {
  sequence[sequenceLength] = random(0,4);
  // Add a new random direction to the sequence!
  for(int i=0;i<sequenceLength;i++) {
    // For each direction...
    gamer.clear(); // ...clear the screen...
    delay(delayTime);
    gamer.printImage(framesSimon[sequence[i]]);
    // ... and show the new direction.
    delay(delayTime);
  }
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
