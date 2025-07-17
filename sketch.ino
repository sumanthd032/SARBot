#include <DHT.h>

// Pin Definitions
#define IN1 14        // L298N Motor IN1
#define IN2 27        // L298N Motor IN2
#define IN3 26        // L298N Motor IN3
#define IN4 25        // L298N Motor IN4
#define TRIG_PIN 18   // Ultrasonic Trigger
#define ECHO_PIN 19   // Ultrasonic Echo
#define DHT_PIN 4     // DHT11 Data
#define IR_PIN 5      // IR Sensor
#define BUZZER_PIN 2  // Buzzer
#define LED_PIN 15    // LED

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

long duration;
int distance;

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Motor Pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic Pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // IR, Buzzer, LED
  pinMode(IR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("SARBot Simulation Started");
}

void loop() {
  // Read DHT11
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C, Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  // Read IR Sensor
  int irValue = digitalRead(IR_PIN);
  if (irValue == LOW) {
    Serial.println("Edge detected! Stopping.");
    stopMotors();
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  // Ultrasonic Obstacle Detection
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {
    Serial.println("Obstacle detected! Stopping and alerting.");
    stopMotors();
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  } else {
    moveForward();
  }

  delay(1000);
}

// Functions for motor movement
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Moving Forward");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Motors Stopped");
}

// Function to measure distance
int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout for safety
  int dist = duration * 0.034 / 2;
  return dist;
}
