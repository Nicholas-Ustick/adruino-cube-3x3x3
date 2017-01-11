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
    Animation(unsigned long ticks);

    /**
        Subclasses implement the logic to
        Populate the DATA for the cube on
        each loop and determine the frame rates.
        Returns "true" if the state was updated.
    */
    virtual boolean update() = 0;

    /**
       Show should be called for each frame to be painted.
    */
    void show();

    /**
       Indicates if the animation is completed.
       Call reset() to restart the animation.
    */
    boolean finished();

    /**
       Initialize the animation to a good starting point.
    */
    void reset();

    /**
       Trace out the animation's name to the Serial line.
    */
    void printName();

  protected:
    void setTimer(unsigned long ticks );
    boolean isTimeup();

    void selectLayer(int z);

    void setName(String name);
    void finished(boolean state);

  private:
    unsigned long _rate = 0;
    unsigned long _nextMillis = 0;

    String _name = "Animation";
    boolean _finished = false;
};


