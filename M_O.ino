const int trigpin = 34;
const int echopin = 36;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(30,HIGH);
  digitalWrite(31,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  
}

void loop() {
 char data = Serial.read();
 if(data == '1')
  {
     while(getdistance() > 20 && data != '2' && data != '3' && data != '4' && data != '5')
    {
      Serial.println('1');
      digitalWrite(4,HIGH); 
      digitalWrite(5,LOW);
      digitalWrite(30,HIGH);
      digitalWrite(31,LOW);
      data=Serial.read();
      if(data == '6')
      {
        digitalWrite(10,LOW);
        digitalWrite(11,HIGH);
      }
      if(data == '7')
      {
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
      }
      if(data == '8')
      {
        digitalWrite(8,LOW);
        digitalWrite(9,HIGH);
        delay(200);
        digitalWrite(8,HIGH);
        digitalWrite(9,HIGH);
      }
     }
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
     
  }
  else if(data == '2')
  { 
    while(data != '1' && data != '3' && data != '4' && data != '5' && data != '6' && data != '7' && data != '8')
    { 
      Serial.println('2');
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(30,LOW);
      digitalWrite(31,HIGH);
      data=Serial.read();
    }
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
  }
  else if(data == '3')
  {
    while(getdistance() > 20 && data != '2' && data != '1' && data != '4' && data != '5' && data !='6' && data != '7' && data != '8')
    { 
      Serial.println('3');
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(30,HIGH);
      digitalWrite(31,LOW);
      data=Serial.read();
    }
      
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
  }
  
  else if(data == '4')
  {   
    while(getdistance() > 20 && data != '2' && data != '1' && data != '3' && data != '5' && data !='6' && data != '7' && data != '8')
     {
      Serial.println('4');
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      data = Serial.read();
     }
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
  }
  else if(data == '5')
  {
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
  }
}
