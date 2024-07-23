// filehandler.h

#ifndef _FILEHANDLER_h
#define _FILEHANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

namespace filehandler {
  bool setup();
}

#endif