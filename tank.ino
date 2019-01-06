#include <Servo.h>

// Arduino pin numbers
const int SW_pin = 11; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int ledPin1 = 2;
const int ledPin2 = 6;
const int ledPin3 = 7;
const int ledPin4 = 5;



Servo servo;

void setup(){
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);

  
  servo.attach(10);
  servo.write(0);
  delay(2000);

  pinMode (ledPin1, OUTPUT) ;
  pinMode (ledPin2, OUTPUT) ;
  pinMode (ledPin3, OUTPUT) ;
  pinMode (ledPin4, OUTPUT) ;
  
}

void loop(){
  /*
  servo.write(180);
  delay(1000);
  servo.write(0);
  delay(1000);*/

if(analogRead(Y_pin) < 15){
  //turn left
  servo.write(80);
}

if(analogRead(Y_pin) > 1000){
  //turn right
  servo.write(0);


}
if(digitalRead(SW_pin) == 0){
  servo.write(80);
  //delay(1000);

  digitalWrite(ledPin1, HIGH) ;
  Serial.println("LED ON ++++");

  delay(100);
  
  digitalWrite(ledPin2, HIGH) ;
  Serial.println("LED ON ++++");

  delay(100);

  digitalWrite(ledPin3, HIGH) ;
  Serial.println("LED ON ++++");

  delay(100);

  digitalWrite(ledPin4, HIGH) ;
  Serial.println("LED ON ++++"); 
      
} else {
  delay(150);
  

  digitalWrite(ledPin1, LOW);
  Serial.println("LED OFF +++");

  digitalWrite(ledPin2, LOW);
  Serial.println("LED OFF +++");

  digitalWrite(ledPin3, LOW);
  Serial.println("LED OFF +++");

  digitalWrite(ledPin4, LOW);
  Serial.println("LED OFF +++");
}

  /*Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(500);*/
}
