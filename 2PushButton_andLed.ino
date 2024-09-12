#define LED_PIN 4
#define BUTTON_PIN 3

bool ledState = LOW;  // Keadaan awal LED mati
bool lastButtonState = HIGH;  // Keadaan awal tombol tidak ditekan

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Pin LED sebagai output
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Pin tombol sebagai input dengan pull-up internal
  digitalWrite(LED_PIN, ledState);  // Set kondisi awal LED
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);  // Baca keadaan tombol

  // Jika tombol ditekan dan dilepas (transisi dari HIGH ke LOW)
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;  // Toggle keadaan LED
    digitalWrite(LED_PIN, ledState);  // Ubah keadaan LED sesuai toggle
    delay(50);  // Debounce sederhana
  }

  lastButtonState = currentButtonState;  // Simpan keadaan tombol terakhir
}
