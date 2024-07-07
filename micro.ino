#include <Servo.h>

#define LEFT_IR1_PIN 6
#define LEFT_IR2_PIN 3
#define RIGHT_IR1_PIN 4
#define RIGHT_IR2_PIN 5
#define SERVO1_PIN 7
#define SERVO2_PIN 8
#define BUZZER_PIN 2

Servo servo1;
Servo servo2;
bool leftDetected = false;
bool rightDetected = false;
bool ok=true;

void setup() {
  pinMode(LEFT_IR1_PIN, INPUT);
  pinMode(LEFT_IR2_PIN, INPUT);
  pinMode(RIGHT_IR1_PIN, INPUT);
  pinMode(RIGHT_IR2_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
}


void loop() {

  if(ok){
    servo1.write(0);
    servo2.write(0);
    ok=false;
  }

  if (!digitalRead(LEFT_IR1_PIN) && !digitalRead(LEFT_IR2_PIN) && !leftDetected && !rightDetected) {
    servo1.write(90);
    servo2.write(90); // Assuming 90 degrees is the down position for servo1
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);  
    leftDetected=true;
  }
  
  if (!digitalRead(RIGHT_IR1_PIN) && !digitalRead(RIGHT_IR2_PIN) && !leftDetected && !rightDetected) {
    servo1.write(90);
    servo2.write(90); // Assuming 0 degrees is the up position for servo2
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
    delay(1000); 
    rightDetected=true;
  }

  if (!digitalRead(LEFT_IR1_PIN) && !digitalRead(LEFT_IR2_PIN) && rightDetected) {
    servo1.write(0);
    servo2.write(0); // Assuming 90 degrees is the down position for servo1
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);  
    //leftDetected=true;
    rightDetected=false;
  }

  if (!digitalRead(RIGHT_IR1_PIN) && !digitalRead(RIGHT_IR2_PIN) && leftDetected) {
    servo1.write(0);
    servo2.write(0); // Assuming 90 degrees is the down position for servo1
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);  
    leftDetected=false;
    //rightDetected=true;
  }
}
