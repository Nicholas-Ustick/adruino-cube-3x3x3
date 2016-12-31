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

Animation::Animation() {
  setTimer(0);
}

Animation::Animation(unsigned long ticks) {
  setTimer(ticks);
}

void Animation::reset() {
  for ( int x = 0; x < CUBE_SIZE; x++ ) {
    for ( int y = 0; y < CUBE_SIZE; y++ ) {
      for ( int z = 0; z < CUBE_SIZE; z++ ) {
        DATA[x][y][z] = false;
      }
    }
  }
}

void Animation::setTimer(unsigned long ticks ) {
  _rate = ticks;
  _nextMillis = 0;
  _ticks = millis();
}

boolean Animation::isTimeup() {
  _ticks = millis();
  return (_rate == 0 ||  _ticks > _nextMillis );
}

void Animation::nextTimeup() {
  if ( _rate > 0 ) {
    _nextMillis = _ticks + _rate;
  }
  if (isDebug()) {
    String m = String();
    m += "timer tick.  _rate = "; m += _rate;
    m += ", _nextMillis = "; m += _nextMillis;
    m += ", _ticks = "; m += _ticks;
    trace(m);
  }
}


void Animation::show() {
  for (int z = 0; z < CUBE_SIZE; z++) {
    selectLayer(z);
    if (isDebug())
      Serial.println("-----------------------------");
    for (int y = 0; y < CUBE_SIZE; y++) {
      //      Serial.print("|");
      for (int x = 0; x < CUBE_SIZE; x++) {
        int p = CUBE_SIZE * y + x;

        if (isDebug()) {
          Serial.print("[");
          Serial.print(p);
          Serial.print("]=");
          Serial.print(DATA[x][y][z]);
          Serial.print(" ");
        }
        if (DATA[x][y][z]) {
          digitalWrite(GRID[p], DATA[x][y][z] );
          if (isDebug())
            delay(500);
          delay(1);
          digitalWrite(GRID[p], false );
        }
      }
      if (isDebug())
        Serial.println("|");
    }
    if (isDebug())
      Serial.println("-----------------------------");
  }
}


/**
   Turns on the selected layer.
*/
void Animation::selectLayer(int layer ) {
  for (int l = 0; l < CUBE_SIZE; l++ ) {
    if (l == layer )
      digitalWrite(LAYER[l], LOW);
    else
      digitalWrite(LAYER[l], HIGH);
  }
}
