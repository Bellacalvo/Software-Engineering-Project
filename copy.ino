#define LED_1 3
#define motionSensorPin 2
#define valvePin 4

bool trigger = false;

void setup() {
  Serial.begin(9600); 
  pinMode(LED_1, OUTPUT);
  pinMode(motionSensorPin, INPUT);
  pinMode(valvePin, OUTPUT);

  digitalWrite(LED_1, LOW);      
  digitalWrite(valvePin, LOW);   
}

void loop() {
  bool motionDetected = digitalRead(motionSensorPin) == HIGH;

  Serial.print("Motion Detected: ");
  Serial.println(motionDetected ? "Yes" : "No");

  if (motionDetected) {
    if (!trigger) {
      digitalWrite(valvePin, HIGH);
      delay(10000) #delay for to seconds so the valve will run
      digitalWrite(LED_1, HIGH);
      Serial.println("Motion has been detected! Light and Valve ON");
      trigger = true;
    }
  } else {
    digitalWrite(valvePin, LOW);
    digitalWrite(LED_1, LOW);
    trigger = false;
  }

  delay(500); 
}


