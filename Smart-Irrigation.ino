#include <Arduino.h>
#include <DHT.h>

#define SOIL_MOISTURE_PIN 34
#define DHT_PIN 4
#define DHT_TYPE DHT11
#define RELAY_PIN 26

const bool RELAY_ACTIVE_LOW = true;
const int DRY_THRESHOLD = 35;
const int STOP_THRESHOLD = 55;

const int SOIL_RAW_DRY = 3200;
const int SOIL_RAW_WET = 1200;

const unsigned long READ_INTERVAL = 2000;

DHT dht(DHT_PIN, DHT_TYPE);
unsigned long lastReadTime = 0;
bool pumpRunning = false;

void setPump(bool on) {
  pumpRunning = on;
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_PIN, on ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, on ? HIGH : LOW);
  }
}

int readSoilMoisture() {
  int raw = analogRead(SOIL_MOISTURE_PIN);
  int moisture = map(raw, SOIL_RAW_DRY, SOIL_RAW_WET, 0, 100);
  return constrain(moisture, 0, 100);
}

void setup() {
  Serial.begin(115200);
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  setPump(false);
  dht.begin();

  Serial.println("Smart Irrigation System Started");
}

void loop() {
  unsigned long now = millis();
  if (now - lastReadTime < READ_INTERVAL) return;
  lastReadTime = now;

  int moisture = readSoilMoisture();
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!pumpRunning && moisture < DRY_THRESHOLD) {
    setPump(true);
    Serial.println("Soil is dry -> Pump ON");
  } else if (pumpRunning && moisture >= STOP_THRESHOLD) {
    setPump(false);
    Serial.println("Target moisture reached -> Pump OFF");
  }

  Serial.println("========== SMART IRRIGATION ==========");
  Serial.printf("Soil Moisture : %d%%\n", moisture);

  if (isnan(temperature)) Serial.println("Temperature   : Sensor error");
  else Serial.printf("Temperature   : %.1f C\n", temperature);

  if (isnan(humidity)) Serial.println("Humidity      : Sensor error");
  else Serial.printf("Humidity      : %.1f%%\n", humidity);

  Serial.print("Pump          : ");
  Serial.println(pumpRunning ? "ON" : "OFF");
  Serial.println("======================================");
}
