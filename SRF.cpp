#include "SRF.h"

int srf(int ch) {
	unsigned long duration = -1;
	int distance = 0;
	switch (ch)
	{
	case 1:
		pinMode(TRIG1, OUTPUT);
		pinMode(ECHO1, INPUT);

		digitalWrite(TRIG1, LOW);
		delayMicroseconds(2);
		digitalWrite(TRIG1, HIGH);
		delayMicroseconds(10);
		digitalWrite(TRIG1, LOW);

		duration = pulseIn(ECHO1, HIGH);
		distance = duration / 29 / 2;
		if (duration == 0) {
			return 0;
		}
		else {
			return distance;
		}

	case 2:
		pinMode(TRIG2, OUTPUT);
		pinMode(ECHO2, INPUT);

		digitalWrite(TRIG2, LOW);
		delayMicroseconds(2);
		digitalWrite(TRIG2, HIGH);
		delayMicroseconds(10);
		digitalWrite(TRIG2, LOW);

		duration = pulseIn(ECHO2, HIGH);
		distance = duration / 29 / 2;
		if (duration == 0) {
			return 0;
		}
		else {
			return distance;
		}

	case 3:
		pinMode(TRIG3, OUTPUT);
		pinMode(ECHO3, INPUT);

		digitalWrite(TRIG3, LOW);
		delayMicroseconds(2);
		digitalWrite(TRIG3, HIGH);
		delayMicroseconds(10);
		digitalWrite(TRIG3, LOW);

		duration = pulseIn(ECHO3, HIGH);
		distance = duration / 29 / 2;
		if (duration == 0) {
			return 0;
		}
		else {
			return distance;
		}
	default:
		break;
	}

}