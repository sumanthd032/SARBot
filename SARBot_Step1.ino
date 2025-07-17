// SARBot_Step1.ino
#include <NewPing.h>
#include <DHT.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define DHT_PIN 2
#define DHT_TYPE DHT22 // Using DHT22 sensor
#define MAX_DISTANCE 200 // Max distance for HC-SR04 (in cm)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000); // Allow DHT22 to stabilize
  Serial.println("SARBot Step 1: Sensor Initialization (HC-SR04 & DHT22)");
}

void loop() {
  // Read HC-SR04 (ultrasonic sensor)
  unsigned int distance = sonar.ping_cm();
  Serial.print("Distance: ");
  if (distance == 0) {
    Serial.println("No echo (out of range)");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Read DHT22 (temperature and humidity)
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT22 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(1000); // Wait 1 second before next reading
}