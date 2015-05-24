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

	if (Serial.available()) {
		int ser = Serial.read();
		if(ser > 0 && ser < 5) setting = ser;
	}

  // setup

  if(!calibrated){
	stepper.rotate(5);

	if (buttonState == HIGH) {
		digitalWrite(ledPin, HIGH);
		calibrated = 1;
	} else {
		newDeg = 90 * setting;
		diffToGo = statusDeg - newDeg;
		statusDeg = newDeg;

		stepper.rotate(diffToGo);
	}

}


/*
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

int number,n;
void main(void){
open_port();
}

  int open_port(void)
{
  int fd; /* File descriptor for the port */


  fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {

perror("open_port: Unable to open /dev/ttyACM0 - ");
  }
  else{
     printf("Port Opened successfully\n");
     number = 1;
     while(number!=55){
     scanf("%d",&number);
      n = write(fd, "ATZ\r", number);
     if (n < 0)
     fputs("write() of 4 bytes failed!\n", stderr);
     }


}


//
// serial.c / serial.cpp
// A simple serial port writing example
// Written by Ted Burke - last updated 13-2-2013
//
// To compile with MinGW:
//
//      gcc -o serial.exe serial.c
//
// To compile with cl, the Microsoft compiler:
//
//      cl serial.cpp
//
// To run:
//
//      serial.exe
//

#include <windows.h>
#include <stdio.h>

int main()
{
    // Define the five bytes to send ("hello")
    char bytes_to_send[5];
    bytes_to_send[0] = 104;
    bytes_to_send[1] = 101;
    bytes_to_send[2] = 108;
    bytes_to_send[3] = 108;
    bytes_to_send[4] = 111;

    // Declare variables and structures
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};

    // Open the highest available serial port number
    fprintf(stderr, "Opening serial port...");
    hSerial = CreateFile(
                "\\\\.\\COM22", GENERIC_READ|GENERIC_WRITE, 0, NULL,
                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
    if (hSerial == INVALID_HANDLE_VALUE)
    {
            fprintf(stderr, "Error\n");
            return 1;
    }
    else fprintf(stderr, "OK\n");

    // Set device parameters (38400 baud, 1 start bit,
    // 1 stop bit, no parity)
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (GetCommState(hSerial, &dcbSerialParams) == 0)
    {
        fprintf(stderr, "Error getting device state\n");
        CloseHandle(hSerial);
        return 1;
    }

    dcbSerialParams.BaudRate = CBR_38400;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if(SetCommState(hSerial, &dcbSerialParams) == 0)
    {
        fprintf(stderr, "Error setting device parameters\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Set COM port timeout settings
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if(SetCommTimeouts(hSerial, &timeouts) == 0)
    {
        fprintf(stderr, "Error setting timeouts\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Send specified text (remaining command line arguments)
    DWORD bytes_written, total_bytes_written = 0;
    fprintf(stderr, "Sending bytes...");
    if(!WriteFile(hSerial, bytes_to_send, 5, &bytes_written, NULL))
    {
        fprintf(stderr, "Error\n");
        CloseHandle(hSerial);
        return 1;
    }
    fprintf(stderr, "%d bytes written\n", bytes_written);

    // Close serial port
    fprintf(stderr, "Closing serial port...");
    if (CloseHandle(hSerial) == 0)
    {
        fprintf(stderr, "Error\n");
        return 1;
    }
    fprintf(stderr, "OK\n");

    // exit normally
    return 0;
}

*/
