//Arduino Code
#include <Wire.h>
#include <Adafruit_LEDBackpack.h>
// Define pins for components
#define GAS_SENSOR_ANALOG_PIN A0
#define LED_PIN 12
#define BUZZER_PIN 11
#define HEATER_PIN_1 9 // Assign pin number for heater 1
#define HEATER_PIN_2 10 // Assign pin number for heater 2
// Define threshold for gas concentration
#define GAS_THRESHOLD 100 // Adjust this value according to sensor's
sensitivity
void setup() {
// Initialize serial communication for debugging
Serial.begin(9600);
// Set LED and buzzer pins as output
pinMode(LED_PIN, OUTPUT);
pinMode(BUZZER_PIN, OUTPUT);
// Set heater pins as output and power the heater
pinMode(HEATER_PIN_1, OUTPUT);
pinMode(HEATER_PIN_2, OUTPUT);
digitalWrite(HEATER_PIN_1, HIGH); // Power the heater
digitalWrite(HEATER_PIN_2, HIGH); // Power the heater
}
void loop() {
// Read gas sensor value
int gasValue = analogRead(GAS_SENSOR_ANALOG_PIN);
// Print gas sensor value for debugging
Serial.print("Gas Value: ");
Serial.println(gasValue);
// Check if gas concentration exceeds threshold
if (gasValue > GAS_THRESHOLD) {
// Gas leakage detected
digitalWrite(LED_PIN, HIGH); // Turn on LED
tone(BUZZER_PIN, 1000); // Activate buzzer
delay(1000); // Delay for 1 second
digitalWrite(LED_PIN, LOW); // Turn off LED
noTone(BUZZER_PIN); // Stop buzzer
}
// Delay for a short period before taking next reading
delay(1000); // Adjust this delay according to your requirements
}
