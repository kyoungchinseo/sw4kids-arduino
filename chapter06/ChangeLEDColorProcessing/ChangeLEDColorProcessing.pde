/*
  NAVER Software Education Project: Select Color and Send it to Arduino
  Copyright (C) 2014  Kyoungchin SEO, NHN NEXT

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import processing.serial.*;

Serial port;

int segs = 12;
int steps = 8;
float rotAdjust = TWO_PI / segs / 2;
float radius;
float segWidth;
float interval = TWO_PI / segs;

void setup() 
{
  port = new Serial(this, "COM4",9600);  
  
  size(400, 400);
  background(0);
  smooth();
  ellipseMode(RADIUS);
  noStroke();
  radius = min(width, height) * 0.45;
  segWidth = radius / steps;
}

void draw()
{
  drawShadeWheel();
  
  if (mousePressed) 
  {
    color sample = get(mouseX,mouseY);
    int r = int(red(sample));
    int g = int(green(sample));
    int b = int(blue(sample));
    port.write(r+" "+g+" "+b+"\n");
    delay(10);
  }
}

void drawShadeWheel() 
{
  for (int j = 0; j < steps; j++) 
  {
    color[] cols = { 
      color(255-(255/steps)*j, 255-(255/steps)*j, 0), 
      color(255-(255/steps)*j, (255/1.5)-((255/1.5)/steps)*j, 0), 
      color(255-(255/steps)*j, (255/2)-((255/2)/steps)*j, 0), 
      color(255-(255/steps)*j, (255/2.5)-((255/2.5)/steps)*j, 0), 
      color(255-(255/steps)*j, 0, 0), 
      color(255-(255/steps)*j, 0, (255/2)-((255/2)/steps)*j), 
      color(255-(255/steps)*j, 0, 255-(255/steps)*j), 
      color((255/2)-((255/2)/steps)*j, 0, 255-(255/steps)*j), 
      color(0, 0, 255-(255/steps)*j),
      color(0, 255-(255/steps)*j, (255/2.5)-((255/2.5)/steps)*j), 
      color(0, 255-(255/steps)*j, 0), 
      color((255/2)-((255/2)/steps)*j, 255-(255/steps)*j, 0) 
    };
    for (int i = 0; i < segs; i++) 
    {
      fill(cols[i]);
      arc(width/2, height/2, radius, radius, 
          interval*i+rotAdjust, interval*(i+1)+rotAdjust);
    }
    radius -= segWidth;
  }
}
 
