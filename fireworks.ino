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

Fireworks::Fireworks() {
  setTimer(50);
}

Fireworks::Fireworks(unsigned long rate) : Animation(rate) {
}

boolean Fireworks::update() {
  if (isTimeup()) {
    updateState();
    nextTimeup();
    return true;
  }
  return false;
}

void Fireworks::updateState() {
  const boolean SPARKLE_LEDS[3][3] = {
    {true, true, true },
    {true, false, true },
    {true, true, true },
  };

  switch (_state) {
    case LAUNCH: {
        DATA[1][1][_count] = true;
        if ( _count > 0 ) {
          DATA[1][1][_count - 1] = false;
        }
        _count++;
        if ( _count == CUBE_SIZE ) {
          _state = SPARKLE;
        }
        setTimer(50*(_count+1));
      }
      break;

    case SPARKLE: {
        reset();
        _count--;

        if ( _count < 0 ) {
          _count = 0;
          _state = LAUNCH;
          break;
        }

        for (int x = 0; x < CUBE_SIZE; x++) {
          for (int y = 0; y < CUBE_SIZE; y++) {
            DATA[x][y][_count] = SPARKLE_LEDS[x][y];
          }
        }
        setTimer(100*(4-_count));
        }
      break;

    default:
      break;
  }
}

