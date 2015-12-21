#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 7;
const int whiteLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup () {
  myServo.attach(9);
  pinMode(whiteLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is Unlocked!");
}

void loop () {
  if(locked == false){
    switchVal = digitalRead(switchPin);
    Serial.println(switchVal);
    if(switchVal == HIGH){
       locked = true;
       digitalWrite(greenLed, LOW);
       digitalWrite(redLed, HIGH);
       myServo.write(90);
       Serial.println("The Box is locked!");
       delay (1000);
    }
  }
  
  if(locked == true){
    knockVal = analogRead(piezo);
    if(numberOfKnocks < 3 && knockVal > 0){
      if(checkForKnock(knockVal) == true){
        numberOfKnocks++;
      }
      Serial.print(3-numberOfKnocks);
      Serial.println(" knocks to go");
    }
    
    if(numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
      numberOfKnocks = 0;
    }
  }
}
boolean checkForKnock(int value){
  if(value > quietKnock && value < loudKnock){
    digitalWrite(whiteLed, HIGH);
    delay(50);
    digitalWrite(whiteLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else {
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
