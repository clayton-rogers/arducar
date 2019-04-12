#include <Arduino.h>

static int PIN_TRIG = 0;
static int PIN_ECHO = 0;

static const double SPEED_OF_SOUND = 346.0; // m/s
// Might either need a correction factor of modify the above to
// get closer to perfect results.

void RANGE_init(int pin_trig, int pin_echo) {
	PIN_TRIG = pin_trig;
	PIN_ECHO = pin_echo;

	pinMode(PIN_TRIG, OUTPUT);
	pinMode(PIN_ECHO, INPUT );

	digitalWrite(PIN_TRIG, LOW);
}

double RANGE_get() {
	// Trig pin should be set high for 10 us.
	// This causes a sonic burst to be emitted.
	// Then a pulse is generated on the echo line
	// proportional to the time of flight.

	digitalWrite(PIN_TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(PIN_TRIG, LOW);

	unsigned long pulse_length_micro = pulseIn(PIN_ECHO, HIGH, 40000); // microsecond timeouts
	if (pulse_length_micro == 0) {
		return 0.0;
	}

	double pulse_length = static_cast<double> (pulse_length_micro) / 1000000;

	// Because the pulse has to go there an back.
	pulse_length /= 2.0;

	double distance = SPEED_OF_SOUND * pulse_length;

	return distance;
}
