#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h> 
const uint64_t pipe = 0xE8E8F0F0E1LL;
Servo myServo,myServo1;
RF24 radio(7, 8);
int datos[5];
bool directionL;
bool directionR;

byte valueL;
byte valueR; 

int mLeft;
int mRight;

boolean ledOn = false;
boolean lastBut = HIGH;
long time = 0;
long debounce = 300;
int pos;
int fspeed; 
int bspeed; 
int steer;

const int in1 = 2; 
const int in2 = 9; 
const int in3 = 4; 
const int in4 = 5; 
const int ena = 3; // PWM pin to change speed
const int enb = 6;
byte IsConnect;
void setup()
{
//  myServo.attach(9);     // Don't use 0 and 1 pins
//  myServo1.attach(10);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT); 
  radio.begin();
  Serial.begin(9600);
  radio.openReadingPipe(1,pipe);
  radio.startListening();
//  radio.setDataRate(RF24_250KBPS); // Recommended use of the capacitor in case of activating this function
  radio.setRetries(15, 15);
}

int MotoL, MotoR;
int ValStickX, ValStickY , valS, valS1;

void loop() {
  uint8_t numero_canal;
  if ( radio.available())
  {
    radio.read(datos, sizeof(datos));
    IsConnect = HIGH;
  }
  else{
    IsConnect = LOW;
  }
    int val_x = datos[0];
    int val_y = datos[1];
  //  int valS1 = datos[2];
  //  int valS2 = datos[3];
    valS = map(valS1,0,1023,0,255);
    valS1 = map(valS2,0,1023,0,255);
    ValStickX = map(val_x, 1023, 0, 252, -252);
    ValStickY = map(val_y, 1023, 0, 252, -252);
    //Serial.println(ValStickX);
//myServo.write(valS);
//myServo1.write(valS1);

   if (abs(ValStickX) < 20) {
      ValStickX = 0;
    }
    if (abs(ValStickY) < 20) {
      ValStickY = 0;
    }

    MotoL = ValStickY - (ValStickX );
    MotoR = ValStickY + (ValStickX );
   
    if (IsConnect == LOW){MotoL = 0;}
    if (IsConnect == LOW){MotoR = 0;}
    
    if (MotoL > 255) {
      MotoL = 255;
    }
    if (MotoR > 255) {
      MotoR = 255;
    }
    if (MotoL < -255) {
      MotoL = -255;
    }
    if (MotoR < -255) {
      MotoR = -255;
    }
Serial.println(mLeft);
  if (MotoL > 0) 
  {
    valueL = MotoL;
    directionL = 0;
    
  }
  else if (MotoL < 0) 
  {
    valueL = abs(MotoL);
    directionL = 1;
    
  }
  else 
  {
    directionL = 0;
    valueL = 0;
  }

  if (MotoR > 0) {
    valueR = MotoR;
    directionR = 0;
    
  }
  else if (MotoR < 0) {
    valueR = abs(MotoR);
    directionR = 1;
   
  }
  else {
    directionR = 0;
    valueR = 0;
  }
  

  digitalWrite(in1, directionR);
  digitalWrite(in2, !directionR); 
  digitalWrite(in3, directionL);
  digitalWrite(in4, !directionL);
  analogWrite(ena, valueR);
  analogWrite(enb, valueL);
  
}
