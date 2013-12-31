/*
  NAVER Software Education Project(Arduino): Blink LED using PWM
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

int LED = 8;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  for(int i=0;i<256;i++)
  {
    analogWrite(LED,i);
    delay(10);
  }
  for(int i=255;i>=0;i--) 
  {
    analogWrite(LED,i);
    delay(10);
  }
    
  
}
