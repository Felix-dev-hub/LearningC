#include <Arduino.h>

#define RED_LIGHT 12
#define YELLOW_LIGHT 13
#define GREEN_LIGHT 14
#define BUTTON 4
bool isRed = true;

void switchLights();

void setup()
{
  pinMode(RED_LIGHT, OUTPUT);
  digitalWrite(RED_LIGHT, HIGH);
  pinMode(YELLOW_LIGHT, OUTPUT);
  pinMode(GREEN_LIGHT, OUTPUT);
}

void loop()
{
  if (digitalRead(BUTTON) == LOW)
  {
    switchLights();
  }
}

void switchLights()
{
  if (isRed)
  {
    delay(200);
    digitalWrite(YELLOW_LIGHT, HIGH);
    delay(1000);
    digitalWrite(RED_LIGHT, LOW);
    digitalWrite(YELLOW_LIGHT, LOW);
    digitalWrite(GREEN_LIGHT, HIGH);
    isRed = false;
  }
  else
  {
    delay(200);
    digitalWrite(GREEN_LIGHT, LOW);
    digitalWrite(YELLOW_LIGHT, HIGH);
    delay(1000);
    digitalWrite(YELLOW_LIGHT, LOW);
    digitalWrite(RED_LIGHT, HIGH);
    isRed = true;
  }
}