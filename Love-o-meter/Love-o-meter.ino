const int sensorPin = A0;
const float baselineTemp = 14.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int pinNumber = 3; pinNumber<6; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, 0);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) *5.0;
  Serial.print(",Volts:");
  Serial.print(voltage);
  Serial.print(",degress C: ");
  float temperature = (voltage-.5)*100;
  Serial.println(temperature);

  if (temperature < baselineTemp){
    digitalWrite (3, 0);
    digitalWrite (4, 0);
    digitalWrite (5, 0);
  }
  else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite (3, 1);
    digitalWrite (4, 0);
    digitalWrite (5, 0);
  }
  else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite (3, 1);
    digitalWrite (4, 1);
    digitalWrite (5, 0);
  }
  else if (temperature >= baselineTemp+6){
    digitalWrite (3, 1);
    digitalWrite (4, 1);
    digitalWrite (5, 1);
  }
  delay(1);
}
