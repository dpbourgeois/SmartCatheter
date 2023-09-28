//www.elegoo.com
//2016.12.9

int diode1Pin = 0;
int diode2Pin = 1;
int light1Pin = 6;
int light2Pin = 5;
int reading1 = 0;
int reading2 = 0;

void setup() 
{
  pinMode(light1Pin, OUTPUT);
  pinMode(light2Pin, OUTPUT);
  digitalWrite(light1Pin, HIGH);
  digitalWrite(light2Pin, HIGH);
  Serial.begin(9600);
  Serial.println("Photodiode readings;");
}

void loop() 
{
  unsigned long start = 0;
  unsigned long finish = 0;
  int newRead = analogRead(diode1Pin);
  if (abs(reading1 - newRead) > 120) {
    reading1 = newRead;
    start = millis();
    while(true) {
      newRead = analogRead(diode2Pin);
      if (abs(reading2 - newRead) > 120) {
        reading2 = newRead;
        finish = millis();
        break;
      }
    }
    double rate = 50.8 / (finish - start);
    if (rate > 0 && rate < 20) {
      Serial.println("\nRate in m/s:");
      Serial.println(50.8 / (finish - start));
      Serial.println("///////////////////////////////");
      delay(3000);
    }
  }
}


