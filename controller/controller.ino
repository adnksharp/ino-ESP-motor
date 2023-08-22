#include "config.h"
#include <Ticker.h>

short c = 0; 

Ticker prints;

extern void motorcWrite(short val);

void serialEvent()
{
	String s = Serial.readString();
	if (s.indexOf("restart") != -1)
		ESP.restart();
}

void setup()
{
	Serial.begin(115200);
	ledcSetup(CHANNEL1, FREQUENCY, RESOLUTIONS);
	ledcAttachPin(M1, CHANNEL1);
	ledcSetup(CHANNEL2, FREQUENCY, RESOLUTIONS);
	ledcAttachPin(M2, CHANNEL2);

	prints.attach(0.1, []() {
		long p = millis() / 100;
		Serial.println(String(float(p) / 10) + "," + String(float(c - 255) * 12 / 255.0));
	});
}

void loop()
{
	c = map(analogRead(S0), 0, 4095, 0, 510);
	motorcWrite(c);
}
