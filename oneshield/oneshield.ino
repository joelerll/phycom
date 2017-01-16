/*
By : Thomas Ouellet Fredericks
Connect the Ultrasonic Sensor's TRIGGER pin to digital pin 7.
Ground the MODE/OUT pin.
*/

#define trigg 9 
#define echo 8

int Distancia()
{
  long tiempo;
  
  digitalWrite(trigg,LOW);
  delayMicroseconds(5);
  digitalWrite(trigg, HIGH); 
  delayMicroseconds(10);
  tiempo = pulseIn(echo, HIGH);
  return int(0.017*tiempo);
}



void setup() {
     Serial.begin(9600);
     pinMode(6, OUTPUT);
     pinMode(trigg, OUTPUT);
     pinMode(echo, INPUT);
}

void loop() {
      if (Distancia() < 10) {
        Serial.println("Correcto");
        digitalWrite(6, HIGH);
        delay(1000);
      }
      digitalWrite(6, LOW);

}

