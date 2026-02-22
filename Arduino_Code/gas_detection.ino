// Gas Leakage Detection System
// Author: Mancy Maran

int gasSensor = A0;      // MQ-2 gas sensor connected to analog pin A0
int buzzer = 8;          // Buzzer connected to digital pin 8
int gasThreshold = 300;  // Threshold value for gas detection (adjust as needed)

void setup() {
  Serial.begin(9600);    // Start Serial Monitor
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop() {
  int gasValue = analogRead(gasSensor);  // Read sensor value
  Serial.print("Gas sensor value: ");
  Serial.println(gasValue);

  if (gasValue > gasThreshold) {
    digitalWrite(buzzer, HIGH);          // Turn on buzzer
    Serial.println("🚨 Gas leakage detected!");
    // Optional: add GSM/SMS alert code here
  } else {
    digitalWrite(buzzer, LOW);           // Turn off buzzer
    Serial.println("Gas level normal.");
  }

  delay(1000); // Wait 1 second before next reading
}