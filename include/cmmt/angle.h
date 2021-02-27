#pragma once
#include <math.h>

inline static double angleToDeg(
	double radians)
{
	return radians * (180.0 / M_PI);
}
inline static double angleToRad(
	double degrees)
{
	return degrees * (M_PI / 180.0f);
}
