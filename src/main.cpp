#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

static constexpr uint8_t ATTINY_LED = (3);
static constexpr uint8_t ATTINY_BUTTON = (4);
bool button_pressed = false;

static constexpr uint16_t morse_duration_short = 10;
static constexpr uint16_t morse_duration_long = 3 * morse_duration_short;
static constexpr uint16_t morse_duration_letter = 2 * morse_duration_short;
static constexpr uint16_t morse_duration_space = 6 * morse_duration_short;

void morse_short();
void morse_long();
void morse_divide_letter();
void morse_space();
// the setup function runs once when you press reset or power the board
void setup()
{
  SREG &= 0x7F;         // equals cli()
  GIMSK |= (1 << PCIE); // Pin Change Interrupt Enable Bit

  // Pin Change Interrupt Enable Mask
  PCMSK |= (1 << PCINT4);
  SREG |= 0x80; // equals sei()

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ATTINY_LED, OUTPUT);
  pinMode(ATTINY_BUTTON, INPUT_PULLUP);
  ADCSRA = 0; // ADC disabled
}

ISR(PCINT0_vect)
{
  if (digitalRead(ATTINY_BUTTON) == LOW)
  {
    button_pressed = true;
  }
}
€
void loop()
{
  while (button_pressed)
  { // Morse Code : "I love you" -> .. / .-.. --- ...- . / -.-- --- ..-
    morse_short();
    morse_short();
    morse_space();

    morse_short();
    morse_long();
    morse_short();
    morse_short();
    morse_divide_letter();
    morse_long();
    morse_long();
    morse_long();
    morse_divide_letter();
    morse_short();
    morse_short();
    morse_short();
    morse_long();
    morse_divide_letter();
    morse_short();
    morse_space();

    morse_long();
    morse_short();
    morse_long();
    morse_long();
    morse_divide_letter();
    morse_long();
    morse_long();
    morse_long();
    morse_divide_letter();
    morse_short();
    morse_short();
    morse_long();
    button_pressed = false;
  }
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_cpu();
}

void morse_short()
{
  digitalWrite(ATTINY_LED, HIGH);
  delay(morse_duration_short);
  digitalWrite(ATTINY_LED, LOW);
  delay(morse_duration_short);
}

void morse_long()
{
  digitalWrite(ATTINY_LED, HIGH);
  delay(morse_duration_long);
  digitalWrite(ATTINY_LED, LOW);
  delay(morse_duration_short);
}

void morse_divide_letter()
{
  delay(morse_duration_letter);
}

void morse_space()
{
  delay(morse_duration_space);
}