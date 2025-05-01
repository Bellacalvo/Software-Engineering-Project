// pin defintions
#define motionSensorPin 2 // pin connected to the motion sensor
#define relayPin 4 // pin connected to the relay

//state variables
bool pump_triggered = false; //track to see if the pump has been triggered
unsigned long pump_trigger_time = 0; //store the time when motion has been detected
const unsigned long pumpDuration = 5000; // time for how long the pump will be on (5 seconds)
const int calibrationTime = 30; // time for how long the motion sesnor will calibrate

//On startup it will initialize the pins for input and output
//then it will begin the serial comms
// finally will preform a sensor callibrate
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
    Serial.println("The sensor is ready");
    delay(50);
}

// This will run contionously that will monitor the motion detection, pump activation, and force a cooldown period
void loop() {
  bool motionDetected = digitalRead(motionSensorPin) == HIGH;
  // motion is detected and the pump has not been triggered yet
  if (!pump_triggered && motionDetected) {
    // Only trigger if not already triggered
    pump_triggered = true;
    pump_trigger_time = millis();
    digitalWrite(relayPin, HIGH); // Turn Pump ON
    Serial.println("Motion detected! Pump ON");
  }
  // no motion and pump is not ON
  else if (!pump_triggered && !motionDetected) {
    // No motion and pump is not running
    Serial.println("No motion detected.");
  }
  //Pump is running and the duration of 5 seconds has passed
  if (pump_triggered && (millis() - pump_trigger_time >= pumpDuration)) {
    digitalWrite(relayPin, LOW); // Turn pump OFF
    Serial.println("5 seconds passed. Pump OFF");
    pump_triggered = false;
  }

  delay(100); // Small delay
}


