int motorPin = 6;
float motorSpeed = 80; //1 - 100%
float dutyCycle;
float timeOn = .1; //Minutes
float timeOff = .1; //Minutes
int count;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  if (count <= 60*timeOn) {
    dutyCycle = 30+(100*(motorSpeed/100));
    analogWrite(motorPin, dutyCycle);
  }

  else if ((count > 60*timeOn) && (count <= 60*(timeOff+timeOn))) {
    dutyCycle = 0;
    analogWrite(motorPin, dutyCycle); 
  }

  else if (count > 60*(timeOn+timeOff)) {
    count = 0;
  }

  Serial.print(dutyCycle);
  Serial.print("\n");
  Serial.print(count);
  Serial.print("\n");
    
  count += 1;
  delay(1000);
}
