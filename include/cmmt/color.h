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
#include "cmmt/vector.h"
#include <assert.h>

typedef struct SrgbColor
{
	uint8_t r, g, b, a;
} SrgbColor;
typedef struct LinearColor
{
	cmmt_float_t r, g, b, a;
} LinearColor;

static const SrgbColor zeroSrgbColor = {
	0, 0, 0, 0,
};
static const SrgbColor blackSrgbColor = {
	0, 0, 0, 255,
};
static const SrgbColor whiteSrgbColor = {
	255, 255, 255, 255,
};

static const LinearColor zeroLinearColor = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
};
static const LinearColor blackLinearColor = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)1.0,
};
static const LinearColor whiteLinearColor = {
	(cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0,
};

inline static SrgbColor srgbColor(
	uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SrgbColor color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return color;
}
inline static SrgbColor valSrgbColor(uint8_t value)
{
	SrgbColor color;
	color.r = value;
	color.g = value;
	color.b = value;
	color.a = value;
	return color;
}

inline static LinearColor linearColor(
	cmmt_float_t r, cmmt_float_t g, cmmt_float_t b, cmmt_float_t a)
{
	LinearColor color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return color;
}
inline static LinearColor valueLinearColor(cmmt_float_t value)
{
	LinearColor color;
	color.r = value;
	color.g = value;
	color.b = value;
	color.a = value;
	return color;
}

inline static LinearColor addLinearColor(
	LinearColor a, LinearColor b)
{
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	a.a += b.a;
	return a;
}
inline static LinearColor subLinearColor(
	LinearColor a, LinearColor b)
{
	a.r -= b.r;
	a.g -= b.g;
	a.b -= b.b;
	a.a -= b.a;
	return a;
}
inline static LinearColor mulLinearColor(
	LinearColor a, LinearColor b)
{
	a.r *= b.r;
	a.g *= b.g;
	a.b *= b.b;
	a.a *= b.a;
	return a;
}
inline static LinearColor divLinearColor(
	LinearColor a, LinearColor b)
{
	a.r /= b.r;
	a.g /= b.g;
	a.b /= b.b;
	a.a /= b.a;
	return a;
}

inline static LinearColor mixLinearColor(
	LinearColor a, LinearColor b, LinearColor v)
{
	a.r = (a.r * ((cmmt_float_t)1.0 - v.r)) + (b.r * v.r);
	a.g = (a.g * ((cmmt_float_t)1.0 - v.g)) + (b.g * v.g);
	a.b = (a.b * ((cmmt_float_t)1.0 - v.b)) + (b.b * v.b);
	a.a = (a.a * ((cmmt_float_t)1.0 - v.a)) + (b.a * v.a);
	return a;
}
inline static LinearColor mixValLinearColor(
	LinearColor a, LinearColor b, cmmt_float_t v)
{
	cmmt_float_t n = (cmmt_float_t)1.0 - v;
	a.r = (a.r * n) + (b.r * v);
	a.g = (a.g * n) + (b.g * v);
	a.b = (a.b * n) + (b.b * v);
	a.a = (a.a * n) + (b.a * v);
	return a;
}

inline static LinearColor addValLinearColor(
	LinearColor linearColor, cmmt_float_t value)
{
	linearColor.r += value;
	linearColor.g += value;
	linearColor.b += value;
	linearColor.a += value;
	return linearColor;
}
inline static LinearColor subValLinearColor(
	LinearColor linearColor, cmmt_float_t value)
{
	linearColor.r -= value;
	linearColor.g -= value;
	linearColor.b -= value;
	linearColor.a -= value;
	return linearColor;
}
inline static LinearColor mulValLinearColor(
	LinearColor linearColor, cmmt_float_t value)
{
	linearColor.r *= value;
	linearColor.g *= value;
	linearColor.b *= value;
	linearColor.a *= value;
	return linearColor;
}
inline static LinearColor divValLinearColor(
	LinearColor linearColor, cmmt_float_t value)
{
	linearColor.r /= value;
	linearColor.g /= value;
	linearColor.b /= value;
	linearColor.a /= value;
	return linearColor;
}

inline static cmmt_float_t srgbToLinearValue(uint8_t srgbValue)
{
	const cmmt_float_t multiplier = (cmmt_float_t)(1.0 / 255.0);
	cmmt_float_t value = (cmmt_float_t)srgbValue * multiplier;

	return value <= (cmmt_float_t)0.04045 ?
		value / (cmmt_float_t)12.92 :
		cmmtPow((value + (cmmt_float_t)0.055) / (cmmt_float_t)1.055, (cmmt_float_t)2.4);
}
inline static uint8_t linearToSrgbValueF(cmmt_float_t linearValue)
{
	assert(linearValue >= 0.0);
	assert(linearValue <= 1.0);

	const cmmt_float_t power = (cmmt_float_t)(1.0 / 2.4);

	return linearValue <= (cmmt_float_t)0.0031308 ?
		(uint8_t)(linearValue * (cmmt_float_t)12.92) :
		(uint8_t)((cmmt_float_t)1.055 * cmmtPow(linearValue, power) - (cmmt_float_t)0.055);
}

inline static LinearColor srgbToLinearColor(SrgbColor srgbColor)
{
	const cmmt_float_t multiplier = (cmmt_float_t)(1.0 / 255.0);

	return linearColor(
		srgbToLinearValue(srgbColor.r),
		srgbToLinearValue(srgbColor.g),
		srgbToLinearValue(srgbColor.b),
		(cmmt_float_t)srgbColor.a * multiplier);
}
inline static SrgbColor linearToSrgbColor(LinearColor linearColor)
{
	assert(linearColor.a >= 0.0);
	assert(linearColor.a <= 1.0);

	return srgbColor(
		linearToSrgbValueF(linearColor.r),
		linearToSrgbValueF(linearColor.g),
		linearToSrgbValueF(linearColor.b),
		(uint8_t)(linearColor.a * (cmmt_float_t)255.0));
}
