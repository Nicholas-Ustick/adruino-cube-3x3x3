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

const int LEFT_RIGHT = 0;
const int RIGHT_LEFT = 1;
const int BOTTOM_TOP = 2;
const int TOP_BOTTOM = 3;
const int FRONT_BACK = 4;
const int BACK_FRONT = 5;
const int SLIDE_AROUND = 6;
const int SLIDE_OVER = 7;
const int FINISHED = 8;

const int states[9] = { LEFT_RIGHT, RIGHT_LEFT, BOTTOM_TOP, TOP_BOTTOM, FRONT_BACK, BACK_FRONT, SLIDE_AROUND, SLIDE_OVER, FINISHED};
const int startingPlane[9] = { 0, 2, 0, 2, 0, 2, 0, 0, 0};

Walls::Walls(unsigned long rate) : Animation(rate) {
  setName("Walls");
  _direction = states[0];
  _plane = startingPlane[_direction];
}

boolean Walls::update() {
  if ( isTimeup() ) {
    nextState();
    switch ( _direction ) {
      case LEFT_RIGHT:
        moveLeftRight();
        break;
      case RIGHT_LEFT:
        moveRightLeft();
        break;
      case BOTTOM_TOP:
        moveBottomTop();
        break;
      case TOP_BOTTOM:
        moveTopBottom();
        break;
      case FRONT_BACK:
        moveFrontBack();
        break;
      case BACK_FRONT:
        moveBackFront();
        break;
      case SLIDE_AROUND:
      //moveSlideAround();
      //break;
      case SLIDE_OVER:
      //moveSlideOver();
      //break;
      default:
        finished(true);
        _direction = states[0];
        _plane = startingPlane[_direction];      
        break;
    }
    return true;
  }
  return false;
}

void Walls::nextState() {
  if (0 > _plane || _plane >= CUBE_SIZE) {
    _direction = states[_direction + 1];
    _plane = startingPlane[_direction];
    reset();
    if (FINISHED == _direction) {
      finished(true);
      _direction = states[0];
      _plane = startingPlane[_direction];
    }
  }
}

void Walls::moveLeftRight() {
  for (int z = 0; z < CUBE_SIZE ; z++) {
    for (int y = 0; y < CUBE_SIZE; y++ ) {
      DATA[_plane][y][z] = HIGH;
      if ( _plane > 0 ) {
        DATA[_plane - 1][y][z] = LOW;
      }
    }
  }
  _plane++;
}

void Walls::moveRightLeft() {
  for (int z = 0; z < CUBE_SIZE ; z++) {
    for (int y = 0; y < CUBE_SIZE; y++ ) {
      DATA[_plane][y][z] = HIGH;
      if ( _plane < CUBE_SIZE - 1) {
        DATA[_plane + 1][y][z] = LOW;
      }
    }
  }
  _plane--;
}

void Walls::moveBottomTop() {
  for (int x = 0; x < CUBE_SIZE ; x++) {
    for (int y = 0; y < CUBE_SIZE; y++ ) {
      DATA[x][y][_plane] = HIGH;
      if ( _plane > 0 ) {
        DATA[x][y][_plane - 1] = LOW;
      }
    }
  }
  _plane++;
}

void Walls::moveTopBottom() {
  for (int x = 0; x < CUBE_SIZE ; x++) {
    for (int y = 0; y < CUBE_SIZE; y++ ) {
      DATA[x][y][_plane] = HIGH;
      if ( _plane < CUBE_SIZE - 1 ) {
        DATA[x][y][_plane + 1] = LOW;
      }
    }
  }
  _plane++;
}

void Walls::moveFrontBack() {
  for (int z = 0; z < CUBE_SIZE ; z++) {
    for (int x = 0; x < CUBE_SIZE; x++ ) {
      DATA[x][_plane][z] = HIGH;
      if ( _plane > 0 ) {
        DATA[x][_plane - 1][z] = LOW;
      }
    }
  }
  _plane++;
}

void Walls::moveBackFront() {
  for (int z = 0; z < CUBE_SIZE ; z++) {
    for (int x = 0; x < CUBE_SIZE; x++ ) {
      DATA[x][_plane][z] = HIGH;
      if ( _plane < CUBE_SIZE - 1) {
        DATA[x][_plane + 1][z] = LOW;
      }
    }
  }
  _plane--;
}

void Walls::moveSlideAround() {
  _plane++;
}

void Walls::moveSlideOver() {
  _plane++;
}



