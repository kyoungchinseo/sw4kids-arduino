/*
  NAVER Software Education Project: Control Character by Arduino
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

PImage img;
Serial port;

float r = 0.0;
float s = 0.0;

void setup() 
{
  img = loadImage("character.jpg");
  int sz = 0;
  if (img.width > img.height) 
  {
    sz = img.width * 3;
  } 
  else 
  {
    sz = img.height * 3;
  }
  
  size(sz, sz, P3D);
  background(255,255,255);
  noStroke();

  port = new Serial(this, "COM4",9600);  
}

void draw() 
{
  while (port.available() > 0) 
  {
    String buffer = port.readStringUntil(10);
    if (buffer != null) 
    {
      String [] val = split(buffer, ",");
      if (val.length == 3) 
      {
        int [] values;
        values = int(val);
        r = values[0]/100.0 * PI;        
        s = values[1]/50.0 + 1.0;
      }
    }
  }
  
  background(255);
  translate(width / 2, height / 2);
  rotateZ(r);
  scale(s);
  beginShape();
    texture(img);
    vertex(-img.width,-img.height,0,0,0);
    vertex( img.width,-img.height,0,img.width, 0);
    vertex(img.width,img.height, 0,img.width, img.height);
    vertex(-img.width,img.height,0,0,img.height);
  endShape();  
}
