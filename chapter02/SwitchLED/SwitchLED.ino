/*
  NAVER Software Education Project(Arduino): LED Light Switch
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

int LED1 = 8;
int LED2 = 9;
int LED3 = 10;

int BUTTON = 2;

int STATUS = 0;

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH) 
  {
    STATUS = STATUS + 1;
    if (STATUS >=3 ) 
    {
      STATUS = 0;
    }
  }
  
  switch(STATUS) 
  {
    case 0:
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);            
      break;
    case 1:
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);            
      break;
    case 2:
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,HIGH);            
      break;
  }
  delay(100);
  
}
