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

Cube::Cube(int elements) {
  animationList = new Animation*[elements];
  _size = elements;
  _end = 0;
}

void Cube::initialize() {
  trace("initialize cube.");
  initializeIO();
}

void Cube::animate() {
  printCubeData();
  if (valueInRange(_current, _end)) {
    Animation* a = animationList[_current];
    if ( a->finished() ) {
      a->reset();
      trace("animation complete" );
      _current++;
      if ( _current == _end ) {
        _current = 0;
      }
      printCubeData();
    }
    else {
      a->update();
      a->show();
    }
  }
  else if (isDebug() ) {
    String m = String("Animation cursor out of range.");
    m += " cursor=" + _current;
    m += ", end=" + _end;
    trace(m);
  }
}

void Cube::printCubeData() {
  if (isDebug() && (traceLimit % 20) == 0 ) {
    String m = String("Cube data: ");
    m += " cursor="; m += _current;
    m += ", end="; m += _end;
    trace(m);
  }
  traceLimit++;
}

void Cube::animate(int iterations) {
  animate();
}

void Cube::add(Animation *animation) {
  trace("Add animation.");
  animation->printName();
  if ( _end < _size ) {
    animation->reset();
    animationList[_end] = animation;
    _end++;
  }
}


