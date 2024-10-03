// 
// 
// 

#include "midi.h"

using namespace MIDI;

static const unsigned long MIDI_BAUD = 31250;

static const uint8_t CHANNEL_BITMASK = 0b00001111;

static const uint8_t NOTE_ON = 0x90;
static const uint8_t NOTE_OFF = 0x80;

static HardwareSerial* midi_port;

void MIDI::setup(HardwareSerial& port) {
  midi_port = &port;
	port.begin(MIDI_BAUD, SERIAL_8N1);
}

inline uint8_t withChannel(uint8_t channel, uint8_t status) {
	return (channel & CHANNEL_BITMASK) | (status & ~CHANNEL_BITMASK);
}

void send(uint8_t* bytes, size_t len) {
	for (size_t i = 0; i < len; i++) {
		midi_port->write(bytes[i]);
	}
}

boolean MIDI::noteOn(uint8_t channel, uint8_t note, uint8_t velocity = 80) {
	boolean isValid = note < 128 && velocity < 128;
	if (isValid) {
		noteOnUnsafe(channel, note, velocity);
	}
	return isValid;
}

void MIDI::noteOnUnsafe(uint8_t channel, uint8_t note, uint8_t velocity = 80) {
	uint8_t data[] = { withChannel(channel, NOTE_ON), note, velocity };
	send(data, 3);
}

boolean MIDI::noteOff(uint8_t channel, uint8_t note, uint8_t velocity = 0) {
	boolean isValid = note < 128 && velocity < 128;
	if (isValid) {
		noteOffUnsafe(channel, note, velocity);
	}
	return isValid;
}

void MIDI::noteOffUnsafe(uint8_t channel, uint8_t note, uint8_t velocity = 0) {
	uint8_t data[] = { withChannel(channel, NOTE_OFF), note, velocity };
	send(data, 3);
}

void MIDI::allOff(uint8_t channel, uint8_t velocity = 0) {
	for (uint8_t note = 0; note < 127; note++) {
		noteOffUnsafe(channel, note, velocity);
	}
}