/*
  NAVER Software Education Project(Arduino): Gesture-based Instrument
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

#include "pitches.h"

int XAXIS = A1;
int YAXIS = A0;

int BUTTON_PLAY = 2;
int BUTTON_STOP = 3;
int SPEAKER = 9;

int xSensorValue = 0;
int ySensorValue = 0;

float minValue = 250.0;
float maxValue = 300.0;

int noteIndex = 0;
int scaleIndex = 0;

bool playStatus = false;

int note[] = { 
  NOTE_C2,NOTE_D2,NOTE_E2,NOTE_F2,
  NOTE_G2,NOTE_A2,NOTE_B2,
  NOTE_C3,NOTE_D3,NOTE_E3,NOTE_F3,
  NOTE_G3,NOTE_A3,NOTE_B3,
  NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,
  NOTE_G4,NOTE_A4,NOTE_B4,
  NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,
  NOTE_G5,NOTE_A5,NOTE_B5,
  NOTE_C6,NOTE_D6,NOTE_E6,NOTE_F6,
  NOTE_G6,NOTE_A6,NOTE_B6,
  NOTE_C7,NOTE_D7,NOTE_E7,NOTE_F7,
  NOTE_G7,NOTE_A7,NOTE_B7};


void setup() 
{
  Serial.begin(9600);
  pinMode(BUTTON_PLAY, INPUT);
  pinMode(BUTTON_STOP, INPUT);
}

void loop() 
{  
  if (digitalRead(BUTTON_PLAY) == HIGH) 
  {
    playStatus = true;
  }
  
  if (digitalRead(BUTTON_STOP) == HIGH) 
  {
    noTone(SPEAKER);    
    playStatus = false;
  } 
 
  if (playStatus)
  {
    xSensorValue = analogRead(XAXIS);
    ySensorValue = analogRead(YAXIS);
          
    noteIndex = map(xSensorValue, minValue, maxValue, 0,70);
    noteIndex = constrain(noteIndex/10.0, 0, 6);
    scaleIndex = map(ySensorValue, minValue, maxValue, 0,30);    
    scaleIndex = constrain(scaleIndex/10.0, 0, 3)+2;
    
    Serial.print(" X Axis: ");
    Serial.print(xSensorValue);
    Serial.print(" Y Axis: " );
    Serial.print(ySensorValue);
    Serial.print(" note: ");
    Serial.print(noteIndex);
    Serial.print(" scale: " );
    Serial.println(scaleIndex);
    
    tone(SPEAKER, note[scaleIndex*7+noteIndex]);

    delay(125);
  }  
}


