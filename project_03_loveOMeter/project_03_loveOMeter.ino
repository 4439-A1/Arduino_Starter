const int sensorPin = A0;
const float baselineTemp = 19.0;
float increment = 1.5;

void setup(){
    Serial.begin(9600); // open a serial port

    for(int pinNumber = 2; pinNumber < 6; pinNumber++){
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
}

void loop(){
    int sensorVal = analogRead(sensorPin);

    Serial.print("Sensor Value: ");
    Serial.print(sensorVal);

    // convert ADC reading to voltage
    float voltage = (sensorVal/1024.0) * 5.0;

    Serial.print(", Volts: ");
    Serial.print(voltage);

    Serial.print(", degrees C: ");
    // convert voltage to temperature in degrees
    float temperature = (voltage - .5) * 100;
    Serial.println(temperature);
    
    // turn on green LED when the temperature read is above the baseline temperature
    if(temperature >= baselineTemp){
        digitalWrite(5, HIGH);
    }
    else{
        digitalWrite(5, LOW);
    }
    if(temperature < baselineTemp + increment){
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if(temperature >= baselineTemp + increment && temperature < baselineTemp + 2 * increment){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if(temperature >= baselineTemp + 2 * increment && temperature < baselineTemp + 3 * increment){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else if(temperature >= baselineTemp + 3 * increment){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(1);
}