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

#include "cube_defs.h"
#include "animation.h"
#include "cube.h"

#include "walker.h"

Cube cube = Cube();

/**
   Initialize the environment.
*/
void setup() {
  Serial.begin(115200);
  Serial.write( "arduino-cube-3x3x3 running...\n");
  cube.add(new Walker(50));
  cube.initialize();  
  //debug(true);
}

void loop() {
  cube.animate();
}


