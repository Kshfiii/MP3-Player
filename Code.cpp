/*
 * Strawberry Shortcake MP3 Player Firmware
 * Hardware: XIAO ESP32-C3 + DFPlayer Mini
 * 
 * Pinout Mapping:
 * - ESP32 D6 (TX) -> DFPlayer RX (Pin 2)
 * - ESP32 D7 (RX) -> DFPlayer TX (Pin 3)
 * - ESP32 D3      -> DFPlayer BUSY (Pin 16)
 * - ESP32 D4      -> Middle Play/Pause Button (Active LOW)
 */

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

// Schematic GPIO Definitions
#define PIN_PLAY_BTN D4  // Play/Pause button
#define PIN_BUSY     D3  // DFPlayer BUSY pin (LOW = Playing, HIGH = Idle/Paused)

// Hardware Serial on ESP32-C3
HardwareSerial mp3Serial(1);
DFRobotDFPlayerMini myDFPlayer;

bool isPlaying = false;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // Debounce threshold in ms

void setup() {
  Serial.begin(115200);

  // Initialize UART communication with DFPlayer Mini at 9600 baud
  mp3Serial.begin(9600, SERIAL_8N1, D7, D6); 

  // Configure Pins
  pinMode(PIN_PLAY_BTN, INPUT_PULLUP);
  pinMode(PIN_BUSY, INPUT);

  Serial.println(F("Initializing Strawberry MP3 Player..."));

  // Check communication with DFPlayer Mini
  if (!myDFPlayer.begin(mp3Serial)) {
    Serial.println(F("Error: DFPlayer Mini not detected! Check SD card & wiring."));
    while (true); // Freeze execution on hardware initialization failure
  }

  Serial.println(F("DFPlayer Online! Ready to play audio."));

  // Set default volume level (0 to 30)
  myDFPlayer.volume(20);
}

void loop() {
  // 1. Debounce and read Play/Pause Button
  bool reading = digitalRead(PIN_PLAY_BTN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    static bool buttonState = HIGH;
    if (reading != buttonState) {
      buttonState = reading;

      // Button press triggered (Active LOW)
      if (buttonState == LOW) {
        if (isPlaying) {
          myDFPlayer.pause();
          isPlaying = false;
          Serial.println(F("Playback: Paused"));
        } else {
          myDFPlayer.start();
          isPlaying = true;
          Serial.println(F("Playback: Playing"));
        }
      }
    }
  }

  lastButtonState = reading;

  // 2. Hardware state synchronization via BUSY Pin
  bool currentBusyState = digitalRead(PIN_BUSY);
  if (currentBusyState == LOW) {
    isPlaying = true;
  } else if (currentBusyState == HIGH && isPlaying) {
    // Track finished playing naturally
    isPlaying = false;
  }
}