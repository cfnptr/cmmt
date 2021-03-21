#pragma once
#include <math.h>

inline static double radToDegD(
	double radians)
{
	return radians * (180.0 / M_PI);
}
inline static float radToDegF(
	float radians)
{
	return radians * (180.0f / M_PI);
}

inline static double degToRadD(
	double degrees)
{
	return degrees * (M_PI / 180.0);
}
inline static float degToRadF(
	float degrees)
{
	return degrees * (M_PI / 180.0f);
}
