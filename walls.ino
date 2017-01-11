/**
  Copyright (c) 2017 by Nicholas R. Ustick <nick@stoicprogrammer.com>

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
int LEFT_RIGHT = 0;
int RIGHT_LEFT = 1;
int BOTTOM_TOP = 2;
int TOP_BOTTOM = 3;
int FRONT_BACK = 4;
int BACK_FRONT = 5;

Walls::Walls(unsigned long rate) : Animation(rate) {
  setName("Walls");
  _plane = 0;
  _direction = LEFT_RIGHT;
}

boolean Walls::update() {
  if (_plane > CUBE_SIZE) {
    finished(true);
    _plane = 0;
    return true;
  }

  if (isTimeup()) {
    for (int z = 0; z < CUBE_SIZE ; z++) {
      for (int y = 0; y < CUBE_SIZE; y++ ) {
        DATA[_plane][y][z] = true;
      }
    }
    _plane++;
    return true;
  }
  return false;
}



