#pragma once
#include <math.h>

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#define clamp(a, min, max) \
	((a) < (min) ? (min) : ((a) > (max) ? (max) : (a)))
#define mix(a, b, v) \
	(((a) * (v)) + ((b) * ((1) - (v))))
