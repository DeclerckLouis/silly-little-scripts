/* This code is my adaptation of what i found on https://arduinogetstarted.com/tutorials/arduino-soil-moisture-sensor
 * This prototype is supposed to check moisture levels of the soil, and notify the user when the levels are too low (red LED)
 * I thought about adding a green LED for when the levels are okay, but it would probably just annoy me. If you want to do it, just uncomment the part at 
 */

int minThreshold = 100 // Change threshold as needed, it depends on the sensor, the soil and the plant.
int maxThreshold = 500 // This is experimental, i might not use it.
int ledWaterNeeded = 7;
int delayValue = 500 // Can be changed if desired, personally, i don't see the point but go off


void setup() {
  Serial.begin(9600);
  Serial.println("Ready for caregiving, delay set at " + String(delayValue));
  pinMode(ledWaterNeeded, OUTPUT);
  Serial.println("Blinking LED");
  digitalWrite(ledWaterNeeded, HIGH);
  delay(2000);
  digitalWrite(ledWaterNeeded, LOW);
  delay(1000);
  }

void loop() {
  int moistMeterValue = analogRead(A0); // read analog value every time the loop starts over

  if (moistMeterValue < minThreshold){ //check moisture level against set threshold
    Serial.println("The soil is DRY (" + String(moistMeterValue));
    digitalWrite(ledWaterNeeded, HIGH);
  }
  else if (minThreshold > moistMeterValue){
    if (moistMeterValue < maxThreshold){
      Serial.println("The soil is GOOD (" + String(moistMeterValue)); 
  }
      
  }
  else {
    Serial.println("The soil is TOO WET (" + String(moistMeterValue));
    blinkLED(ledWaterNeeded);
  }
  Serial.println(")");
  delay(delayValue);
  digitalWrite(ledWaterNeeded, LOW);
}

void blinkLED(int led){
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200); // 1 sec
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200); // 2 sec
 }