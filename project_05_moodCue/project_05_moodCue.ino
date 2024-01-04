#include <Servo.h>

// create Servo object
Servo myServo;

int const potPin = A0;
int const servoPin = 9;
int potVal;
int angle;

void setup(){
    myServo.attach(servoPin);
    Serial.begin(9600);
}

void loop(){
    // reads a value ranging from 0-1023
    potVal = analogRead(potPin);
    Serial.print("potVal: ");
    Serial.print(potVal);
    
    // map value to an angle
    angle = map(potVal, 0, 1023, 0, 179);
    Serial.print(", angle: ");
    Serial.print(angle);

    // make changes to the servo motor
    myServo.write(angle);
    delay(15);
}