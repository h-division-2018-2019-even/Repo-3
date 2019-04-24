void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600)  
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
delay(10000);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
}
