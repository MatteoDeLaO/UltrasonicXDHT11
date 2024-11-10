#include <DHT.h>           // Include the DHT sensor library
#include <Ultrasonic.h>     // Include the Ultrasonic sensor library

// Define pins for the sensors
#define DHTPIN 2            // DHT sensor data pin connected to digital pin 2
#define DHTTYPE DHT11       // DHT 11 sensor type (can be DHT22 as well)

#define TRIG_PIN 9          // HC-SR04 Trigger Pin connected to digital pin 9
#define ECHO_PIN 10         // HC-SR04 Echo Pin connected to digital pin 10

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize the Ultrasonic sensor
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);    // Start Serial communication
  dht.begin();           // Initialize the DHT sensor
  Serial.println("Sensor Readings:");
}

void loop() {
  // Reading temperature and humidity from the DHT sensor
  float temperature = dht.readTemperature();   // Get temperature in Celsius
  float humidity = dht.readHumidity();         // Get humidity percentage

  // If the readings are invalid, print error
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Reading the distance from the ultrasonic sensor
  long distance = ultrasonic.read();           // Get the distance in centimeters

  // Print the readings to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature); // Print temperature
  Serial.print(" °C, ");

  Serial.print("Humidity: ");
  Serial.print(humidity); // Print humidity
  Serial.print(" %, ");

  Serial.print("Distance: ");
  Serial.print(distance); // Print distance
  Serial.println(" cm");

  // Wait 2 seconds before the next reading
  delay(2000);
}


