//www.elegoo.com
//2016.12.9

int diodePin = 0;
int lightPin = 6;

void setup() 
{
  pinMode(lightPin, OUTPUT);
  digitalWrite(lightPin, HIGH);
  Serial.begin(9600);
  Serial.println("Photodiode readings;");
}

void loop() 
{
  Serial.println("\nLight level in lumens:");
  Serial.println(analogRead(diode1Pin));
  Serial.println("///////////////////////////////");
  delay(5000);

}


