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
   Defines a baseclass for how animations can be done.
*/
class Animation {
  public:
    Animation();
    Animation(unsigned long ticks);

    void reset();
    void show();

    /** Subclasses implement the logic to
     *  Populate the DATA for the cube on
     *  each loop and determine the frame rates.
     */
    virtual boolean update() = 0;

  protected:
    void setTimer(unsigned long ticks );
    boolean isTimeup();
    void nextTimeup();

    void selectLayer(int z);

    // Maintains the  pixel settings.
    boolean DATA[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE];
      
  private:
    unsigned long _rate = 0;
    unsigned long _nextMillis = 0;
    unsigned long _ticks = 0;

};

