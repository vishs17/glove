#include <SoftwareSerial.h>

// Pin assignments for flex sensors
const int flexPin1 = A0;
const int flexPin2 = A1;
const int flexPin3 = A2;
const int flexPin4 = A3;

// Initialize Bluetooth module communication pins (RX, TX)
SoftwareSerial bluetooth(2, 3); // RX, TX

void setup() {
  // Start serial communication for debugging and Bluetooth communication
  Serial.begin(9600);
  bluetooth.begin(9600);

  // Set flex sensor pins as input
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
}

void loop() {
  // Read flex sensor values
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);
  int flexValue3 = analogRead(flexPin3);
  int flexValue4 = analogRead(flexPin4);

  // Check flex sensor values and send appropriate messages
  if (flexValue1 < 1030 && flexValue2 < 995 && flexValue3 < 995 && flexValue4 < 1030) {
    Serial.println("Washroom");
    bluetooth.println("Washroom");
  } else if (flexValue1 < 1030 && flexValue2 > 1000 && flexValue3 < 995 && flexValue4 < 1030) {
    Serial.println("Gloves is at rest");
    bluetooth.println("Gloves is at rest");
  } else if (flexValue1 < 1030 && flexValue2 < 995 && flexValue3 > 1000 && flexValue4 < 1030) {
    Serial.println("Please Help");
    bluetooth.println("Please Help");
  } else if (flexValue1 < 1050 && flexValue2 > 1000 && flexValue3 > 1000 && flexValue4 < 1050) {
    Serial.println("HELP");
    bluetooth.println("HELP");
  }

  // Additional conditions
  if (flexValue1 < 1050 && flexValue2 < 1000 && flexValue3 > 1000 && flexValue4 > 1050) {
    Serial.println("Help");
    bluetooth.println("Help");
  } else if (flexValue1 > 1020 && flexValue2 < 995 && flexValue3 < 990 && flexValue4 > 900) {
    Serial.println("Take Me Out");
    bluetooth.println("Take Me Out");
  } else {
    Serial.println("No sensors are bent.");
    bluetooth.println("No sensors are bent.");
  }

  // Add a small delay to avoid spamming
  delay(500);
}
