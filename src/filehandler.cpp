//
//
//

#include "filehandler.h"

#include <SPI.h>
#include <SD.h>

// SPI Pins:
// MISO: 12
// MOSI: 11
// SCK: 13
// CS: 10

#define SDCARD_CS_PIN 10

static File current_file;

#define PROGRAM_ROOT_NAME "program.toml"

using namespace filehandler;

bool filehandler::setup() {
  if (!SD.begin(SDCARD_CS_PIN)) {
    return false;
  }

  current_file = SD.open(PROGRAM_ROOT_NAME, O_READ);

  //check if 
  if (current_file) {
    //Read the file and determine the program
  }
}