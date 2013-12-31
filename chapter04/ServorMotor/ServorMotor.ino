/*
  NAVER Software Education Project(Arduino): Control Servor Motor
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

#include <Servo.h>

Servo servoMotor;

int SERVO = 9;
int SENSOR = A0;

int sensorValue = 0;
int motorValue = 0;

void setup() 
{
  servoMotor.attach(SERVO);
  
  Serial.begin(9600);
} 

void loop()
{
    sensorValue = analogRead(SENSOR);
    
    motorValue = map(sensorValue, 0, 1023, 0, 179);
    
    Serial.print(" Sensor Value: ");
    Serial.print(sensorValue);
    Serial.print(" Angle Value: ");
    Serial.println(motorValue);
    
    servoMotor.write(motorValue);
    
    delay(15);
  
}

