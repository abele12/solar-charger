 
//Το κύκλωμα αποτελείται από δύο φωτοαντιστάσεις, ένα led κίτρινο και ένα led πράσινο. Όταν η μια φωτοαντίσταση δίνει μεγαλύτερη τιμή αναβοσβήνει το ένα led, διαφορετικά το άλλο led
 
int LDR1 = A0;          // Η φωτοαντίσταση LDR1 συνδέεται στο pin A0
int LDR2 = A1;          // Η φωτοαντίσταση LDR2 συνδέεται στο pin A1
int led_green = 13;     // το πράσινο led συνδέεται στο pin 13
int led_yellow = 8;     // το κίτρινο led συνδέεται στο pin 8

int error = 5;
 
void setup() 
{ 
 pinMode(LDR1, INPUT);
 pinMode(LDR2, INPUT);
 Serial.begin(9600);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  digitalWrite(led_yellow, HIGH);  //ανάβει το κίτρινο led
  digitalWrite(led_green, HIGH);   //ανάβει το πράσινο led
  delay(500);                      // για 0,5 sec
  digitalWrite(led_yellow, LOW);   //σβήνει το κίτρινο led
  digitalWrite(led_green, LOW);    //σβήνει το κίτρινο led
  delay(500);                      // για 0,5 sec
}  
 
void loop() 
{ 
  int R1 = analogRead(LDR1);   //η τιμή που δίνει η φωτοαντίσταση LDR1 αποθηκεύεται στη μεταβλητή R1
  int R2 = analogRead(LDR2);   //η τιμή που δίνει η φωτοαντίσταση LDR2 αποθηκεύεται στη μεταβλητή R2

   digitalWrite(led_yellow, LOW);  //το κίτρινο led δεν ανάβει
   digitalWrite(led_green, LOW);  //το πράσινο led δεν ανάβει

   int diff=abs(R1-R2);   //υπολογίζεται η απόλυτη τιμή της διαφοράς των τιμών των δύο φωτοαντιστάσεων


   Serial.print("R1=");    
   Serial.println(R1);     //τυπώνεται στην οθόνη η τιμή που δίνει η πρώτη φωτοαντίσταση
   Serial.print("R2=");
   Serial.println(R2);     //τυπώνεται στην οθόνη η τιμή που δίνει η δεύτερη φωτοαντίσταση
   delay(2000);
   if((diff <= error)     //αν η διαφορά των τιμών των φωτοαντίστάσεων είναι μικρότερη από 5
   {
    Serial.print("diff=");
    Serial.println(diff);     //τυπώνεται η διαφορά στην οθόνη και δεν συμβαίνει κάτι άλλο

   }
    else       //αν η διαφορά των τιμών των φωτοαντίστάσεων είναι μεγαλύτερη από 5
   {
    if(R1 > R2)     //αν η τιμή της πρώτης φωτοαντίστασης είναι μεγαλύτερη
    {
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, HIGH);  //ανάβει το πράσινο led
      delay(500);
     }
    digitalWrite(led_yellow, LOW);
   digitalWrite(led_green, LOW);   
    if(R1 < R2)                     //αν η τιμή της δεύτερης φωτοαντίστασης είναι μεγαλύτερη
    {
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_green, HIGH);    //ανάβει το κίτρινο led
      delay(500);
      }
  }
}
