/*
  NAVER Software Education Project(Arduino): Receive Value from PC
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

int LED = 12;

char message;
 
void setup()
{
  Serial.begin(9600);     
  Serial.println("Please send 0 (off) or 1 (on) to control LED!");
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0) 
  {
    message = Serial.read();
    
    if (message == '1') 
    {
      digitalWrite(LED, HIGH);
      Serial.println("Arduino received 1");
      Serial.println("Turn on LED!");
    }
    
    if (message == '0') 
    {
      digitalWrite(LED, LOW);
      Serial.println("Arduino received 0");
      Serial.println("Turn off LED!");
    }    
  }   
}
