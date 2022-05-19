#include <CuteBuzzerSounds.h>


//Define the Button States
int buttonStateRot = 0;
int buttonStateGelb = 0;
int buttonStateBlau = 0;
int buttonStateGruen = 0;
int resetButtonState = 0;

//Prestate currently not used
int prestate = 0;

//Define the Buzzer Pin and the Soundfrequency
int buzzer = 10;
int buzzersound = 300;

//Define the pin for dis- and enabling the Buzzers
int buttonRot = 2;
int buttonGelb = 3;
int buttonBlau = 4;
int buttonGruen = 5;

//Define the pins for checking if the Buzzers are pressed
int pinRot = 6;
int pinGelb = 7;
int pinBlau = 8;
int pinGruen = 9;

//Define the Pins for turning on and off the corresponding leds to the Buzzers 
int ledRot = A5;
int ledGelb = A4;
int ledBlau = A3;
int ledGruen = A2;

//Define the Pins for turning on and off the leds for the right and wrong buttons
int ledFalsch = A1;
int ledRichtig = A0;

//define the Pin for the Reset Button
int resetPin = 11;

//Define the Pins for the right and wrong buttons
int pinFalsch = 12;
int pinRichtig = 13;

int gruenPressed = 0;
int blauPressed = 0;
int gelbPressed = 0;
int rotPressed = 0;

int gruenWrong = 0;
int blauWrong = 0;
int gelbWrong = 0;
int rotWrong = 0;

void setup() {
  // put your setup code here, to run once:
  
  //Setup of the PinModes for the LEDs
  pinMode(ledRot, OUTPUT);
  pinMode(ledGelb, OUTPUT);
  pinMode(ledBlau, OUTPUT);
  pinMode(ledGruen, OUTPUT);
  
  //Setup of the PinModes for the Buzzers
  pinMode(buttonRot, OUTPUT);
  pinMode(buttonGelb, OUTPUT);
  pinMode(buttonBlau, OUTPUT);
  pinMode(buttonGruen, OUTPUT);
  
  //Setup of the PinModes for the check if a button is pressed
  pinMode(pinRot, INPUT);
  pinMode(pinGelb, INPUT);
  pinMode(pinBlau, INPUT);
  pinMode(pinGruen, INPUT);
  
  //Setup of the PinModes for the buzzer(speaker)
  pinMode(buzzer, OUTPUT);
  
  //Setup of the PinModes for the reset Button
  pinMode(resetPin, INPUT);
  
  // 
  pinMode(pinRichtig, INPUT);
  pinMode(pinFalsch, INPUT);
  
  pinMode(ledRichtig, OUTPUT);
  pinMode(ledFalsch, OUTPUT);

  Serial.begin(9600);
  digitalWrite(ledRichtig, LOW);
  digitalWrite(ledFalsch, LOW);
  cute.init(buzzer);

}

