// lib.h

#ifndef _LIB_h
#define _LIB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//Include sub-libraries
#include "MIDI/midi.h"
#include "Program/program.h"



#endif



