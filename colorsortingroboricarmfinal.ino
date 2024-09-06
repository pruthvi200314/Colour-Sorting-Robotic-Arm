#include <Servo.h>

#define PIN_S0 2
#define PIN_S1 3
#define PIN_S2 4
#define PIN_S3 5
#define PIN_OUT 6

Servo baseServo;
Servo shoulderServo;
Servo armServo;
Servo wristServo;
Servo wristRServo;
Servo clawServo;


void setup() {

  Serial.begin(9600);
   pinMode(PIN_S0, OUTPUT);
  pinMode(PIN_S1, OUTPUT);
  pinMode(PIN_S2, OUTPUT);
  pinMode(PIN_S3, OUTPUT);
  pinMode(PIN_OUT, INPUT);
   // set the frequency scaling to 20% (S==1; S1=0)
  digitalWrite(PIN_S0,HIGH);
  digitalWrite(PIN_S1,LOW);
  
baseServo.attach(8);
shoulderServo.attach(9);
armServo.attach(10);
wristRServo.attach(11);
wristServo.attach(12);
clawServo.attach(13);

baseServo.write(20);
shoulderServo.write(100);
armServo.write(35);
wristRServo.write(90);
  wristServo.write(30);
  clawServo.write(45);

}
void loop(){
  // select photodiodes with red filters 
  digitalWrite(PIN_S2, LOW);
  digitalWrite(PIN_S3, LOW);
  int red = pulseIn(PIN_OUT, LOW); // read red output frequency
  // print out red frequency value via serial 
  Serial.print("Red = ");
  Serial.print(red);
  Serial.print("; ");
  delay(1000); // short delay between readings 
  
  // select photodiodes with green filters 
  digitalWrite(PIN_S2, HIGH);
  digitalWrite(PIN_S3, HIGH);
  int green = pulseIn(PIN_OUT, LOW); // read green output frequency
  // print out green frequency value via serial 
  Serial.print("Green = ");
  Serial.print(green);
  Serial.print("; ");
  delay(1000); // short delay between readings 
  
  // select photodiodes with blue filters 
  digitalWrite(PIN_S2, LOW);
  digitalWrite(PIN_S3, HIGH);
  int blue = pulseIn(PIN_OUT, LOW);  // read blue output frequency
  // print out blue frequency value via serial 
  Serial.print("Blue = ");
  Serial.println(blue);
  delay(1000); // short delay between readings 
  
  pickObject();
  delay(1000);
  if(red<green && red<blue){
  placeObjectr();
  delay(1000);
  }
  else if(green<red && green<blue){
  placeObjectg();
  delay(1000);
  }
  else if(blue<green && blue<red ){
  placeObjectb();
  delay(1000);
  }
  else{
    pickObject();
    delay(1000);
  }
  delay(1000);  
}

void pickObject(){
  baseServo.write(20);
shoulderServo.write(100);
armServo.write(35);
wristRServo.write(90);
  wristServo.write(30);
  delay(3000);
  clawServo.write(0);
  delay(1000);
}

void placeObjectr(){
   baseServo.write(120);
shoulderServo.write(100);
armServo.write(45);
wristRServo.write(90);
  wristServo.write(30);
  delay(3000);
  clawServo.write(45);
  delay(1000);
}
void placeObjectg(){
   baseServo.write(145);
shoulderServo.write(100);
armServo.write(35);
wristRServo.write(90);
  wristServo.write(30);
  delay(3000);
  clawServo.write(45);
  delay(1000);
}
void placeObjectb(){
   baseServo.write(170);
shoulderServo.write(100);
armServo.write(35);
wristRServo.write(90);
  wristServo.write(30);
  delay(3000);
  clawServo.write(45);
  delay(1000);
}