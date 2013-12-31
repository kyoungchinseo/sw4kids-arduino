/*
  NAVER Software Education Project(Arduino): Change LED Colors by PC
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

int G = 9;
int B = 10;
int R = 11;

int red = 0;
int green = 0;
int blue = 0;

void setup()
{
  Serial.begin(9600);  
}

void loop()
{
  while(Serial.available() > 0) 
  {
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();
    if (Serial.read() == '\n') 
    {
      analogWrite(R,red);
      analogWrite(G,green);
      analogWrite(B,blue);      
    }
  }  
}
