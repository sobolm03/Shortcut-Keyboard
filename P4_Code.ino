// Include the keyboard library
// This library allows the arduino to press buttons on the keyboard
#include <Keyboard.h>
// Declaring pins that the capacitive buttons use
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

// Declaring the buttons' states
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

// Declaring varibles for debounce time (unsigned means positive values only)
unsigned long previousMillis = 0; // Previous milliseconds
unsigned long elapsedMillis = 0; // Elapsed milliseconds since button press
int debounceTime = 1000; // Debounce time for touch sensor

void setup() {
  // Initializing pinModes of the pins being used on the Arduino Pro Micro
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
}

// Main loop
void loop() {
  // Reading the button states (HIGH or LOW)
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  // Calculating the elapsed milliseconds
  elapsedMillis = millis() - previousMillis;  
  // The millis() function returns the
  // number of milliseconds passed since the Arduino board began running the current program.


  // Following If statements check if button is being pressed and checks if the 
  // elapsed time is larger than the debounce time given

  // This when this button is pressed, it performs the copy keyboard shortcut
  if (buttonState1 == HIGH && elapsedMillis > debounceTime) {
    Keyboard.press(KEY_LEFT_CTRL); // Presses the bottom left CTRL button
    Keyboard.press('c'); // Presses the 'c' button
    delay(100);
    Keyboard.releaseAll(); // Releases all key presses

    // Stores the current milliseconds on the previous milliseconds
    previousMillis = millis();
    }
    
  // This when this button is pressed, it performs the paste keyboard shortcut
  if (buttonState2 == HIGH && elapsedMillis > debounceTime) {
    Keyboard.press(KEY_LEFT_CTRL); // Presses the bottom left CTRL button
    Keyboard.press('v'); // Presses the 'v' button
    delay(100);
    Keyboard.releaseAll(); // Releases all key presses

    // Stores the current milliseconds on the previous milliseconds
    previousMillis = millis();
    }

  // This when this button is pressed, it performs the new tab keyboard shortcut
  if (buttonState3 == HIGH && elapsedMillis > debounceTime) {
    Keyboard.press(KEY_LEFT_CTRL); // Presses the bottom left CTRL button
    Keyboard.press('t'); // Presses the 't' button
    delay(100);
    Keyboard.releaseAll(); // Releases all key presses

    // Stores the current milliseconds on the previous milliseconds
    previousMillis = millis();
    }

  // This when this button is pressed, it performs the close tab keyboard shortcut
  if (buttonState4 == HIGH && elapsedMillis > debounceTime) {
    Keyboard.press(KEY_LEFT_CTRL); // Presses the bottom left CTRL button
    Keyboard.press('w'); // Presses the 't' button
    delay(100);
    Keyboard.releaseAll(); // Releases all key presses

    // Stores the current milliseconds on the previous milliseconds
    previousMillis = millis();
    }
}
