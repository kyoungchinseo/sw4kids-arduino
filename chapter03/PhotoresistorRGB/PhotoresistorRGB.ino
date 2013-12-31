/*
  NAVER Software Education Project(Arduino): Photoresistors & RGB LED
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

int RED_SENSOR = A0;
int GREEN_SENSOR = A1;
int BLUE_SENSOR = A2;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

int redLEDValue = 0;
int greenLEDValue = 0;
int blueLEDValue = 0;

int minValue = 600;
int maxValue = 900;

void setup()
{
  Serial.begin(9600);
  
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop()
{
  
  redSensorValue = analogRead(RED_SENSOR);
  delay(5);
  greenSensorValue = analogRead(GREEN_SENSOR);
  delay(5);
  blueSensorValue = analogRead(BLUE_SENSOR);
  delay(5);
  
  Serial.print("RED: ");
  Serial.println(redSensorValue);
  Serial.print("GREEN: ");
  Serial.println(greenSensorValue);
  Serial.print("BLUE: ");
  Serial.println(blueSensorValue);
  
  redLEDValue = map(redSensorValue, minValue,maxValue ,0,255);
  greenLEDValue = map(greenSensorValue, minValue,maxValue, 0,255);
  blueLEDValue = map(blueSensorValue, minValue, maxValue ,0,255);  
  redLEDValue = constrain(redLEDValue, 0 ,255);
  greenLEDValue =  constrain(greenLEDValue, 0, 255);
  blueLEDValue = constrain(blueLEDValue, 0, 255);
  
  analogWrite(RED_LED,redLEDValue);
  analogWrite(GREEN_LED,greenLEDValue);
  analogWrite(BLUE_LED,blueLEDValue);
  
}
