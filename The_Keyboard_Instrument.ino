// Create note values array
// These values determine the current that is sent to the piezo.
// The higher the value the higher the sound pitch outputted by the piezo
int notes[] = {
  242,
  284,
  306,
  328,
  350
};

void setup() {
  // Start Serial monitor to see the debu messages in the serial at 9600 BAUD rate
  Serial.begin(9600);
}

void loop() {
  // Capture the analog value from the push button pins
  int keyVal = analogRead(A0);

  // Print this value to the Serial monitor
  Serial.println(keyVal);

  // Play a tone by reading the analog value from the key presses.
  // The different key values are determined by the different resistors used
  // This is a pretty effective way to have large amounts of push buttons on 
  // a board
  if (keyVal == 1023) {
    tone(8, notes[0]);
  } else if (keyVal >= 940 && keyVal <= 960) {
    tone(8, notes[1]);
  } else if (keyVal >= 990 && keyVal <= 1010) {
    tone(8, notes[2]);
  } else if (keyVal >= 490 && keyVal <= 520) {
    tone(8, notes[3]);
  } else if (keyVal <= 50 && keyVal >= 2) {
    tone(8, notes[4]);
  } else {
    noTone(8); // If no button is pushed then the key tones are disabled
  }
}
