
int motor1Pin = 3;
int motor2Pin = 6;
int motor3Pin = 9;
int motor4Pin = 11;

int ledPin = 5;
  unsigned long previousMillis;
  unsigned long pMill;
  unsigned long cMill;
  unsigned long cSpeed = 120;
  unsigned long mSpeed;
  int ledState = LOW;

void setup() 
{ 
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin,OUTPUT);
  pinMode(motor3Pin,OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
//  PWM();
  pinMode(ledPin,OUTPUT);
 // digitalWrite(5,HIGH);
 //led();
} 
 
 
void loop() 
{ 
    analogWrite(11,90);
     analogWrite(motor1Pin,80);
   analogWrite(motor2Pin,80);
  // analogWrite(motor3Pin,80);
 // digitalWrite(5,HIGH);
  cilia();
 // motors();
  led();
  //analogWrite(11,100);
  
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    Serial.println(speed);
    
    analogWrite(motor1Pin, speed);
      
    
  }
}

void cilia(){
 /* unsigned long currentMillis = millis();
  if(currentMillis - cMill > 60) {
    // save the last time you blinked the LED 
    cMill = currentMillis;   
    if(cSpeed == 120){
    cSpeed= 0;  
   }
  else{
    cSpeed = 120;
  }
   analogWrite(motor4Pin,cSpeed);
  }
  //analogWrite(motor4Pin,200);*/
}



void motors(){
  unsigned long currentMillis = millis();
  if(mSpeed == 70){
  if(currentMillis - previousMillis > 140) {
    // save the last time you blinked the LED 
    pMill = currentMillis;   
 
    // if the LED is off turn it on and vice-versa:
    if (mSpeed == 0)
      mSpeed = 200;
    else
      mSpeed = 0;
 
    // set the LED with the ledState of the variable:
   analogWrite(motor1Pin,mSpeed);
   analogWrite(motor2Pin,mSpeed);
   analogWrite(motor3Pin,mSpeed);
  // analogWrite(motor4Pin,mSpeed);
  }
  }
  else{
    if(currentMillis - previousMillis > 150) {
    // save the last time you blinked the LED 
    pMill = currentMillis;   
 
    // if the LED is off turn it on and vice-versa:
    if (mSpeed == 0)
      mSpeed = 200;
    else
      mSpeed = 0;
 
    // set the LED with the ledState of the variable:
   analogWrite(motor1Pin,mSpeed);
   analogWrite(motor2Pin,mSpeed);
   analogWrite(motor3Pin,mSpeed);
//   analogWrite(motor4Pin,mSpeed);
  }
  }
  }

 

void led(){
 //    digitalWrite(ledPin,HIGH);
  //delay(1000);
  //digitalWrite(ledPin,LOW);
  //delay(1000);
  
  unsigned long currentMillis = millis();
             // ledState used to set the LED

  if(currentMillis - previousMillis > 500) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
 
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
 
    // set the LED with the ledState of the variable:
    digitalWrite(5, ledState);
  }

}

