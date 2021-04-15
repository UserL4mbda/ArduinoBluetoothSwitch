#include "Arduino.h"

#define OUTPIN 12
#define SWITCH 11
#define LIGHTBULBE 10

int status       = LOW;
int oldStatus    = LOW;
int oldSwitchPin = LOW;
int switchPin    = LOW;
unsigned long lastTime    = 0;
unsigned long currentTime = 0;
unsigned long latence     = 200;

void setup(){
  pinMode(OUTPIN, OUTPUT);
  pinMode(SWITCH, INPUT);
  pinMode(LIGHTBULBE, OUTPUT);

  for(int i = 0; i<5 ; i++){
    digitalWrite(OUTPIN, HIGH);
    delay(1000);
    digitalWrite(OUTPIN, LOW);
    delay(1000);
  }
}

void loop(){
  if(digitalRead(SWITCH) == LOW){
    digitalWrite(OUTPIN, HIGH);
    switchPin = HIGH;
  }else{
    digitalWrite(OUTPIN, LOW);
    switchPin = LOW;
  }

  currentTime = millis();
  if(currentTime - lastTime < latence){
    return;
  }
  lastTime = currentTime;
  if((switchPin != oldSwitchPin) && (switchPin == LOW)){
    status = (status == LOW)?HIGH:LOW;
    digitalWrite(LIGHTBULBE, status);
  }
  oldSwitchPin = switchPin;
}
