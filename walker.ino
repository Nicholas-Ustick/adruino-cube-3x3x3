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

Walker::Walker() {
  startingPixel(0, 0, 0);
}

Walker::Walker(unsigned long rate) : Animation(rate) {
  startingPixel(0, 0, 0);
}


void Walker::startingPixel(int x, int y, int z) {
  _x = x;  _y = y;  _z = z;
  DATA[x][y][z] = true;
}


boolean Walker::update() {
  if (isTimeup() ) {
    int x = _x, y = _y, z = _z;
    moveToNextPixel();
    DATA[_x][_y][_z] = true;
    DATA[x][y][z] = false;
    nextTimeup();
  }
  return true;
}

void Walker::moveToNextPixel() {
  _x = incrementValue(_x, CUBE_SIZE);

  if (_x == 0 ) {
    _y = incrementValue(_y, CUBE_SIZE);
  }

  if (_x == 0 && _y == 0 ) {
    _z = incrementValue(_z, CUBE_SIZE);
  }
}

void Walker::show() {
  for (int z = 0; z < CUBE_SIZE; z++) {
    activateLayer(_z);
//    Serial.println("-----------------------------");
    for (int y = 0; y < CUBE_SIZE; y++) {
//      Serial.print("|");
      for (int x = 0; x < CUBE_SIZE; x++) {
        int p = CUBE_SIZE * y + x;
/*
        Serial.print("[");
        Serial.print(p);
        Serial.print("]=");        
        Serial.print(DATA[x][y][z]);
        Serial.print(" ");
*/
        digitalWrite(GRID[p], DATA[x][y][z] );
      }
      //Serial.println("|");
    }
//    Serial.println("-----------------------------");
//    delay(10);
  }
}

