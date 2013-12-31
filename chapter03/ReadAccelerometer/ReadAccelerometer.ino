/*
  NAVER Software Education Project(Arduino): Read Accelerometer
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

int xAxis = A2;
int yAxis = A1;
int zAxis = A0;

int xSensorValue = 0;
int ySensorValue = 0;
int zSensorValue = 0;

int RED_LED = 9;
int GREEN_LED = 10;
int BLUE_LED = 11;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

float minValue = 200.0;
float maxValue = 400.0;

void setup()
{
  Serial.begin(9600);  
  
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
    
}

void loop()
{
  
  xSensorValue = analogRead(xAxis);
  ySensorValue = analogRead(yAxis);
  zSensorValue = analogRead(zAxis);
  
  Serial.print(" X AXIS: ");
  Serial.print(xSensorValue); 
  Serial.print(" Y AXIS: ");
  Serial.print(ySensorValue); 
  Serial.print(" Z AXIS: ");
  Serial.println(zSensorValue); 

  redValue = 255.0*(xSensorValue - minValue)/(maxValue-minValue);
  greenValue = 255.0*(ySensorValue - minValue)/(maxValue-minValue);
  blueValue = 255.0*(zSensorValue - minValue)/(maxValue-minValue);
  if (redValue > 255)
    redValue = 255;
  if (redValue < 0 ) 
    redValue  = 0;  
  if (greenValue > 255) 
    greenValue = 255;
  if (greenValue < 0 ) 
    greenValue = 0;
  if (blueValue > 255) 
    blueValue = 255;
  if (blueValue < 0 )
    blueValue = 0;
  
  Serial.print(" RED: ");
  Serial.print(redValue); 
  Serial.print(" GREEN: ");
  Serial.print(greenValue); 
  Serial.print(" BLUE: ");
  Serial.println(blueValue); 
  
  analogWrite(RED_LED, redValue);
  analogWrite(GREEN_LED, greenValue);
  analogWrite(BLUE_LED, blueValue);
  
  delay(10);
}
