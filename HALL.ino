const int hallSensorPin = A1;
int read = 0;
int state = 0;
long previousMillis = 0;
int count = 0;

void setup() {
  pinMode(hallSensorPin, INPUT); 
  Serial.begin(9600);       // use the serial port
}

void loop() {
  read = analogRead(hallSensorPin);

  long currentMillis = millis();

  if (currentMillis - previousMillis >= 300) {

    if(read < 790 && state == 0) {
      previousMillis = currentMillis;
      // Serial.print("read ");
      // Serial.println(read);
      state = 1;
      Serial.print("passing ");
      Serial.println(count);
      count++;
    } else if(read > 790 && state == 1) {
      state = 0;
    }
  }
  // delay(1000);
}