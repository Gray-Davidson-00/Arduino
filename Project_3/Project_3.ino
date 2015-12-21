const int sensorPin = A0;
const float baselineTemp = 25.0;

void setup(){
    Serial.begin(9600); //open a serial port
    
    for(int pinNumber = 2; pinNumber<5; pinNumber++) {
      pinMode(pinNumber, OUTPUT);
      digitalWrite(pinNumber, LOW);
    }
}


void loop(){
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value:  ");
  Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(", Volts ");
  Serial.print(voltage);
  
  Serial.print(", Degrees C ");
  //Convert voltage to degrees centegrade  
  float temperature = (voltage-.5)*100;
  Serial.println(temperature);
  
  if(temperature < baselineTemp){ // temperature at or below 20C

  digitalWrite(2, LOW);   //White
  digitalWrite(3, LOW);    //Red
  digitalWrite(4, LOW);    //Green
}

else if(temperature > baselineTemp+2 && temperature < baselineTemp+4){  //Temperature rises
  digitalWrite(2, HIGH);   //White
  digitalWrite(3, LOW);    //Red
  digitalWrite(4, LOW);    //Green
}

else if(temperature > baselineTemp+4 && temperature < baselineTemp+6){  //Temperature rises
  digitalWrite(2, HIGH);   //White
  digitalWrite(3, HIGH);    //Red
  digitalWrite(4, LOW);    //Green
}

else if(temperature > baselineTemp+6){  //Temperature rises
  digitalWrite(2, HIGH);   //White
  digitalWrite(3, HIGH);    //Red
  digitalWrite(4, HIGH);    //Green
}
delay(1);
}
