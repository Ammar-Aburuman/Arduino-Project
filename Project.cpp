#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>

char passcode[] = {'7', '3', '5', '5', '6', '0', '8'}; // Stored passcode 7355608
char pass[7] = {}; // Array to store entered passcode, sized to 4 to include null terminator
int pass_index = 0;

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {12, 11, 10}; // Connect to the column pinouts of the keypad

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int led = 2;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  Serial.println("start");
  pinMode(led, OUTPUT);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    pass[pass_index] = key;
    pass_index++;
    Serial.print("Key added: ");
    Serial.println(key);
    Serial.print("Current pass: ");
    for (int i = 0; i < pass_index; i++) {
      Serial.print(pass[i]);
    }
    lcd.print(key);
    Serial.println("");

    // If pass_index reaches the passcode length, compare the arrays
    if (pass_index == 7) {
      if (!memcmp(pass, passcode, 7)) {
        Serial.println("Match");
        digitalWrite(led, HIGH); // Turn on the LED if the passcode matches
      } else {
        Serial.println("No Match");
        digitalWrite(led, LOW); // Turn off the LED if the passcode does not match
      }
      pass_index = 0; // Reset pass_index for new entry
      memset(pass, 0, sizeof(pass)); // Clear the pass array
      lcd.clear(); // Clear the LCD for new input
    }
  }

  delay(100);
}