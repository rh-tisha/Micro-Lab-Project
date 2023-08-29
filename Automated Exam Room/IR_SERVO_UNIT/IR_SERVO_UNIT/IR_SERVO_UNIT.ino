#include <ESP32_Servo.h>
Servo servo;

const int irSensorPin = 12; // Change this to the actual pin number
const int servoPin = 13; 

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(irSensorPin, INPUT); // Set IR sensor pin as input
  servo.attach(servoPin);
}

void loop() {
  // Read IR sensor value
  int irSensorValue = digitalRead(irSensorPin);

  // Print the sensor value to the Serial Monitor
  Serial.print("IR Sensor Value: ");
  Serial.println(irSensorValue);

  if(irSensorValue == 0 ){    
     servo.write(0);//change angle according to your needs
     delay(2000);
     servo.write(150);
     
     Serial.println("press");
    }
  else{
    servo.write(150);
    }

  delay(1000); // Delay for 1 second before reading again
}
