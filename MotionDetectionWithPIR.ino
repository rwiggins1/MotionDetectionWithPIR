int sensorCalibrationTime = 30; // Time sensor needs to calibrate


void setup() {
  //pinMode(led_pin, OUTPUT);
  volatile uint8_t* red_led_dir = (volatile uint8_t*)0x24;
  *red_led_dir |= (1 << 0);
  
  //pinMode(led_pin2, OUTPUT);
  volatile uint8_t* blue_led_dir = (volatile uint8_t*)0x2A;
  *blue_led_dir |= (1 << 7);
  
  // pinMode(led_pin3, OUTPUT);
  volatile uint8_t* start_led_dir = (volatile uint8_t*)0x2A;
  *start_led_dir |= (1 << 4);
  
  //pinMode(button_pin, INPUT);
  volatile uint8_t* Button_pin_dir = (volatile uint8_t*)0x2A;
  *Button_pin_dir &= ~(1 << 2);
  
  
  volatile uint8_t* portd = (volatile uint8_t*)0x2B;
  *portd |= (1 << 2); // Enable pull-up
  

  //digitalWrite(pir_pen, LOW);
  volatile uint8_t* pir_pin_dir = (volatile uint8_t*)0x2A;
  *pir_pin_dir &= ~(1 << 3);
  
  volatile uint8_t* portd_pir = (volatile uint8_t*)0x2B;
  *portd_pir |= (1 << 3); // Enable pull-up

  for(int i = 0; i < sensorCalibrationTime; i++){
    Serial.print("Calibrating...  (");
    Serial.print(i);
    Serial.print("secs)");
    delay(1000);
  }

  Serial.print("Calibration Complete");
  volatile uint8_t* start_led = (volatile uint8_t*)0x2B;
  *start_led |= (1 << 4);
}

void loop() {
  // digitalRead(button_pin)
  volatile uint8_t* Button_pin = (volatile uint8_t*)0x29;
  if((*Button_pin & (1 << 2)) == 0){
    //digitalWrite(led_pin, HIGH);
    volatile uint8_t* red_led = (volatile uint8_t*)0x25;
  	*red_led &= ~(1 << 0);
    
    volatile uint8_t* pir_pin = (volatile uint8_t*)0x29;
    if((*pir_pin & (1 << 3)) == 0){
      //digitalWrite(led_pin2, HIGH);
      volatile uint8_t* blue_led = (volatile uint8_t*)0x2B;
      *blue_led |= (1 << 7);
      delay(300); 

      //digitalWrite(led_pin2, LOW);
      *blue_led &= ~(1 << 7);
      delay(300); 
    }
    else{
      volatile uint8_t* blue_led = (volatile uint8_t*)0x2B;
      *blue_led &= ~(1 << 7);
    }
  }
  else{
    volatile uint8_t* red_led = (volatile uint8_t*)0x25;
	*red_led |= (1 << 0);  // Turn off red LED (PB0)
  }
}
