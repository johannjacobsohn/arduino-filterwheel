#include "AH_EasyDriver.h"

//AH_EasyDriver(int RES, int DIR, int STEP);
// RES -> RESOLUTION per full revolve
// DIR -> DIRECTION PIN
// STEP -> STEPPING PIN
AH_EasyDriver stepper(200,2,3);   // Initialisation


// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
const int setting1Pin = 12;
const int setting2Pin = 11;
const int setting3Pin = 10;
const int setting4Pin =  9;

int buttonState = 0;         // variable for reading the pushbutton status
int setting1PinState = 0;         // variable for reading the pushbutton status
int setting2PinState = 0;         // variable for reading the pushbutton status
int setting3PinState = 0;         // variable for reading the pushbutton status
int setting4PinState = 0;         // variable for reading the pushbutton status
int setting = 0;
int calibrated = 0;
int statusDeg = 0; 

void setup() {
  //  Serial.begin(57600);
  stepper.setSpeedRPM(100);          // RPM , rotations per minute
  //stepper.setSpeedHz(100);           // Hz, steps per second

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);  
  pinMode(setting1Pin, INPUT);  
  pinMode(setting2Pin, INPUT);  
  pinMode(setting3Pin, INPUT);
  pinMode(setting4Pin, INPUT);
}

void loop() {
  int diffToGo;
  int newDeg = 0;

  buttonState = digitalRead(buttonPin);

  setting1PinState = digitalRead(setting1Pin);
  setting2PinState = digitalRead(setting2Pin);
  setting3PinState = digitalRead(setting3Pin);
  setting4PinState = digitalRead(setting4Pin);

  if(setting1PinState == HIGH){ 
    setting = 1; 
  }
  if(setting2PinState == HIGH){ 
    setting = 2; 
  }
  if(setting3PinState == HIGH){ 
    setting = 3; 
  }
  if(setting4PinState == HIGH){ 
    setting = 4; 
  }

  // setup

//  if(!calibrated){
//    stepper.rotate(5);

//    if (buttonState == HIGH) {    
//      digitalWrite(ledPin, HIGH);  
//      calibrated = 1;
//    }
//  } else {
//    newDeg = 90 * setting;
//   diffToGo = statusDeg - newDeg;
//    statusDeg = newDeg;

//    stepper.rotate(diffToGo);  

    if (setting == 4) {    
      // turn LED on:    
      digitalWrite(ledPin, HIGH);  
    } else {
      // turn LED off:
      digitalWrite(ledPin, LOW); 
    }

//  }


  //  stepper.rotate(360.0);            // rotate 180° 
  //  digitalWrite(ledPin, HIGH);  
  //  stepper.rotate(-360.0);            // rotate 180° 
  //  digitalWrite(ledPin, LOW); 

}



/*

 
 
 // variables will change:
 int buttonState = 0;         // variable for reading the pushbutton status
 
 void setup() {
 // initialize the LED pin as an output:
 pinMode(ledPin, OUTPUT);      
 // initialize the pushbutton pin as an input:
 pinMode(buttonPin, INPUT);     
 }
 
 void loop(){
 // read the state of the pushbutton value:
 buttonState = digitalRead(buttonPin);
 
 // check if the pushbutton is pressed.
 // if it is, the buttonState is HIGH:
 if (buttonState == HIGH) {    
 // turn LED on:    
 digitalWrite(ledPin, HIGH);  
 } else {
 // turn LED off:
 digitalWrite(ledPin, LOW); 
 }
 }
 
 */

