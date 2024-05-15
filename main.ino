#include <Servo.h>
#include <NewPing.h>

#define HC_TRIG 8
#define HC_ECHO 9

Servo myServo;

const int servoPin = 3;
const int buttonPin = 2;
const int BoomPin = 6;

NewPing sonar(HC_TRIG, HC_ECHO, 200);

void setup() {
  myServo.attach(servoPin);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(BoomPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  for (int i = 0; i <= 180; i++) {

    myServo.write(i);
    delay(20);

    float Distance1 = sonar.ping_cm();
    float distance = 0;

    delay(50);
    if (Distance1 == 0.00) {
      distance = 900;
    }
    else {
      distance = Distance1;
    }
    Serial.println(distance);
    if (distance < 50) {
      myServo.write(i+15);
      delay(5000);
      float Distance1 = sonar.ping_cm();
      delay(50);
      if (Distance1 == 0.00) {
        distance = 900;
      }
      else {
        distance = Distance1;
      }
      Serial.println(distance);
      if (distance < 50) {
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(BoomPin, HIGH);
        while (digitalRead(buttonPin) == HIGH) {
          delay(10);
        }
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(BoomPin, LOW);
      }
    }
  }

  for (int i = 180; i >= 0; i--) {
    myServo.write(i);
    delay(20);
    float Distance1 = sonar.ping_cm();
    float distance = 0;
    delay(50);
    if (Distance1 == 0.00) {
      distance = 900;
    }
    else {
      distance = Distance1;
    }
    Serial.println(distance);
    if (distance < 50) {
      myServo.write(i-15);
      delay(5000);
      float Distance1 = sonar.ping_cm();
      delay(50);
      if (Distance1 == 0.00) {
        distance = 900;
      }
      else {
        distance = Distance1;
      }
      Serial.println(distance);
      if (distance < 50) {
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(BoomPin, HIGH);
        while (digitalRead(buttonPin) == HIGH) {
          delay(10);
        }
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(BoomPin, LOW);
      }
    }
  }
}
