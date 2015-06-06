#include "AH_EasyDriver.h"

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = A0; //0;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int setting1Pin = 12;
const int setting2Pin = 11;
const int setting3Pin = 10;
const int setting4Pin =  9;

const int RES = 200;  // RESOLUTION per full revolve
const int DIR = 2;    // DIRECTION PIN
const int STEP = 3;   // STEPPING PIN
const int MS1 = 4;    //
const int MS2 = 5;    //
const int SLP = 6;    //
const int ENABLE = 7; //
const int RST = 8;    //

// AH_EasyDriver stepper(RES, DIR, STEP, MS1, MS2, SLP);
AH_EasyDriver stepper(RES, DIR, STEP, MS1, MS2, SLP, ENABLE, RST);

int buttonState = 0;         // variable for reading the pushbutton status
int setting1PinState = 0;         // variable for reading the pushbutton status
int setting2PinState = 0;         // variable for reading the pushbutton status
int setting3PinState = 0;         // variable for reading the pushbutton status
int setting4PinState = 0;         // variable for reading the pushbutton status
int setting = 0;
int calibrated = 0;
int statusDeg = 0;
int oldbuttonState = -1;
int oldsetting = -1;

void setup() {
	Serial.begin(9600);

	// initialize the LED pin as an output:
	pinMode(ledPin, OUTPUT);

	// initialize the pushbutton pin as an input:
	pinMode(buttonPin, INPUT);
	pinMode(setting1Pin, INPUT);
	pinMode(setting2Pin, INPUT);
	pinMode(setting3Pin, INPUT);
	pinMode(setting4Pin, INPUT);

	stepper.enableDriver();
	stepper.resetDriver();

	//	int rpm = stepper.getMaxSpeedRPM();
	//	stepper.setSpeedRPM(rpm);          // RPM , rotations per minute
	stepper.setSpeedRPM(100);          // RPM , rotations per minute
}

/**
 *
 *
 */
int get_button_setting(){
	int setting = 0;
	if(digitalRead(setting1Pin) == HIGH){
		setting = 1;
	}
	if(digitalRead(setting2Pin) == HIGH){
		setting = 2;
	}
	if(digitalRead(setting3Pin) == HIGH){
		setting = 3;
	}
	if(digitalRead(setting4Pin) == HIGH){
		setting = 4;
	}

	return setting;
}


/**
 *
 *
 */
int calibrate(){
	stepper.sleepOFF();

	while (1){
		if(digitalRead(buttonPin) == HIGH) break;
		stepper.rotate(5);
	}

	stepper.sleepON();
	return 1;
}

void loop() {
	int diffToGo;
	int newDeg = 0;
	int i;

	if(calibrated == 0){
		calibrated = calibrate();
	}

	/*
	FIXME: document who overrides who
	*/
	int buttonState = get_button_setting();
	if(buttonState > 0 && buttonState < 5 && buttonState != oldbuttonState){ // eg. button has been switched
		setting = buttonState;
		oldbuttonState = buttonState;
	}

	// check to see if there is any new command on the serial port waiting
	if (Serial.available()) {
		int ser = Serial.read();
		if(ser > 0 && ser < 5) setting = ser;
	}

	digitalWrite(ledPin, LOW);
	if(setting != oldsetting){
		oldsetting = setting;

		for (i=0; i<setting; i++){
			digitalWrite(ledPin, HIGH);
			delay(100);
			digitalWrite(ledPin, LOW);
			delay(100);
		}

		digitalWrite(ledPin, HIGH);

		// calculate distance that we have to rotate
		newDeg = 90 * setting;
		diffToGo = statusDeg - newDeg;
		statusDeg = newDeg;

		// do the actual rotation.
		stepper.sleepOFF();
		stepper.rotate(diffToGo);
		stepper.sleepON();
	}
}