void loop() {
  // put your main code here, to run repeatedly:


  buttonStateRot = digitalRead(pinRot);
  buttonStateGelb = digitalRead(pinGelb);
  buttonStateBlau = digitalRead(pinBlau);
  buttonStateGruen = digitalRead(pinGruen);
  resetButtonState = digitalRead(resetPin);
  
  if(resetButtonState == HIGH) {
    delay(100);
    digitalWrite(buttonRot, HIGH);
    digitalWrite(buttonGelb, HIGH);
    digitalWrite(buttonBlau, HIGH);
    digitalWrite(buttonGruen, HIGH);
    digitalWrite(ledRot, HIGH);
    digitalWrite(ledGelb, HIGH);
    digitalWrite(ledBlau, HIGH);
    digitalWrite(ledGruen, HIGH);
    cute.play(S_CONNECTION);
    delay(150);
    digitalWrite(ledRot, LOW);
    digitalWrite(ledGelb, LOW);
    digitalWrite(ledBlau, LOW);
    digitalWrite(ledGruen, LOW);
    gruenPressed = 0;
    blauPressed = 0;
    gelbPressed = 0;
    rotPressed = 0;
    gruenWrong = 0;
    blauWrong = 0;
    gelbWrong = 0;
    rotWrong = 0;
  }


  if(buttonStateRot == HIGH && rotPressed == 0) {
    digitalWrite(buttonGelb, LOW);
    digitalWrite(buttonBlau, LOW);
    digitalWrite(buttonGruen, LOW);
    digitalWrite(ledRichtig, LOW);
    digitalWrite(ledFalsch, LOW);
    digitalWrite(ledRot, HIGH);
    tone(buzzer, buzzersound, 500);
    rotPressed = 1;
  }

  
   if(buttonStateGelb == HIGH) {
    digitalWrite(buttonRot, LOW);
    digitalWrite(buttonBlau, LOW);
    digitalWrite(buttonGruen, LOW);
    digitalWrite(ledRichtig, LOW);
    digitalWrite(ledFalsch, LOW);
    digitalWrite(ledGelb, HIGH);
    tone(buzzer, buzzersound, 500);
    gelbPressed = 1;
  }

  
  if(buttonStateBlau == HIGH) {
    digitalWrite(buttonGelb, LOW);
    digitalWrite(buttonRot, LOW);
    digitalWrite(buttonGruen, LOW);
    digitalWrite(ledRichtig, LOW);
    digitalWrite(ledFalsch, LOW);
    digitalWrite(ledBlau, HIGH);
    tone(buzzer, buzzersound, 500);
    blauPressed = 1;
  }

  
  if(buttonStateGruen == HIGH) {
    digitalWrite(buttonGelb, LOW);
    digitalWrite(buttonBlau, LOW);
    digitalWrite(buttonRot, LOW);
    digitalWrite(ledRichtig, LOW);
    digitalWrite(ledFalsch, LOW);
    digitalWrite(ledGruen, HIGH);
    tone(buzzer, buzzersound, 500);
    gruenPressed = 1;
  }

  if(digitalRead(pinRichtig) == HIGH) {
    digitalWrite(ledRichtig, HIGH);
    cute.play(S_BUTTON_PUSHED);
    delay(1000);
    digitalWrite(ledRichtig, LOW);
    digitalWrite(buttonGelb, HIGH);
    digitalWrite(buttonBlau, HIGH);
    digitalWrite(buttonRot, HIGH);
    digitalWrite(buttonGruen, HIGH);
    digitalWrite(ledGruen, LOW);
    digitalWrite(ledBlau, LOW);
    digitalWrite(ledGelb, LOW);
    digitalWrite(ledRot, LOW);
    gruenPressed = 0;
    blauPressed = 0;
    gelbPressed = 0;
    rotPressed = 0;
    gruenWrong = 0;
    blauWrong = 0;
    gelbWrong = 0;
    rotWrong = 0;
  }


  if(digitalRead(pinFalsch) == HIGH && rotPressed == 1) {
    digitalWrite(ledFalsch, HIGH);
    digitalWrite(buttonRot, LOW);
    cute.play(S_OHOOH);
    delay(1000);
    digitalWrite(ledFalsch, LOW);
    digitalWrite(ledRot, LOW);
    digitalWrite(buttonGelb, HIGH);
    digitalWrite(buttonBlau, HIGH);
    digitalWrite(buttonGruen, HIGH);
    rotPressed = 0;
    rotWrong = 1;
  }


    if(digitalRead(pinFalsch) == HIGH && gelbPressed == 1) {
    digitalWrite(ledFalsch, HIGH);
    digitalWrite(buttonGelb, LOW);
    cute.play(S_OHOOH);
    delay(1000);
    digitalWrite(ledFalsch, LOW);
    digitalWrite(ledGelb, LOW);
    digitalWrite(buttonRot, HIGH);
    digitalWrite(buttonBlau, HIGH);
    digitalWrite(buttonGruen, HIGH);
    gelbPressed = 0;
    gelbWrong = 1;
  }

  
  if(digitalRead(pinFalsch) == HIGH && blauPressed == 1) {
    digitalWrite(ledFalsch, HIGH);
    digitalWrite(buttonBlau, LOW);
    cute.play(S_OHOOH);
    delay(1000);
    digitalWrite(ledFalsch, LOW);
    digitalWrite(ledBlau, LOW);
    digitalWrite(buttonGelb, HIGH);
    digitalWrite(buttonRot, HIGH);
    digitalWrite(buttonGruen, HIGH);
    blauPressed = 0;
    blauWrong = 1;
  }

  
  if(digitalRead(pinFalsch) == HIGH && gruenPressed == 1) {
    digitalWrite(ledFalsch, HIGH);
    digitalWrite(buttonGruen, LOW);
    cute.play(S_OHOOH);
    delay(1000);
    digitalWrite(ledFalsch, LOW);
    digitalWrite(ledGruen, LOW);
    digitalWrite(buttonGelb, HIGH);
    digitalWrite(buttonBlau, HIGH);
    digitalWrite(buttonRot, HIGH);
    gruenPressed = 0;
    gruenWrong = 1;
  }


  if(rotWrong == 1) {
    digitalWrite(buttonRot, LOW);
  }

  if(gelbWrong == 1) {
    digitalWrite(buttonGelb, LOW);
  }

  if(blauWrong == 1) {
    digitalWrite(buttonBlau, LOW);
  }

  if(gruenWrong == 1) {
    digitalWrite(buttonGruen, LOW);
  }


  if(rotWrong == 1 && gelbWrong == 1 && blauWrong == 1 && gruenWrong == 1) {
    delay(100);
    cute.play(S_FART3);
    digitalWrite(buttonRot, HIGH);
    digitalWrite(ledGelb, HIGH);
    digitalWrite(ledBlau, HIGH);
    digitalWrite(ledGruen, HIGH);
    delay(150);
    digitalWrite(ledRot, LOW);
    digitalWrite(ledGelb, LOW);
    digitalWrite(ledBlau, LOW);
    digitalWrite(ledGruen, LOW);
    delay(150);
    digitalWrite(buttonRot, HIGH);
    digitalWrite(ledGelb, HIGH);
    digitalWrite(ledBlau, HIGH);
    digitalWrite(ledGruen, HIGH);
    delay(150);
    digitalWrite(ledRot, LOW);
    digitalWrite(ledGelb, LOW);
    digitalWrite(ledBlau, LOW);
    digitalWrite(ledGruen, LOW);
    gruenWrong = 0;
    blauWrong = 0;
    gelbWrong = 0;
    rotWrong = 0;
  }

}
