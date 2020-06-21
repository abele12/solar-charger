#include <Servo.h>      
Servo sg90;             
int initial_position = 90;   //
int LDR1 = A0;          // Η φωτοαντίσταση LDR1 συνδέεται στο pin A0
int LDR2 = A1;          // Η φωτοαντίσταση LDR2 συνδέεται στο pin A1
int error = 5;          // ορίζεται η ελάχιστη διαφορά των τιμών των δύο φωτοαντιστάσεων
int servopin=9;         // ο σερβοκινητήρας συνδέεται στο pin 9
void setup() 
{ 

  sg90.attach(servopin);  //ο σερβοκινητήρας συνδέεται στο pin 9

  pinMode(LDR1, INPUT);   
  pinMode(LDR2, INPUT);
  sg90.write(initial_position);   ///γυρίζει στις 90 μοίρες
    delay(2000);           
}  
 
void loop() 
{ 
  int R1 = analogRead(LDR1); //η τιμή που δίνει η φωτοαντίσταση LDR1 αποθηκεύεται στη μεταβλητή R1
  int R2 = analogRead(LDR2); //η τιμή που δίνει η φωτοαντίσταση LDR2 αποθηκεύεται στη μεταβλητή R2
  int diff= abs(R1 - R2);   //η τιμή που δίνει η φωτοαντίσταση LDR1 αποθηκεύεται στη μεταβλητή R1

  
  if (diff > error) {    //αν η διαφορά των τιμών των φωτοαντίστάσεων είναι μεγαλύτερη από 5
       if(R1 > R2)      //αν η τιμή της πρώτης φωτοαντίστασης είναι μεγαλύτερη  
    {
      initial_position = initial_position-10;    //ο σερβοκινητήρας γυρίζει 10 μοίρες αριστερά
     
      if (initial_position < 0)  //αν η τιμη της αρχικής θέσης είναι αρνητική, τότε παίρνει την τιμή 0
      {
       initial_position = 0;
      }
      }
    if(R1 < R2) 
    {
      initial_position = 10+initial_position; //ο σερβοκινητήρας γυρίζει 10 μοίρες δεξιά
     
       if (initial_position >140)  //αν η τιμη της αρχικής θέσης είναι μεγαλύτερη των 140, τότε παίρνει την τιμή 140
      {
       initial_position = 140;
      }
      }
   sg90.write(initial_position);
   delay(1000);
    }
}
