void setup(){
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (2, INPUT);
}  
  
  
int switchState = 0;

void loop(){

switchState = digitalRead(2);
// This is a Comment.



if(switchState == LOW){ // The Button is NOT Pressed

  digitalWrite(3, HIGH);   //White
  digitalWrite(4, LOW);    //Red
  digitalWrite(5, LOW);    //Green
}

else{  //The Button is Pressed
  digitalWrite(3, LOW);   //White
  digitalWrite(4, LOW);    //Red
  digitalWrite(5, HIGH);    //Green
  
  delay(250); //Wait for 250 ms and then toggle the LEDs
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(250); //Wait another 250 ms.
}

} //Endloop
  
