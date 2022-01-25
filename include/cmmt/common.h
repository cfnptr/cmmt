// Copyright 2021-2022 Nikita Fediuchin. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdint.h>

#if !defined(CMMT_INT32) && !defined(CMMT_INT64)
#define CMMT_INT32 1
#endif

#if !defined(CMMT_FLOAT32) && !defined(CMMT_FLOAT64)
#define CMMT_FLOAT32 1
#endif

#if CMMT_INT32
typedef int32_t cmmt_int_t;
#elif CMMT_INT64
typedef int64_t cmmt_int_t;
#endif

#if CMMT_FLOAT32
typedef float cmmt_float_t;
#define cmmtSqrt(x) sqrtf(x)
#define cmmtPow(x, y) powf(x, y)
#define cmmtSin(x) sinf(x)
#define cmmtAsin(x) asinf(x)
#define cmmtCos(x) cosf(x)
#define cmmtAsos(x) acosf(x)
#define cmmtTan(x) tanf(x)
#define cmmtAtan(x) atanf(x)
#define cmmtAtan2(y, x) atan2f(y, x)
#define cmmtFmin(x, y) fminf(x, y)
#define cmmtFmax(x, y) fmaxf(x, y)
// TODO: add other functions exp, log, floor, etc.
#elif CMMT_FLOAT64
typedef double cmmt_float_t;
#define cmmtSqrt(x) sqrt(x)
#define cmmtPow(x, y) pow(x, y)
#define cmmtSin(x) sin(x)
#define cmmtAsin(x) asin(x)
#define cmmtCos(x) cos(x)
#define cmmtAsos(x) acos(x)
#define cmmtTan(x) tan(x)
#define cmmtAtan(x) atan(x)
#define cmmtAtan2(y, x) atan2(y, x)
#define cmmtFmin(x, y) fmin(x, y)
#define cmmtFmax(x, y) fmax(x, y)
#endif

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
