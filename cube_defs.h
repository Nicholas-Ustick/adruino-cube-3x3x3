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

#define LR_TOP A4
#define LR_MID A2
#define LR_BOT A1

#define PX_1 11
#define PX_2 A0
#define PX_3 A5

#define PX_4 7
#define PX_5 5
#define PX_6 4

#define PX_7 10
#define PX_8 6
#define PX_9 2

#define PIXEL_COUNT 9
#define CUBE_SIZE 3

// The list of LEDs in a plane in order to be lit. (ie. lower left corner to upper right corner.
// NOTE: Orientation of Lower-left corner is neare the barrel connector on the Arduino UNO.
const byte GRID[PIXEL_COUNT] = { PX_1, PX_2, PX_3, PX_4, PX_5, PX_6, PX_7, PX_8, PX_9 };

// List of layer pins so we can activate a layer or not.
// NOTE: we will activate one layer at a time.
const byte LAYER[CUBE_SIZE] = { LR_BOT, LR_MID, LR_TOP };

// Shared cube state buffer. Animation->show() will "print" out the state.
byte DATA[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE];

/**
   A flag that can be inspected to determine if se should print tracing to Serial.
*/
boolean _debugFlag = false;




