

#include<Wire.h>

#include <TEA5767Radio.h>
#include <radio.h>
#include <LiquidCrystal.h>

TEA5767Radio radio = TEA5767Radio();
            
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);              
float frequency = 0.000; 
int f = frequency *1000;                           
int count = 0;
int menu = 1;
float step = 0.001;
                               
void setup()
{
  pinMode(8,INPUT);// menu
  pinMode(7,INPUT);// plus
  pinMode(6,INPUT);// minus
  delay(1000);
  Wire.begin();
  frequency = 52.000;                       //starting frequency
  radio.setFrequency(frequency);
  lcd.begin(16,2);
    lcd.clear(); lcd.setCursor(0,1);
    lcd.print(frequency*1000); lcd.print(" KHz");
}

  void loop()
 {
  if(digitalRead(8)==HIGH){menu++;step = step * 10; delay(300);if(menu>4){menu=1; step = 0.001;}}
  lcd.setCursor(0,0); lcd.print("Step = "); lcd.print((int) (step * 1000)); lcd.print (" KHz      ");
  
  if(digitalRead(7)==HIGH)
    {
    frequency = frequency + step; delay(200);
    if(frequency > 54.00) frequency = 54.000; frequencyUpdate();
    lcd.clear(); lcd.setCursor(0,1);
    lcd.print(frequency*1000); lcd.print(" KHz");
    }

    if(digitalRead(6)==HIGH)
    {
    frequency = frequency - step; delay(200); frequencyUpdate();
    if(frequency < 50.00) frequency = 50.000;
    lcd.clear(); lcd.setCursor(0,1);
    lcd.print(frequency*1000); lcd.print(" KHz");
    } 
}
void frequencyUpdate()                    
{
  frequency = constrain(frequency, 50.0, 54.0);
    lcd.clear(); lcd.setCursor(0,1);
    lcd.print(frequency*1000); lcd.print(" KHz");

  radio.setFrequency(frequency);


}
