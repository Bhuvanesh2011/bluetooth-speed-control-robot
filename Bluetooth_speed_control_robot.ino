


#define light_FR   9    //Front Light   Digital pin 9 
#define light_RE   10   //Rear Light   Digital pin 10 
#define horn_BUZZ  11   //Horn    Digital pin 11
#define light_EX   12   //Extra Light    Digital pin 12

//L293 Connection  
  const int motorAspeed  = 3;
  const int motorA1      = 4;  
  const int motorA2      = 5;  
  const int motorB1      = 6;
  const int motorB2      = 7; 
  const int motorBspeed  = 8;

  int command;    
  int vSpeed=200;     // Default speed, from 0 to 255
  
  boolean lightFront = false;
  boolean lightRear  = false;
  boolean hornBUZZER   = false;
  boolean lightExtra = false;

void setup() {  
    // Set pins as outputs:
    pinMode(light_FR, OUTPUT);
    pinMode(light_RE, OUTPUT);
    pinMode(horn_BUZZ, OUTPUT);
    pinMode(light_EX, OUTPUT);
    
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT); 
    
    Serial.begin(9600); 

  } 

/***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
void goAhead(){
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,HIGH);                       
  delay(1);
  
  digitalWrite (motorB1,HIGH);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
  }
  /**********************Forward Left************************/
  //If state is equal with letter 'I', car will go forward left
void goAheadLeft(){
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,HIGH);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'G', car will go forward right
void goAheadRight(){
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,HIGH);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, vSpeed);
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
void goBack(){
  digitalWrite (motorA1,HIGH);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'J', car will go backward left
void goBackLeft(){
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, vSpeed);
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'H', car will go backward right
void goBackRight(){
  digitalWrite (motorA1,HIGH);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
void goLeft(){
  digitalWrite (motorA2,HIGH);
  delay(1);
  digitalWrite(motorA1,LOW);                       
  delay(1);
  
  digitalWrite (motorB2,HIGH);
  delay(1);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
void goRight(){
  digitalWrite (motorA2,LOW);
  delay(1);
  digitalWrite(motorA1,HIGH);                       
  delay(1);
  
  digitalWrite (motorB2,LOW);
  delay(1);
  digitalWrite(motorB1,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);    
    }

     /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
void stopRobot(){
   analogWrite(motorA1, 0);           analogWrite(motorA2, 0); 
   analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }
    
  
void loop(){
  
if (Serial.available() > 0) {
  command = Serial.read();
  stopRobot();      //Initialize with motors stopped.

if (lightFront)  {digitalWrite(light_FR, HIGH);}
if (!lightFront) {digitalWrite(light_FR, LOW);}
if (lightRear)   {digitalWrite(light_RE, HIGH);}
if (!lightRear)  {digitalWrite(light_RE, LOW);}
if (hornBUZZER)  {digitalWrite(horn_BUZZ, HIGH);}
if (!hornBUZZER) {digitalWrite(horn_BUZZ, LOW);}
if (lightExtra)  {digitalWrite(light_EX, HIGH);}
if (!lightExtra) {digitalWrite(light_EX, LOW);}

switch (command) {
case 'F':goAhead();break;
case 'B':goBack();break;
case 'L':goLeft();break;
case 'R':goRight();break;
case 'I':goAheadRight();break;
case 'G':goAheadLeft();break;
case 'J':goBackRight();break;
case 'H':goBackLeft();break;
case 'D':stopRobot();break;
case '0':vSpeed = 0;break;
case '1':vSpeed = 25.5;break;
case '2':vSpeed = 51;break;
case '3':vSpeed = 76.5;break;
case '4':vSpeed = 102;break;
case '5':vSpeed = 127.5;break;
case '6':vSpeed = 153;break;
case '7':vSpeed = 178.5;break;
case '8':vSpeed = 204;break;
case '9':vSpeed = 229.5;break;
case 'q':vSpeed = 255;break;
case 'W':lightFront = true;break;
case 'w':lightFront = false;break;
case 'U':lightRear  = true;break;
case 'u':lightRear  = false;break;
case 'V':hornBUZZER = true;break;
case 'v':hornBUZZER = false;break;
case 'X':lightExtra = true;break;
case 'x':lightExtra = false;break;            
}
}
}
