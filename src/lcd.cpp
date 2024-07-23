//
//
//

#include "lcd.h"
#include <LiquidCrystal.h>

using namespace lcd;

// LCD Pin Definitions

const int lcdRSPin = 7;
const int lcdEPin = 6;
const int lcdD4Pin = 5;
const int lcdD5Pin = 4;
const int lcdD6Pin = 3;
const int lcdD7Pin = 2;

static LiquidCrystal display = LiquidCrystal(lcdRSPin, lcdEPin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

void lcd::setup() {
  display.begin(16, 2);
  display.print("Testing...");
}