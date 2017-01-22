#pragma once

#include <math.h>

class ofxMod
{
public:
	float static distanceClock(float from, float to);
	float static distanceAnticlock(float from, float to);

	float m_start;
	float m_end;

	ofxMod(float start, float end);

	float distanceClock(float to) const;
	float distanceAnticlock(float to) const;
	float distanceClock(const ofxMod & arc) const;
	float distanceAnticlock(const ofxMod & arc) const;
	bool inRange(float mid) const;

private:
	float static mod360(float value);

};
