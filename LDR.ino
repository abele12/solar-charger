int LDR1 = A0;          //connect The LDR1 on Pin A0
int led = 13;
void setup() 
{ 
  Serial.begin(9600);  
  pinMode(LDR1, INPUT);   
  pinMode(led, OUTPUT);
  delay(2000); 
  digitalWrite(led, HIGH);
  delay(1000);   
  digitalWrite(led, LOW);
  delay(1000);   
  digitalWrite(led, HIGH);
  delay(1000);   
  digitalWrite(led, LOW);
  delay(1000);          
}  
 
void loop() 
{ 
  int R1 = analogRead(LDR1); // read  LDR 1
  Serial.print("R1 = ");
   Serial.println(R1); 
  delay(1000);
  if (R1 > 431) { 
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delay(1000);
  }
  else {
  digitalWrite(led, LOW);
  delay(1000);
  }
  
}
 
