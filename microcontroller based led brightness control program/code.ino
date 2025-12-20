int pot = A5;

int Value = 0;

int bright = 0;

int led = 2;

void setup() {

  Serial.begin(9600);

  pinMode(led, OUTPUT);
}




void loop() {

  Value = analogRead(pot);

  bright = (255.0/1023.0)*Value;

  analogWrite(led, bright);

}
