/*
  NAVER Software Education Project(Arduino): Read Capacitive Sensors
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

#include<CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(4,2);

int th = 120;
int LED = 13;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
} 

void loop()
{
  long sensorValue = sensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  
  if (sensorValue > th) 
  {
    digitalWrite(LED, HIGH);
  } 
  else 
  {
    digitalWrite(LED, LOW);
  }
  delay(10);
}

