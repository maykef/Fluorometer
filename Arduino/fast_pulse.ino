#define OUTPUT_PIN 13  // Using pin 13 (PORTB5) for output

void setup() {
  DDRB |= (1 << DDB5);  // Set pin 13 as output
}

void pulse_2us() {
  PORTB |= (1 << PORTB5);  // Set pin high
  __asm__ __volatile__ (
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    ::
  );
  PORTB &= ~(1 << PORTB5);  // Set pin low
}

void loop() {
  // First 2-microsecond pulse
  pulse_2us();

  // 300-microsecond delay
  delayMicroseconds(300);

  // Second 2-microsecond pulse
  pulse_2us();

  // Wait before next pair of pulses (adjust as needed)
  delay(1000);
}
