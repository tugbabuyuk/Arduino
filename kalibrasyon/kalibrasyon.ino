#include "HX711.h"

HX711 cell(3, 2);
int inputPin1 = A0;
int outputPin1 = 8;
int outputPin2 = 9;

int threshold=500;
int AZ=3000;
int ORTA=5000;
int FAZLA=7000;

//Ağırlık sensörü 80Hz

void setup() {
  Serial.begin(9600);
   pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(inputPin1, INPUT);
}

long val = 0;
float count = 0;

void loop() {
  //count = count + 1;
  
  // Use only one of these
  //val = ((count-1)/count) * val    +  (1/count) * cell.read(); // take long term average
  //val = 0.5 * val    +   0.5 * cell.read(); // take recent average
  val = cell.read(); // most recent reading

  
  Serial.println( val );
}
