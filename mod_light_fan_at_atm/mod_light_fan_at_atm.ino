const int trigPin = 9;
const int echoPin = 10;
const int fanPin = 4;
const int fanpin1= 5;
const int lightPin = 2;
const int maximumdistance =15;

long duration;
int distance; // The threshold distance in centimeters

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(fanpin1,OUTPUT);
  pinMode(lightPin, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo duration and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;

  // Turn on the fan and light if distance is below threshold
  if (distance <= maximumdistance) {
    digitalWrite(fanPin, HIGH);
    digitalWrite(fanpin1 ,HIGH);
    digitalWrite(lightPin, HIGH);
  } else {
    digitalWrite(fanPin, LOW);
    digitalWrite(fanpin1, LOW);
    digitalWrite(lightPin, LOW);
  }

  // Delay for a short period of time before taking another reading
  delay(50);
}
