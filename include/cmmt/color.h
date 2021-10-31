// Copyright 2021 Nikita Fediuchin. All rights reserved.
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
	float r, g, b, a;
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
	0.0f, 0.0f, 0.0f, 0.0f,
};
static const LinearColor blackLinearColor = {
	0.0f, 0.0f, 0.0f, 1.0f,
};
static const LinearColor whiteLinearColor = {
	1.0f, 1.0f, 1.0f, 1.0f,
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
	float r, float g, float b, float a)
{
	LinearColor color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return color;
}
inline static LinearColor valueLinearColor(float value)
{
	LinearColor color;
	color.r = value;
	color.g = value;
	color.b = value;
	color.a = value;
	return color;
}

inline static LinearColor addLinearColor(
	LinearColor a,
	LinearColor b)
{
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	a.a += b.a;
	return a;
}
inline static LinearColor subLinearColor(
	LinearColor a,
	LinearColor b)
{
	a.r -= b.r;
	a.g -= b.g;
	a.b -= b.b;
	a.a -= b.a;
	return a;
}
inline static LinearColor mulLinearColor(
	LinearColor a,
	LinearColor b)
{
	a.r *= b.r;
	a.g *= b.g;
	a.b *= b.b;
	a.a *= b.a;
	return a;
}
inline static LinearColor divLinearColor(
	LinearColor a,
	LinearColor b)
{
	a.r /= b.r;
	a.g /= b.g;
	a.b /= b.b;
	a.a /= b.a;
	return a;
}

inline static Vec2F mixLinearColor(
	Vec2F a,
	Vec2F b,
	Vec2F v)
{
	a.x = (a.x * (1.0f - v.x)) + (b.x * v.x);
	a.y = (a.y * (1.0f - v.y)) + (b.y * v.y);
	return a;
}
inline static LinearColor mixValLinearColor(
	LinearColor a,
	LinearColor b,
	float v)
{
	float n = 1.0f - v;
	a.r = (a.r * n) + (b.r * v);
	a.g = (a.g * n) + (b.g * v);
	a.b = (a.b * n) + (b.b * v);
	a.a = (a.a * n) + (b.a * v);
	return a;
}

inline static LinearColor addValLinearColor(
	LinearColor linearColor,
	float value)
{
	linearColor.r += value;
	linearColor.g += value;
	linearColor.b += value;
	linearColor.a += value;
	return linearColor;
}
inline static LinearColor subValLinearColor(
	LinearColor linearColor,
	float value)
{
	linearColor.r -= value;
	linearColor.g -= value;
	linearColor.b -= value;
	linearColor.a -= value;
	return linearColor;
}
inline static LinearColor mulValLinearColor(
	LinearColor linearColor,
	float value)
{
	linearColor.r *= value;
	linearColor.g *= value;
	linearColor.b *= value;
	linearColor.a *= value;
	return linearColor;
}
inline static LinearColor divValLinearColor(
	LinearColor linearColor,
	float value)
{
	linearColor.r /= value;
	linearColor.g /= value;
	linearColor.b /= value;
	linearColor.a /= value;
	return linearColor;
}

inline static float srgbToLinearValue(uint8_t srgbValue)
{
	const float multiplier = 1.0f / 255.0f;
	float value = (float)srgbValue * multiplier;

	return value <= 0.04045f ?
		value / 12.92f :
		powf((value + 0.055f) / 1.055f, 2.4f);
}
inline static uint8_t linearToSrgbValue(float linearValue)
{
	assert(linearValue >= 0.0);
	assert(linearValue <= 1.0);

	const float power = 1.0f / 2.4f;

	return linearValue <= 0.0031308f ?
		(uint8_t)(linearValue * 12.92f) :
		(uint8_t)(1.055f * powf(linearValue, power) - 0.055f);
}

inline static LinearColor srgbToLinearColor(SrgbColor srgbColor)
{
	const float multiplier = 1.0f / 255.0f;

	return linearColor(
		srgbToLinearValue(srgbColor.r),
		srgbToLinearValue(srgbColor.g),
		srgbToLinearValue(srgbColor.b),
		(float)srgbColor.a * multiplier);
}
inline static SrgbColor linearToSrgbColor(LinearColor linearColor)
{
	assert(linearColor.a >= 0.0);
	assert(linearColor.a <= 1.0);

	return srgbColor(
		linearToSrgbValue(linearColor.r),
		linearToSrgbValue(linearColor.g),
		linearToSrgbValue(linearColor.b),
		(uint8_t)(linearColor.a * 255.0f));
}
