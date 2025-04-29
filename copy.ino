#define motionSensorPin 2
#define relayPin 4

bool triggered = false;
unsigned long triggerTime = 0;
const unsigned long blockDuration = 5000; // 5 seconds
const int calibrationTime = 30; // seconds

void setup() {
  pinMode(motionSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600); 

  digitalWrite(relayPin, LOW);  
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
}

void loop() {
  bool motionDetected = digitalRead(motionSensorPin) == HIGH;

  if (!triggered && motionDetected) {
    // Only trigger if not already triggered
    triggered = true;
    triggerTime = millis();
    digitalWrite(relayPin, HIGH); // Turn ON pump
    Serial.println("Motion detected! Pump ON");
  }
  else if (!triggered && !motionDetected) {
    // No motion and pump is not running
    Serial.println("No motion detected.");
  }

  if (triggered && (millis() - triggerTime >= blockDuration)) {
    // After 15 seconds, turn OFF pump and reset trigger
    digitalWrite(relayPin, LOW); // Turn OFF pump
    Serial.println("5 seconds passed. Pump OFF");
    triggered = false;
  }

  delay(100);
}


