#include "ofxMod.h"

ofxMod::ofxMod(float start, float end) : m_start(mod360(start)), m_end(mod360(end)) {}

float ofxMod::mod360(float value)
{
	if (value < 0)
		value += 360;
	return fmodf(value, 360.0f);
}

float ofxMod::distanceClock(float from, float to)
{
	return mod360(mod360(to) - mod360(from));
}

float ofxMod::distanceAnticlock(float from, float to)
{
	return mod360(mod360(from) - mod360(to));
}

float ofxMod::distanceClock(float to) const
{
	if (inRange(to))
		return 0.0f;
	return distanceClock(m_end, to);
}

float ofxMod::distanceAnticlock(float to) const
{
	if (inRange(to))
		return 0.0f;
	return distanceAnticlock(m_start, to);
}

float ofxMod::distanceClock(const ofxMod & ofxMod) const
{
	return distanceClock(ofxMod.m_start);
}

float ofxMod::distanceAnticlock(const ofxMod & ofxMod) const
{
	return distanceAnticlock(ofxMod.m_end);
}

bool ofxMod::inRange(float mid) const
{
	return distanceClock(mid, m_end) <= distanceClock(m_start, m_end);
}