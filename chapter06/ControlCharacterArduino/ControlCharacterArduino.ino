/*
  NAVER Software Education Project(Arduino): Send Control Signal to PC
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

int SENSOR_ROTATION = A0;
int SENSOR_SCALE = A1;

int sensorRotationValue = 0;
int sensorScaleValue = 0;

int serialRotationValue = 0;
int serialScaleValue = 0;

String message = "";

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  message="";
  sensorRotationValue = analogRead(SENSOR_ROTATION);
  sensorScaleValue = analogRead(SENSOR_SCALE);
  serialRotationValue = map(sensorRotationValue,0,1023,0,100);
  serialRotationValue = constrain(serialRotationValue,0,100);
  serialScaleValue = map(sensorScaleValue,0,1023,0,100);
  serialScaleValue = constrain(serialScaleValue,0,100);
  message = String(serialRotationValue)+","+String(serialScaleValue)+","+String(0);
  Serial.println(message); 
}
