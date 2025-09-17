// Analog pin connected to the photoresistor (LDR)
const int phrest = A0;

// Pins connected to the high beam and low beam LEDs
const int Highled = 6;
const int Lowled = 8;

// Pins connected to the left and right IR sensors
int irleft = 3;
int irright = 2;

// Pins connected to ultrasonic sensor trigger and echo
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Initialize serial communication at 9600 baud rate for debugging
  Serial.begin(9600);

  // Set LDR pin as input
  pinMode(phrest, INPUT);

  // Set LED pins as outputs
  pinMode(Highled, OUTPUT);
  pinMode(Lowled, OUTPUT);

  // Set IR sensor pins as inputs
  pinMode(irleft, INPUT);
  pinMode(irright, INPUT);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Read the analog value from LDR sensor (0 to 1023)
  int data = analogRead(phrest);

  // Map the analog value to a smaller range (0 to 30) for threshold control
  int value = map(data, 0, 1023, 0, 30);

  // Print the mapped LDR value for debugging
  Serial.println(value);

  // If very dark (night time, below threshold), check for objects using ultrasonic and IR sensors
  if (value < 3) {
    object();
  }
  // If ambient light is moderate (well-lit street or dusk), switch to low beam
  else if (value >= 3 && value < 10) {
    digitalWrite(Lowled, HIGH);
    digitalWrite(Highled, LOW);
  }
  // If bright (daytime or enough ambient light), turn off both headlights
  else {
    digitalWrite(Lowled, LOW);
    digitalWrite(Highled, LOW);
  }
}

// Function to detect objects and decide headlight state using IR and ultrasonic sensors
void object() {
  long duration;

  // Trigger the ultrasonic sensor to send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time for the echo to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters from the duration of echo pulse
  float cm = (duration / 58.0);

  // Print distance for debugging
  Serial.print(cm);
  Serial.println(" cm");

  // Read values from the left and right IR sensors (HIGH or LOW)
  bool irValueleft = digitalRead(irleft);
  bool irValueright = digitalRead(irright);

  // Condition explanation:
  // If either IR sensor detects an object (assuming LOW means detected) 
  // or ultrasonic sensor detects an object closer than 30 cm,
  // then switch to low beam to avoid glaring.
  if (irValueleft == 0 || irValueright == 0 || cm < 30) {
    digitalWrite(Highled, LOW);  // Turn OFF high beam
    digitalWrite(Lowled, HIGH);  // Turn ON low beam
  }
  // Else, no vehicle detected nearby, so use high beam for better visibility
  else {
    digitalWrite(Highled, HIGH); // Turn ON high beam
    digitalWrite(Lowled, LOW);   // Turn OFF low beam
  }

  delay(100); // Short delay for sensor stability and debounce
}
