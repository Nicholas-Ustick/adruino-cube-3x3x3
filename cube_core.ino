/**
  Copyright (c) 2016 by Nicholas R. Ustick <nick@stoicprogrammer.com>

  This file is part of arduino-cube-3x3x3.

  arduino-cube-3x3x3 is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  arduino-cube-3x3x3 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with arduino-cube-3x3x3 .  If not, see <http://www.gnu.org/licenses/>.
*/


/**
   A flag that can be inspected to determine if se should print tracing to Serial.
*/
boolean _debugFlag = false;

boolean isDebug() {
  return _debugFlag;
}
/**
   Toggle debugging.
*/
void debug() {
  _debugFlag = !_debugFlag;
}

void debug(boolean debugFlag) {
  _debugFlag = debugFlag;
}


void trace(String message) {
  if (_debugFlag) {
    Serial.println(message);
  }
}


/**
   Constrain the given value to within the bounds of
   0..maxValue after incrementing. If the value
   exceeds maxValue then the value is reset to 0.
*/
int incrementValue(int value, const int maxValue ) {
  value++;
  if ( value >= maxValue ) {
    value = 0;
  }
  return value;
}

void initializeIO() {
  // Layers
  for (int l = 0; l < CUBE_SIZE; l++) {
    pinMode(LAYER[l], OUTPUT);
  }

  // Pixels
  for (int p = 0; p < PIXEL_COUNT; p++) {
    pinMode(GRID[p], OUTPUT);
  }
}

