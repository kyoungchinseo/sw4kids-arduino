/*
  NAVER Software Education Project(Arduino): Button Piano
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

int BUTTON_DO = 2;
int BUTTON_RE = 3;
int BUTTON_MI = 4;
int BUTTON_FA = 5;
int BUTTON_SO = 6;

int SPEAKER = 9;

int note[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4 };

void setup() 
{
  pinMode(BUTTON_DO, INPUT);
  pinMode(BUTTON_RE, INPUT);
  pinMode(BUTTON_MI, INPUT);
  pinMode(BUTTON_FA, INPUT);
  pinMode(BUTTON_SO, INPUT);
}

void loop() 
{
  while (digitalRead(BUTTON_DO) == HIGH)
    tone(SPEAKER, note[0]);
  while (digitalRead(BUTTON_RE) == HIGH)
    tone(SPEAKER, note[1]);
  while (digitalRead(BUTTON_MI) == HIGH)
    tone(SPEAKER, note[2]);
  while (digitalRead(BUTTON_FA) == HIGH)
    tone(SPEAKER, note[3]);
  while (digitalRead(BUTTON_SO) == HIGH)
    tone(SPEAKER, note[4]);  
  
  delay(100);
    
  noTone(SPEAKER);
}


