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
  initializeBuffer();
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
