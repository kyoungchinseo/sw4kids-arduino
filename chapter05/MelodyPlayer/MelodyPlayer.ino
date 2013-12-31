/*
  NAVER Software Education Project(Arduino): Basic Music Player
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

int BUTTON = 2;
int SPEAKER = 9;

int sensorValue = 0;

int melody[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
int duration[] = { 250,250,250,250,250,250,250,250 };
//int melody[] = { NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
//int duration[] = { 250,125,125,250,250,250,250,250 };

void setup() 
{
  pinMode(BUTTON, INPUT);
}

void loop() 
{  
  if (digitalRead(BUTTON) == HIGH) 
  {
    for (int i = 0; i < 8; i++) 
    {
      tone(SPEAKER, melody[i],duration[i]);
      delay(duration[i]*1.5);
    } 
    noTone(SPEAKER);
  }
}


