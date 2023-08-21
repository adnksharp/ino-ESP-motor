#include "config.h"
#include <Ticker.h>

short c = 0; 

Ticker prints;

extern void motorcWrite(short val);

void setup()
{
	Serial.begin(115200);
	ledcSetup(CHANNEL1, FREQUENCY, RESOLUTIONS);
	ledcAttachPin(M1, CHANNEL1);
	ledcSetup(CHANNEL2, FREQUENCY, RESOLUTIONS);
	ledcAttachPin(M2, CHANNEL2);

	prints.attach(0.1, []() {
		float p = abs(c - 255) - 39;
		p = p < 0 ? 0 : map(p, 0, 216, 375, 13000) / 100.0;
		p = c - 255 < 0 ? -p : p;
		Serial.println(String(p) + "," + String(float(c - 255) * 12 / 255.0));
	});
}

void loop()
{
	c = map(analogRead(S0), 0, 4095, 0, 510);
	motorcWrite(c);
}
