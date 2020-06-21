int LDR1 = A0;          //η φωτοαντίσταση συνδέεται στο Α0 pin
int led = 13;           //το led συνδέεται στο pin 13
void setup() 
{ 
  Serial.begin(9600);  
  pinMode(LDR1, INPUT);   
  pinMode(led, OUTPUT);
  delay(2000); 
  digitalWrite(led, HIGH);    //στην αρχή το led αναβοσβήνει δύο φορές με χρονική απόσταση 1 sec
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
  int R1 = analogRead(LDR1); // διαβάζει την τομή από την φωτοαντίσταση
  Serial.print("R1 = ");
   Serial.println(R1);    //η τιμή που δίνει η φωτοαντίσταση τυπώνεται στην οθόνη
  delay(1000);
  if (R1 > 431) {   //αν η τιμή της φωτοαντίστασης είναι μεγαλύτερη από 431 το led ανάβει
  digitalWrite(led, HIGH);
  delay(1000);
  }
  else {
  digitalWrite(led, LOW);        // διαφορετικά σβήνει
  delay(1000);
  }
  
}
 
