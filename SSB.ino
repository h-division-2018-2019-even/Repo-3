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

void loop() 
{
  char data = Serial.read();
  Serial.println(getdistance());
  if(getdistance()<11)
  {
     delay(50);
     if(getdistance()<11)
        bot_stop();
  }      
  else if(data == '1')
      move_fwd();
  else if(data == '2')  
      move_back();
  else if(data == '3')
      move_left();
  else if(data == '4')
      move_right();
  else if(data == '5')
      bot_stop();
  else if(data == '6')
      start_seed();
  else if(data == '7')
      stop_seed();
  else if(data == '8')
      watering();
  else if(data == '9')
  {
    while(data!= "10")
    {
       move_fwd();
       start_seed();
       Serial.println("1234747565758798687675655645345345354");
       watering();    
       if(getdistance()<11)
       {
         delay(50);
         if(getdistance()<11)
         {
           bot_stop;
           move_back();
           delay(1000);
           bot_stop();
           move_right();
           delay(2000);
           bot_stop();
         } 
       }
       data = Serial.read();
    }
    bot_stop(); 
  }
}

void move_fwd()
{

      digitalWrite(4,HIGH); 
      digitalWrite(5,LOW);
      digitalWrite(30,HIGH);
      digitalWrite(31,LOW);
}

void move_back()
{
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(30,LOW);
      digitalWrite(31,HIGH);
}

void move_left()
{
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(30,HIGH);
      digitalWrite(31,LOW);
}

void move_right()
{
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
}

void bot_stop()
{
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
}

void start_seed()
{
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      
}

void stop_seed()
{
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
}

void watering()
{
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      delay(200);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
}

int getdistance() 
{
  int duration;
  int distance;
  digitalWrite(trigpin,HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration=pulseIn(echopin,HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}
