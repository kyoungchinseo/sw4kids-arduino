/*
  NAVER Software Education Project(Arduino): Paper Interface
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

CapacitiveSensor sensorLeft = CapacitiveSensor(4,2);
CapacitiveSensor sensorMiddle = CapacitiveSensor(4,5);
CapacitiveSensor sensorRight = CapacitiveSensor(4,8);

int th = 120;
int LED = 13;

int buttonLeft = 0;
int buttonMiddle = 0;
int buttonRight = 0;

String message = "";

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
} 

void loop()
{
  long sensorLeftValue = sensorLeft.capacitiveSensor(30);
  long sensorMiddleValue = sensorMiddle.capacitiveSensor(30);
  long sensorRightValue = sensorRight.capacitiveSensor(30);
  
  if (sensorLeftValue > th || sensorMiddleValue > th || sensorRightValue > th) 
  {
    digitalWrite(LED, HIGH);
  } 
  else 
  {
    digitalWrite(LED, LOW);
  }
  
  if (sensorLeftValue > th) 
  {
    buttonLeft = 1;
  } 
  else 
  {
    buttonLeft = 0;
  }
  
  if (sensorMiddleValue > th) 
  {
    buttonMiddle = 1;
  } 
  else 
  {
    buttonMiddle = 0;
  }
  
  if (sensorRightValue > th) 
  {
    buttonRight = 1;
  } 
  else 
  {
    buttonRight = 0;
  }
  message = String(buttonLeft)+","+String(buttonMiddle)+","+String(buttonRight)+","+String(0);
  Serial.println(message);  
     
  delay(10);
}

