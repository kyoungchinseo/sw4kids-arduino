/*
  NAVER Software Education Project: Paper Interface (Processing Part)
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

float rotX = 0;
float rotY = 0;
 
void setup() 
{ 
  size(800, 600, P3D); 
  colorMode(RGB, 1); 
  
  port = new Serial(this, "COM4", 9600);
} 
 
void draw() 
{   
  while(port.available()>0)
  {
    String buffer = port.readStringUntil(10);
    if (buffer != null)
    {
      String [] val = split(buffer,",");
      int [] values;
      values = int(val);
      if (val.length > 3) 
      {
        println(values[0] + "," + values[1] + "," + values[2]);
        if (values[0] == 1) 
        {
          rotY = rotY - 0.1;
        }
        if (values[1] == 1) 
        {
          rotX = rotX - 0.1;
        }
        if (values[2] == 1) 
        {
          rotY = rotY + 0.1;
        }
      }      
      println("rotX: " + rotX + " rotY: " + rotY);
    }
  }
  
  background(0.2);
  
  pushMatrix(); 
  translate(width/2, height/2, -30);   
  rotateX(rotX);
  rotateY(rotY);  
  scale(150);
  beginShape(QUADS);
    fill(0, 1, 1); vertex(-1,  1,  1);
    fill(1, 1, 1); vertex( 1,  1,  1);
    fill(1, 0, 1); vertex( 1, -1,  1);
    fill(0, 0, 1); vertex(-1, -1,  1);
  
    fill(1, 1, 1); vertex( 1,  1,  1);
    fill(1, 1, 0); vertex( 1,  1, -1);
    fill(1, 0, 0); vertex( 1, -1, -1);
    fill(1, 0, 1); vertex( 1, -1,  1);
  
    fill(1, 1, 0); vertex( 1,  1, -1);
    fill(0, 1, 0); vertex(-1,  1, -1);
    fill(0, 0, 0); vertex(-1, -1, -1);
    fill(1, 0, 0); vertex( 1, -1, -1);
  
    fill(0, 1, 0); vertex(-1,  1, -1);
    fill(0, 1, 1); vertex(-1,  1,  1);
    fill(0, 0, 1); vertex(-1, -1,  1);
    fill(0, 0, 0); vertex(-1, -1, -1);
  
    fill(0, 1, 0); vertex(-1,  1, -1);
    fill(1, 1, 0); vertex( 1,  1, -1);
    fill(1, 1, 1); vertex( 1,  1,  1);
    fill(0, 1, 1); vertex(-1,  1,  1);
  
    fill(0, 0, 0); vertex(-1, -1, -1);
    fill(1, 0, 0); vertex( 1, -1, -1);
    fill(1, 0, 1); vertex( 1, -1,  1);
    fill(0, 0, 1); vertex(-1, -1,  1);
  endShape();  
  popMatrix(); 
} 
