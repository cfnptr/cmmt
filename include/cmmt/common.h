#pragma once
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define clamp(a, min, max) \
	((a) < (min) ? (min) : ((a) > (max) ? (max) : (a)))
#define mix(a, b, v) \
	(((a) * (v)) + ((b) * ((1) - (v))))
