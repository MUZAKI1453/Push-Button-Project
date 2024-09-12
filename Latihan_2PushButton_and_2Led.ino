#define redLed 4
#define buttonRed 3
#define greenLed 2
#define buttonGren 1  

bool redLedState = LOW;
bool greenLedState = LOW;
bool lastButtonRedState = HIGH;
bool lastButtonGreenState = HIGH;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buttonRed, INPUT_PULLUP);
  pinMode(buttonGren, INPUT_PULLUP);  // Gunakan buttonGren seperti yang dideklarasikan

  digitalWrite(redLed, redLedState);
  digitalWrite(greenLed, greenLedState);
}

void loop() {
  // Baca keadaan tombol untuk LED merah
  bool currentButtonRedState = digitalRead(buttonRed);
  if (currentButtonRedState == LOW && lastButtonRedState == HIGH) {
    redLedState = !redLedState;  // Toggle LED merah
    digitalWrite(redLed, redLedState);
    delay(50);  // Debounce sederhana
  }
  lastButtonRedState = currentButtonRedState;

  // Baca keadaan tombol untuk LED hijau
  bool currentButtonGreenState = digitalRead(buttonGren);  // Konsisten dengan buttonGren
  if (currentButtonGreenState == LOW && lastButtonGreenState == HIGH) {
    greenLedState = !greenLedState;  // Toggle LED hijau
    digitalWrite(greenLed, greenLedState);
    delay(50);  // Debounce sederhana
  }
  lastButtonGreenState = currentButtonGreenState;
}
