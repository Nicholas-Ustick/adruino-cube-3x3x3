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

class Cube {
  public:
    Cube();
    Cube(int elements);
    void initialize();
    void animate();
    void animate(int iterations);

    void add(Animation* animation);

  private:
    /**
      One animation for now.
      Later we will ad capabilities to rotate through several animations.
    */
    Animation** animationList;
    unsigned int _current = 0;
    unsigned int _size = 0;
    unsigned int _end = 0;

    unsigned int traceLimit = 0;
    void printCubeData();
};


