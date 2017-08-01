/*  SevSeg Counter Example
 *  Create Date: 29/6/2017
 *  Creator: Methun

 */

#include <SevSeg.h>




const int  buttonPin = 1;      //INPUT PIN Diclear
SevSeg sevseg;                //Instantiate a seven segment controller object
int buttonPushCounter = 0; // counter for the number of button presses
int buttonState = 0;       // current state of the button
int lastButtonState = 0;    // previous state of the button

void setup() {

  Serial.begin(9600);

  pinMode(buttonPin, INPUT);  // initialize the button pin as a input:
  byte numDigits = 3 ;
  byte digitPins[] = {  4, 5, 6 };
  byte segmentPins[] = { 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(230);
}

void loop() {



  buttonState = digitalRead(buttonPin);  // read the pushbutton input pin:
    if (buttonState != lastButtonState)  // compare the buttonState to its previous state
    {
      if (buttonState == LOW) {         // if the state has changed, increment the counter

        delay(1500);
        buttonPushCounter++;             // if the current state is HIGH then the button   
        
      }
    }
    lastButtonState = buttonState;    // save the current state as the last state,
                                      //for next time through the loop
    sevseg.setNumber(buttonPushCounter,2);  //show value to 7 segment 
    
 

  sevseg.refreshDisplay(); // Must run repeatedly
  
}

/// END ///
