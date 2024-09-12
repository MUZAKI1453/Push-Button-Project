#define LED_PIN 4
#define BUTTON_PIN 3

void setup() {
  pinMode(LED_PIN, OUTPUT);  
  pinMode(BUTTON_PIN, INPUT); 
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {  
    digitalWrite(LED_PIN, LOW);  
  } else if (digitalRead(BUTTON_PIN) == HIGH) {  
    digitalWrite(LED_PIN, HIGH);   
  }
}
