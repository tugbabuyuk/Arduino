#include "HX711.h"

//-140650.00 ## Kalibrasyon
//8350350    ## Zero factor

HX711 scale(2, 3);
int inputPin1 = A0;
int outputPin1 = 8;
int outputPin2 = 9;

float val;

double threshold=0.10;
double AZ   =0.300;
double ORTA  =0.600;
double FAZLA =1.00;

void setup() {
  Serial.begin(9600);
  scale.set_scale();
  scale.tare();
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(inputPin1, INPUT);
}


void loop() {
  scale.set_scale(-140650.00);
  val = scale.get_units(),20;
  val = -val;
  //Serial.println(val);
  
  if(val <= threshold || val < 0 ){
    digitalWrite(outputPin1,LOW);
    digitalWrite(outputPin2,LOW);
     Serial.println("Yok.");
          Serial.println(val);
  }
  else if(val <= AZ){
    digitalWrite(outputPin1,LOW);
    digitalWrite(outputPin2,HIGH);  
    Serial.println("Az.");
         Serial.println(val);
    
  }
  else if(val <= ORTA){
    digitalWrite(outputPin1,HIGH);
    digitalWrite(outputPin2,LOW);
    Serial.println("Orta.");
         Serial.println(val);
  }
  else if(val <= FAZLA  || val > FAZLA){
    digitalWrite(outputPin1,HIGH);
    digitalWrite(outputPin2,HIGH);
    Serial.println("Fazla.");
         Serial.println(val);
  }
}
