/*
  NAVER Software Education Project(Arduino): Control Speed of DC Motor
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

int SENSOR = A0;
int MOTOR = 9;

int sensorValue = 0;
int motorValue = 0;

void setup() 
{
  pinMode(MOTOR, OUTPUT);
} 

void loop()
{
  sensorValue = analogRead(SENSOR);
  
  motorValue = map(sensorValue, 0 ,1023, 0, 255);
  
  analogWrite(MOTOR, motorValue);
  
}

