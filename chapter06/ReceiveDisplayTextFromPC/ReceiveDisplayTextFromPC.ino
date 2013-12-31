/*
  NAVER Software Education Project(Arduino): Send Text to Arduino
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

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String message = "";
char data;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
  lcd.print("Waiting Message!");
}

void loop()
{
  if (Serial.available()) 
  { 
    delay(100);  
    while (Serial.available() > 0) 
    {    
      data = Serial.read();
      message += String(data);   
    }
    lcd.clear();
    lcd.print(message);
    Serial.println(message);
    message = "";
  }
}
