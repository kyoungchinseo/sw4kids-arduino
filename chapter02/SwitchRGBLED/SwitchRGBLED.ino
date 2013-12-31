/*
  NAVER Software Education Project(Arduino): RGB LED Switch
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

int RED_LED = 11;
int GREEN_LED = 9;
int BLUE_LED = 10 ;

int BUTTON = 2;

int STATUS = 0;

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH) 
  {
    STATUS = STATUS + 1;
    if (STATUS >=7  ) 
    {
      STATUS = 0;
    }
  }
  
  switch(STATUS) 
  {
    case 0:
      analogWrite(RED_LED,255);
      analogWrite(GREEN_LED,0);
      analogWrite(BLUE_LED,0);
      break;
    case 1:
      analogWrite(RED_LED,0);
      analogWrite(GREEN_LED,255);
      analogWrite(BLUE_LED,0);
      break;
    case 2:
      analogWrite(RED_LED,0);
      analogWrite(GREEN_LED,0);
      analogWrite(BLUE_LED,255);
      break;
    case 3:
      analogWrite(RED_LED,127);
      analogWrite(GREEN_LED,0);
      analogWrite(BLUE_LED,127);
      break;
    case 4:
      analogWrite(RED_LED,0);
      analogWrite(GREEN_LED,127);
      analogWrite(BLUE_LED,127);
      break;
    case 5:
      analogWrite(RED_LED,127);
      analogWrite(GREEN_LED,127);
      analogWrite(BLUE_LED,0);
      break;
    case 6:
      analogWrite(RED_LED,70);
      analogWrite(GREEN_LED,70);
      analogWrite(BLUE_LED,70);
      break;
  }
  delay(100);  
}
