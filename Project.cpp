#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {12, 11, 10}; //connect to the column pinouts of the keypad

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int led = 2;

void setup() {
  // set up the LCD's number of columns and rows:
  // lcd.begin(20, 4);
  // lcd.setCursor(1,2);
  // lcd.print("www.TheEngineering");
  // lcd.setCursor(4,3);
  // lcd.print("Projects.com");
  // lcd.setCursor(0,0);
  // pinMode(led,OUTPUT);
    lcd.begin(16, 2);
    lcd.setCursor(0,1);

}

void loop() {
char key = keypad.getKey();
char pass[3] = {} ;
int pass_index = 0;


if (key) {
  pass[pass_index] = key;
      currentPos++;
      Serial.print("Key added: ");
      Serial.println(key);
      Serial.print("Current pass: ");
      Serial.println(pass);
  lcd.print(key);
    }
}

if ()

delay(100);