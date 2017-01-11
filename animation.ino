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
   Set the animation to update the animation
   in the number of ticks in milliseconds.
   Thus 1000 wil cause the animation to
   ecexute the core update implementation
   once a second.
*/
Animation::Animation(unsigned long ticks) {
  setTimer(ticks);
}

/**
   Turns off all the LEDs and
   sets the finished flag to false.

   Subclasses should override to perform any cleanup
   they need to perform then call the base class' method.
*/
void Animation::reset() {
  trace("Reset animation...");
  finished(false);
  for ( int x = 0; x < CUBE_SIZE; x++ ) {
    for ( int y = 0; y < CUBE_SIZE; y++ ) {
      for ( int z = 0; z < CUBE_SIZE; z++ ) {
        DATA[x][y][z] = LOW;
      }
    }
  }
}

/**
   Set the finished indicator.
*/
void Animation::finished(boolean state) {
  if ( isDebug() ) {
    printName();
    trace("Finished!"+state);
  }
  _finished = state;
}

/**
   Read the finished indicator or
   subclasses may override to implement
   more complex finished logic and calculations.
*/
boolean Animation::finished() {
  return _finished;
}

/**
   Set the number of ticks to pass between
   before update changes the state of the LED
   cube.
*/
void Animation::setTimer(unsigned long ticks ) {
  _rate = ticks;
  _nextMillis = 0;
}

/**
   Check to see if the number of ticks have
   passed from the previous time.
*/
boolean Animation::isTimeup() {
  unsigned long ticks = millis();
  if  (_rate == 0 ||  ticks > _nextMillis ) {
    if ( _rate > 0 ) {
      _nextMillis = ticks + _rate;
      if (isDebug()) {
        printName();
        String m = String();
        m += "nextTimeup.  rate= "; m += _rate;
        m += ", nextMillis= "; m += _nextMillis;
        m += ", time= "; m += ticks;
        trace(m);
      }
    }
    return true;
  }
  return false;
}

void Animation::setName(String name ) {
  _name = name;
}

void Animation::printName() {
  trace("Anim: " + _name);
}

/**
   Uses "digitalWrite()" which is S-L-O-W and takes 10s of millis
   to process.  Write out all the LEDS for each layer and "flashes"
   them for a millis.

   TODO: Should be changed to be more board specific and write
   directly to PORTx registers with appropriate masks.
*/
void Animation::show() {
  for (int z = 0; z < CUBE_SIZE; z++) {
    selectLayer(z);
    for (int y = 0; y < CUBE_SIZE; y++) {
      for (int x = 0; x < CUBE_SIZE; x++) {
        int p = CUBE_SIZE * y + x;

        if (DATA[x][y][z]) {
          digitalWrite(GRID[p], DATA[x][y][z] );
        }
      }
    }
    delay(1);
    for ( int p = 0; p < PIXEL_COUNT; p++) {
      digitalWrite(GRID[p], LOW );
    }
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

