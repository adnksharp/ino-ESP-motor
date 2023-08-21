#include <Arduino.h>
#include "config.h"

byte m[] = {CHANNEL1, CHANNEL2};

void motorcWrite(short var)
{
	if (var == 255)
	{
		ledcWrite(m[0], 0);
		ledcWrite(m[1], 0);
		return;
	}
	var < 255 ? ledcWrite(m[0], 0) : ledcWrite(m[0], var - 255);
	var < 255 ? ledcWrite(m[1], 255 - var) : ledcWrite(m[1], 0);
}
