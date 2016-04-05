// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <Servo.h>

Servo servoMain; // Define our Servo
Servo esc;
int throttlePin = 1;

#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define TRIGGER_PIN_1  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_1    12  // Arduino pin tied to echo pin on the ultrasonic sensor.

#define TRIGGER_PIN_2  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_2    10  // Arduino pin tied to echo pin on the ultrasonic sensor.

#define TRIGGER_PIN_3  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_3    8  // Arduino pin tied to echo pin on the ultrasonic sensor.

#define TRIGGER_PIN_4  7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_4    6  // Arduino pin tied to echo pin on the ultrasonic sensor.

#define TRIGGER_PIN_5  5  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_5    4  // Arduino pin tied to echo pin on the ultrasonic sensor.



NewPing sonar_1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_4(TRIGGER_PIN_4, ECHO_PIN_4, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_5(TRIGGER_PIN_5, ECHO_PIN_5, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  delay(1000);
  pinMode(1,OUTPUT);
  servoMain.attach(14); // servo on digital pin 1
  servoMain.write(179);

  esc.attach(3);
  int throttle = analogRead(throttlePin);
  throttle = map(throttle, 220, 1023, 73, 179);
  esc.write(throttle);
}

void loop() {

  delay(100); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  
  //int throttle = analogRead(throttlePin);
  //throttle = map(throttle, 0, 700, 0, 179);
  //esc.write(throttle);

  Serial.println("");
  
  Serial.print("Sensor #1: ");
  Serial.print(sonar_1.ping_cm());
  Serial.print(" cm");

  Serial.println("");

  Serial.print("Sensor #2: ");
  Serial.print(sonar_2.ping_cm());
  Serial.print(" cm");

  Serial.println("");

  Serial.print("Sensor #3: ");
  Serial.print(sonar_3.ping_cm());
  Serial.print(" cm");

  Serial.println("");

  Serial.print("Sensor #4: ");
  Serial.print(sonar_4.ping_cm());
  Serial.print(" cm");

  Serial.println("");

  Serial.print("Sensor #5: ");
  Serial.print(sonar_5.ping_cm());
  Serial.print(" cm");

  Serial.println("");

  if(sonar_1.ping_cm() <= 60) {
    servoMain.write(40); 
    if(sonar_4.ping_cm() <= 100) {
    servoMain.write(40); 
  }
  }

  if(sonar_3.ping_cm() <= 60) {
    servoMain.write(180); 
    if(sonar_5.ping_cm() <= 100) {
    servoMain.write(180); 
  }
  }

}
