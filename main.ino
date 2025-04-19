#define led_pin 8 // red led
#define led_pin2 7 // blue led
#define led_pin3 4 // white led
#define pir_pen 3 // Sensor 
#define button_pin 2 // button

int sensorCalibrationTime = 30; // Time sensor calibration


void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(button_pin, INPUT);

  digitalWrite(pir_pen, LOW);

  for(int i = 0; i < sensorCalibrationTime; i++){
    Serial.print("Calibrating...  (");
    Serial.print(i);
    Serial.print("secs)");
    delay(1000);
  }

  Serial.print("Calibration Complete");
  digitalWrite(led_pin3, HIGH);
}

void loop() {
  if(digitalRead(button_pin) == HIGH){
    digitalWrite(led_pin, HIGH);
    if(digitalRead(pir_pen) == HIGH){
      digitalWrite(led_pin2, HIGH);
      delay(300); 

      digitalWrite(led_pin2, LOW);
      delay(300); 
    }
    else{
      digitalWrite(led_pin2, LOW);
    }
  }
  else{
    digitalWrite(led_pin, LOW);
  }
}
