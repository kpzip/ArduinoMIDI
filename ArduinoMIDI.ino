/*
 Name:		ArduinoMIDI.ino
 Created:	3/26/2024 2:11:23 PM
 Author:	kpzip
*/

#include "src/lib.h"

#define SERIAL_1 &Serial1
#define SERIAL_2 &Serial2
#define SERIAL_3 &Serial3

// the setup function runs once when you press reset or power the board
void setup() {
	MIDI::setup(SERIAL_1);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
