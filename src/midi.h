// midi.h

#ifndef _MIDI_h
#define _MIDI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

namespace MIDI {
	void setup(HardwareSerial& port);
	boolean noteOn(uint8_t channel, uint8_t note, uint8_t velocity = 80);
	void noteOnUnsafe(uint8_t channel, uint8_t note, uint8_t velocity = 80);
	boolean noteOff(uint8_t channel, uint8_t note, uint8_t velocity = 0);
	void noteOffUnsafe(uint8_t channel, uint8_t note, uint8_t velocity = 0);
	void allOff(uint8_t channel, uint8_t velocity = 0);
}

#endif

