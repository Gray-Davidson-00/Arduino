#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup(){
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("What the fuck");
  lcd.setCursor(0, 1);
  lcd.print("do you want?");
}

void loop(){
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Arduino says");
      lcd.setCursor(0,1); 
      switch(reply){
        
        case 0:
        lcd.print("Fuck You!");
        break;
        
        case 1:
        lcd.print("What the Shit?");
        break;
        
        case 2:
        lcd.print("Prophecy's Fake.");
        break;
        
        case 3:
        lcd.print("Go Away!");
        break;
        
        case 4:
        lcd.print("Stop This.");
        break;
        
        case 5:
        lcd.print("Won't Work.");
        break;
        
        case 6:
        lcd.print("Are you HIGH?");
        break;
        
        case 7:
        lcd.print("No.");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
