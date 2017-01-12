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

RandPixel::RandPixel(unsigned long rate): Animation(rate) {
}

boolean RandPixel::update() {
  static int frames = 0;
  static int x = -1, y = -1, z = -1;
  if (isTimeup()) {
    frames++;
    if (x != -1 && y != -1 && z != -1) {
      DATA[x][y][z] = LOW;
      if (frames == 25) {
        finished(true);
        x = -1, y = -1, z = -1;
        frames = 0;
        return true;
      }
    }
    x = random(0, CUBE_SIZE);
    y = random(0, CUBE_SIZE);
    z = random(0, CUBE_SIZE);
    DATA[x][y][z] = HIGH;
    return true;
  }
  return false;
}

