  #include <CuteBuzzerSounds.h>

int buttonStateRot = 0;
int buttonStateGelb = 0;
int buttonStateBlau = 0;
int buttonStateGruen = 0;
int resetButtonState = 0;

int prestate = 0;
int buzzer = 10;
int buzzersound = 300;

int buttonRot = 2;
int buttonGelb = 3;
int buttonBlau = 4;
int buttonGruen = 5;

int pinRot = 6;
int pinGelb = 7;
int pinBlau = 8;
int pinGruen = 9;

int ledRot = A5;
int ledGelb = A4;
int ledBlau = A3;
int ledGruen = A2;

int ledFalsch = A1;
int ledRichtig = A0;

int resetPin = 11;

int pinFalsch = 12;
int pinRichtig = 13;

int i = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledRot, OUTPUT);
  pinMode(ledGelb, OUTPUT);
  pinMode(ledBlau, OUTPUT);
  pinMode(ledGruen, OUTPUT);
  
  pinMode(buttonRot, OUTPUT);
  pinMode(buttonGelb, OUTPUT);
  pinMode(buttonBlau, OUTPUT);
  pinMode(buttonGruen, OUTPUT);
  
  pinMode(pinRot, INPUT);
  pinMode(pinGelb, INPUT);
  pinMode(pinBlau, INPUT);
  pinMode(pinGruen, INPUT);
  
  pinMode(buzzer, OUTPUT);
  
  pinMode(resetPin, INPUT);

  pinMode(pinRichtig, INPUT),

  pinMode(ledRichtig, OUTPUT);
  
  Serial.begin(9600);

  digitalWrite(ledRichtig, LOW);
  
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
    delay(50);
    digitalWrite(ledRot, LOW);
    digitalWrite(ledGelb, LOW);
    digitalWrite(ledBlau, LOW);
    digitalWrite(ledGruen, LOW);
  }
  


  if(buttonStateRot == HIGH) {
    digitalWrite(buttonGelb, LOW);
    digitalWrite(buttonBlau, LOW);
    digitalWrite(buttonGruen, LOW);
    digitalWrite(ledRot, HIGH);
    tone(buzzer, buzzersound, 500);
  }

  
   if(buttonStateGelb == HIGH) {
    digitalWrite(buttonRot, LOW);
    digitalWrite(buttonBlau, LOW);
    digitalWrite(buttonGruen, LOW);
    digitalWrite(ledGelb, HIGH);
    tone(buzzer, buzzersound, 500);
  }

  
  if(buttonStateBlau == HIGH) {
    digitalWrite(buttonGelb, LOW);
    digitalWrite(buttonRot, LOW);
    digitalWrite(buttonGruen, LOW);
    digitalWrite(ledBlau, HIGH);
    tone(buzzer, buzzersound, 500);
  }

  
  if(buttonStateGruen == HIGH) {
    digitalWrite(buttonGelb, LOW);
    digitalWrite(buttonBlau, LOW);
    digitalWrite(buttonRot, LOW);
    digitalWrite(ledGruen, HIGH);
    tone(buzzer, buzzersound, 500);
  }

  if(digitalRead(pinRichtig) == HIGH) {
    digitalWrite(ledRichtig, HIGH);
    cute.play(S_BUTTON_PUSHED);
    delay(1000);
    digitalWrite(ledRichtig, LOW);
    
  }

  if(digitalRead(pinFalsch) == HIGH) {
    digitalWrite(ledFalsch, HIGH);
    cute.play(S_OHOOH);
    delay(1000);
    digitalWrite(ledFalsch, LOW);
  }
  
}
