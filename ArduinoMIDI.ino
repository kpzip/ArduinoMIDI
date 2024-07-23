/*
 Name:		ArduinoMIDI.ino
 Created:	3/26/2024 2:11:23 PM
 Author:	kpzip
*/

#include "src/lib.h"


#define SERIAL Serial
#define SERIAL_1 Serial1
#define SERIAL_2 Serial2
#define SERIAL_3 Serial3

#define DEBUG_PIN 8

static int previous_state = HIGH;

// the setup function runs once when you press reset or power the board
void setup() {
	MIDI::setup(SERIAL);
  //lcd::setup();

  // Debug
  pinMode(DEBUG_PIN, INPUT_PULLUP);
  //pinMode(9, OUTPUT);
  //pinMode(10, OUTPUT);

}

// the loop function runs over and over again until power down or reset
void loop() {
  /*
  MIDI::noteOn(0, 60);
  delay(2000);
  MIDI::noteOff(0, 60);
  delay(2000);*/

  
  int current_state = digitalRead(DEBUG_PIN);
  //digitalWrite(9, current_state);
  //digitalWrite(10, previous_state);

  if (current_state != previous_state) {
    if (current_state == LOW) {
      MIDI::noteOn(0, 60);
    }
    else {
      MIDI::noteOff(0, 60);
    }
    previous_state = current_state;
  }
	delay(2000);
}
