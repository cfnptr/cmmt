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
#include "cmmt/common.h"

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define LEFT_AXIS_VALUE (-1)
#define RIGHT_AXIS_VALUE 1
#define BOTTOM_AXIS_VALUE (-1)
#define TOP_AXIS_VALUE 1
#define BACK_AXIS_VALUE (-1)
#define FRONT_AXIS_VALUE 1

typedef struct Vec2F
{
	cmmt_float_t x, y;
} Vec2F;
typedef struct Vec3F
{
	cmmt_float_t x, y, z;
} Vec3F;
typedef struct Vec4F
{
	cmmt_float_t x, y, z, w;
} Vec4F;

typedef struct Vec2I
{
	cmmt_int_t x, y;
} Vec2I;
typedef struct Vec3I
{
	cmmt_int_t x, y, z;
} Vec3I;
typedef struct Vec4I
{
	cmmt_int_t x, y, z, w;
} Vec4I;

static const Vec2F zeroVec2F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0,
};
static const Vec2F oneVec2F = {
	(cmmt_float_t)1.0, (cmmt_float_t)1.0,
};
static const Vec2F minOneVec2F = {
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
};
static const Vec2F infVec2F = {
	INFINITY, INFINITY,
};
static const Vec2F minInfVec2F = {
	-INFINITY, -INFINITY,
};

static const Vec3F zeroVec3F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
};
static const Vec3F oneVec3F = {
	(cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0,
};
static const Vec3F minOneVec3F = {
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
};
static const Vec3F infVec3F = {
	INFINITY, INFINITY, INFINITY,
};
static const Vec3F minInfVec3F = {
	-INFINITY, -INFINITY, -INFINITY,
};
static const Vec3F leftVec3F = {
	LEFT_AXIS_VALUE, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
};
static const Vec3F rightVec3F = {
	RIGHT_AXIS_VALUE, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
};
static const Vec3F bottomVec3F = {
	(cmmt_float_t)0.0, BOTTOM_AXIS_VALUE, (cmmt_float_t)0.0,
};
static const Vec3F topVec3F = {
	(cmmt_float_t)0.0, TOP_AXIS_VALUE, (cmmt_float_t)0.0,
};
static const Vec3F backVec3F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, BACK_AXIS_VALUE,
};
static const Vec3F frontVec3F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, FRONT_AXIS_VALUE
};

static const Vec4F zeroVec4F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0,
};
static const Vec4F oneVec4F = {
	(cmmt_float_t)1.0, (cmmt_float_t)1.0,
	(cmmt_float_t)1.0, (cmmt_float_t)1.0,
};
static const Vec4F minOneVec4F = {
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
};
static const Vec4F infVec4F = {
	INFINITY, INFINITY, INFINITY, INFINITY,
};
static const Vec4F minInfVec4F = {
	-INFINITY, -INFINITY, -INFINITY, -INFINITY,
};

static const Vec2I zeroVec2I = {
	0, 0,
};
static const Vec2I oneVec2I = {
	1, 1,
};
static const Vec2I minOneVec2I = {
	-1, -1,
};
static const Vec2I minVec2I = {
	INT32_MIN, INT32_MIN,
};
static const Vec2I maxVec2I = {
	INT32_MAX, INT32_MAX,
};

static const Vec3I zeroVec3I = {
	0, 0, 0,
};
static const Vec3I oneVec3I = {
	1, 1, 1,
};
static const Vec3I minOneVec3I = {
	-1, -1, -1,
};
static const Vec3I minVec3I = {
	INT32_MIN, INT32_MIN, INT32_MIN,
};
static const Vec3I maxVec3I = {
	INT32_MAX, INT32_MAX, INT32_MAX,
};
static const Vec3I leftVec3I = {
	LEFT_AXIS_VALUE, 0, 0,
};
static const Vec3I rightVec3I = {
	RIGHT_AXIS_VALUE, 0, 0,
};
static const Vec3I bottomVec3I = {
	0, BOTTOM_AXIS_VALUE, 0,
};
static const Vec3I topVec3I = {
	0, TOP_AXIS_VALUE, 0,
};
static const Vec3I backVec3I = {
	0, 0, BACK_AXIS_VALUE,
};
static const Vec3I frontVec3I = {
	0, 0, FRONT_AXIS_VALUE
};

static const Vec4I zeroVec4I = {
	0, 0, 0, 0,
};
static const Vec4I oneVec4I = {
	1, 1, 1, 1,
};
static const Vec4I minOneVec4I = {
	-1, -1, -1, -1,
};
static const Vec4I minVec4I = {
	INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN,
};
static const Vec4I maxVec4I = {
	INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX,
};

inline static Vec2F vec2F(cmmt_float_t x, cmmt_float_t y)
{
	Vec2F vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static Vec2F valVec2F(cmmt_float_t value)
{
	Vec2F vector;
	vector.x = value;
	vector.y = value;
	return vector;
}

inline static Vec2F addVec2F(Vec2F a, Vec2F b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static Vec2F subVec2F(Vec2F a, Vec2F b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static Vec2F mulVec2F(Vec2F a, Vec2F b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static Vec2F divVec2F(Vec2F a, Vec2F b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static Vec2F addValVec2F(Vec2F vector, cmmt_float_t value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static Vec2F subValVec2F(Vec2F vector, cmmt_float_t value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static Vec2F mulValVec2F(Vec2F vector, cmmt_float_t value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static Vec2F divValVec2F(Vec2F vector, cmmt_float_t value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2F(Vec2F a, Vec2F b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}
inline static Vec2F negVec2F(Vec2F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}
inline static cmmt_float_t dotVec2F(Vec2F a, Vec2F b)
{
	return
		a.x * b.x +
		a.y * b.y;
}
inline static cmmt_float_t lenVec2F(Vec2F vector)
{
	return cmmtSqrt(
		vector.x * vector.x +
		vector.y * vector.y);
}
inline static cmmt_float_t distPowVec2F(Vec2F a, Vec2F b)
{
	return
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y);
}
inline static cmmt_float_t distVec2F(Vec2F a, Vec2F b)
{
	return cmmtSqrt(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y));
}
inline static Vec2F normVec2F(Vec2F vector)
{
	cmmt_float_t length = cmmtSqrt(
		vector.x * vector.x +
		vector.y * vector.y);
	assert(length > (cmmt_float_t)0.0);

	vector.x /= length;
	vector.y /= length;
	return vector;
}
inline static Vec2F reflVec2F(Vec2F vector, Vec2F normal)
{
	cmmt_float_t dot =
		(normal.x * vector.x +
		normal.y * vector.y) * (cmmt_float_t)2.0;

	vector.x -= normal.x * dot;
	vector.y -= normal.y * dot;
	return vector;
}
inline static Vec2F mixValVec2F(Vec2F a, Vec2F b, cmmt_float_t v)
{
	cmmt_float_t n = (cmmt_float_t)1.0 - v;
	a.x = (a.x * n) + (b.x * v);
	a.y = (a.y * n) + (b.y * v);
	return a;
}
inline static Vec2F mixVec2F(Vec2F a, Vec2F b, Vec2F v)
{
	a.x = mix(a.x, b.x, v.x);
	a.y = mix(a.y, b.y, v.y);
	return a;
}
inline static Vec2F lerpVec2F(Vec2F a, Vec2F b, Vec2F v)
{
	a.x = lerp(a.x, b.x, v.x);
	a.y = lerp(a.y, b.y, v.y);
	return a;
}
inline static Vec2F lerpValVec2F(Vec2F a, Vec2F b, cmmt_float_t v)
{
	a.x = lerp(a.x, b.x, v);
	a.y = lerp(a.y, b.y, v);
	return a;
}

inline static Vec3F vec3F(cmmt_float_t x, cmmt_float_t y, cmmt_float_t z)
{
	Vec3F vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static Vec3F valVec3F(cmmt_float_t value)
{
	Vec3F vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}

inline static Vec3F addVec3F(Vec3F a, Vec3F b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static Vec3F subVec3F(Vec3F a, Vec3F b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static Vec3F mulVec3F(Vec3F a, Vec3F b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static Vec3F divVec3F(Vec3F a, Vec3F b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static Vec3F addValVec3F(Vec3F vector, cmmt_float_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static Vec3F subValVec3F(Vec3F vector, cmmt_float_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static Vec3F mulValVec3F(Vec3F vector, cmmt_float_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static Vec3F divValVec3F(Vec3F vector, cmmt_float_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3F(Vec3F a, Vec3F b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}
inline static Vec3F negVec3F(Vec3F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	return vector;
}
inline static cmmt_float_t dotVec3F(Vec3F a, Vec3F b)
{
	return
		(a.x * b.x) +
		(a.y * b.y) +
		(a.z * b.z);
}
inline static Vec3F crossVec3F(Vec3F a, Vec3F b)
{
	Vec3F vector;
	vector.x = a.y * b.z - a.z * b.y;
	vector.y = a.z * b.x - a.x * b.z;
	vector.z = a.x * b.y - a.y * b.x;
	return vector;
}
inline static cmmt_float_t lenVec3F(Vec3F vector)
{
	return cmmtSqrt(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z);
}
inline static cmmt_float_t distPowVec3F(Vec3F a, Vec3F b)
{
	return
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z);
}
inline static cmmt_float_t distVec3F(Vec3F a, Vec3F b)
{
	return cmmtSqrt(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z));
}
inline static Vec3F normVec3F(Vec3F vector)
{
	cmmt_float_t length = cmmtSqrt(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z);
	assert(length > (cmmt_float_t)0.0);

	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	return vector;
}
inline static Vec3F reflVec3F(Vec3F vector, Vec3F normal)
{
	cmmt_float_t dot =
		(normal.x * vector.x +
		normal.y * vector.y +
		normal.z * vector.z) * (cmmt_float_t)2.0;

	vector.x -= normal.x * dot;
	vector.y -= normal.y * dot;
	vector.z -= normal.z * dot;
	return vector;
}
inline static Vec3F mixValVec3F(Vec3F a, Vec3F b, cmmt_float_t v)
{
	cmmt_float_t n = (cmmt_float_t)1.0 - v;
	a.x = (a.x * n) + (b.x * v);
	a.y = (a.y * n) + (b.y * v);
	a.z = (a.z * n) + (b.z * v);
	return a;
}
inline static Vec3F mixVec3F(Vec3F a, Vec3F b, Vec3F v)
{
	a.x = mix(a.x, b.x, v.x);
	a.y = mix(a.y, b.y, v.y);
	a.z = mix(a.z, b.z, v.z);
	return a;
}
inline static Vec3F lerpVec3F(Vec3F a, Vec3F b, Vec3F v)
{
	a.x = lerp(a.x, b.x, v.x);
	a.y = lerp(a.y, b.y, v.y);
	a.z = lerp(a.z, b.z, v.z);
	return a;
}
inline static Vec3F lerpValVec3F(Vec3F a, Vec3F b, cmmt_float_t v)
{
	a.x = lerp(a.x, b.x, v);
	a.y = lerp(a.y, b.y, v);
	a.z = lerp(a.z, b.z, v);
	return a;
}

inline static Vec4F vec4F(cmmt_float_t x, cmmt_float_t y, cmmt_float_t z, cmmt_float_t w)
{
	Vec4F vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static Vec4F valVec4F(cmmt_float_t value)
{
	Vec4F vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}

inline static Vec4F addVec4F(Vec4F a, Vec4F b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static Vec4F subVec4F(Vec4F a, Vec4F b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static Vec4F mulVec4F(Vec4F a, Vec4F b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static Vec4F divVec4F(Vec4F a, Vec4F b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static Vec4F addValVec4F(Vec4F vector, cmmt_float_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static Vec4F subValVec4F(Vec4F vector, cmmt_float_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static Vec4F mulValVec4F(Vec4F vector, cmmt_float_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static Vec4F divValVec4F(Vec4F vector, cmmt_float_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4F(Vec4F a, Vec4F b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
inline static Vec4F negVec4F(Vec4F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	vector.w = -vector.w;
	return vector;
}
inline static cmmt_float_t dotVec4F(Vec4F a, Vec4F b)
{
	return
		a.x * b.x +
		a.y * b.y +
		a.z * b.z +
		a.w * b.w;
}
inline static cmmt_float_t lenVec4F(Vec4F vector)
{
	return cmmtSqrt(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z +
		vector.w * vector.w);
}
inline static cmmt_float_t distPowVec4F(Vec4F a, Vec4F b)
{
	return
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z) +
		(a.w - b.w) * (a.w - b.w);
}
inline static cmmt_float_t distVec4F(Vec4F a, Vec4F b)
{
	return cmmtSqrt(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z) +
		(a.w - b.w) * (a.w - b.w));
}
inline static Vec4F normVec4F(Vec4F vector)
{
	cmmt_float_t length = cmmtSqrt(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z +
		vector.w * vector.w);
	assert(length > (cmmt_float_t)0.0);

	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	vector.w /= length;
	return vector;
}
inline static Vec4F reflVec4F(Vec4F vector, Vec4F normal)
{
	cmmt_float_t dot =
		(normal.x * vector.x +
		normal.y * vector.y +
		normal.z * vector.z +
		normal.w * vector.w) * (cmmt_float_t)2.0;

	vector.x -= normal.x * dot;
	vector.y -= normal.y * dot;
	vector.z -= normal.z * dot;
	vector.w -= normal.w * dot;
	return vector;
}
inline static Vec4F mixValVec4F(Vec4F a, Vec4F b, cmmt_float_t v)
{
	cmmt_float_t n = (cmmt_float_t)1.0 - v;
	a.x = (a.x * n) + (b.x * v);
	a.y = (a.y * n) + (b.y * v);
	a.z = (a.z * n) + (b.z * v);
	a.w = (a.w * n) + (b.w * v);
	return a;
}
inline static Vec4F mixVec4F(Vec4F a, Vec4F b, Vec4F v)
{
	a.x = mix(a.x, b.x, v.x);
	a.y = mix(a.y, b.y, v.y);
	a.z = mix(a.z, b.z, v.z);
	a.w = mix(a.w, b.w, v.w);
	return a;
}
inline static Vec4F lerpValVec4F(Vec4F a, Vec4F b, cmmt_float_t v)
{
	a.x = lerp(a.x, b.x, v);
	a.y = lerp(a.y, b.y, v);
	a.z = lerp(a.z, b.z, v);
	a.w = lerp(a.w, b.w, v);
	return a;
}
inline static Vec4F lerpVec4F(Vec4F a, Vec4F b, Vec4F v)
{
	a.x = lerp(a.x, b.x, v.x);
	a.y = lerp(a.y, b.y, v.y);
	a.z = lerp(a.z, b.z, v.z);
	a.w = lerp(a.w, b.w, v.w);
	return a;
}

inline static Vec2I vec2I(cmmt_int_t x, cmmt_int_t y)
{
	Vec2I vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static Vec2I valVec2I(cmmt_int_t value)
{
	Vec2I vector;
	vector.x = value;
	vector.y = value;
	return vector;
}

inline static Vec2I addVec2I(Vec2I a, Vec2I b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static Vec2I subVec2I(Vec2I a, Vec2I b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static Vec2I mulVec2I(Vec2I a, Vec2I b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static Vec2I divVec2I(Vec2I a, Vec2I b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}
inline static Vec2I andVec2I(Vec2I a, Vec2I b)
{
	a.x &= b.x;
	a.y &= b.y;
	return a;
}
inline static Vec2I orVec2I(Vec2I a, Vec2I b)
{
	a.x |= b.x;
	a.y |= b.y;
	return a;
}
inline static Vec2I xorVec2I(Vec2I a, Vec2I b)
{
	a.x ^= b.x;
	a.y ^= b.y;
	return a;
}

inline static Vec2I addValVec2I(Vec2I vector, cmmt_int_t value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static Vec2I subValVec2I(Vec2I vector, cmmt_int_t value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static Vec2I mulValVec2I(Vec2I vector, cmmt_int_t value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static Vec2I divValVec2I(Vec2I vector, cmmt_int_t value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}
inline static Vec2I andValVec2I(Vec2I vector, cmmt_int_t value)
{
	vector.x &= value;
	vector.y &= value;
	return vector;
}
inline static Vec2I orValVec2I(Vec2I vector, cmmt_int_t value)
{
	vector.x |= value;
	vector.y |= value;
	return vector;
}
inline static Vec2I xorValVec2I(Vec2I vector, cmmt_int_t value)
{
	vector.x ^= value;
	vector.y ^= value;
	return vector;
}

inline static bool compVec2I(Vec2I a, Vec2I b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}
inline static Vec2I negVec2I(Vec2I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}
inline static Vec2I notVec2I(Vec2I vector)
{
	vector.x = !vector.x;
	vector.y = !vector.y;
	return vector;
}
inline static cmmt_float_t dotVec2I(Vec2I a, Vec2I b)
{
	return (cmmt_float_t)(
		a.x * b.x +
		a.y * b.y);
}
inline static cmmt_float_t lenVec2I(Vec2I vector)
{
	return cmmtSqrt((cmmt_float_t)(
		vector.x * vector.x +
		vector.y * vector.y));
}
inline static cmmt_float_t distPowVec2I(Vec2I a, Vec2I b)
{
	return (cmmt_float_t)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y));
}
inline static cmmt_float_t distVec2I(Vec2I a, Vec2I b)
{
	return cmmtSqrt((cmmt_float_t)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y)));
}
inline static Vec2F normVec2I(Vec2I vector)
{
	cmmt_float_t length = cmmtSqrt((cmmt_float_t)(
		vector.x * vector.x +
		vector.y * vector.y));
	assert(length > (cmmt_float_t)0.0);

	Vec2F result;
	result.x = (cmmt_float_t)vector.x / length;
	result.y = (cmmt_float_t)vector.y / length;
	return result;
}
inline static Vec2F reflVec2I(Vec2I vector, Vec2I normal)
{
	cmmt_float_t dot = (cmmt_float_t)(
		normal.x * vector.x +
		normal.y * vector.y) * (cmmt_float_t)2.0;

	Vec2F result;
	result.x = (cmmt_float_t)vector.x - (cmmt_float_t)normal.x * dot;
	result.y = (cmmt_float_t)vector.y - (cmmt_float_t)normal.y * dot;
	return result;
}

inline static Vec3I vec3I(cmmt_int_t x, cmmt_int_t y, cmmt_int_t z)
{
	Vec3I vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static Vec3I valVec3I(cmmt_int_t value)
{
	Vec3I vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}

inline static Vec3I addVec3I(Vec3I a, Vec3I b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static Vec3I subVec3I(Vec3I a, Vec3I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static Vec3I mulVec3I(Vec3I a, Vec3I b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static Vec3I divVec3I(Vec3I a, Vec3I b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}
inline static Vec3I andVec3I(Vec3I a, Vec3I b)
{
	a.x &= b.x;
	a.y &= b.y;
	a.z &= b.z;
	return a;
}
inline static Vec3I orVec3I(Vec3I a, Vec3I b)
{
	a.x |= b.x;
	a.y |= b.y;
	a.z |= b.z;
	return a;
}
inline static Vec3I xorVec3I(Vec3I a, Vec3I b)
{
	a.x ^= b.x;
	a.y ^= b.y;
	a.z ^= b.z;
	return a;
}

inline static Vec3I addValVec3I(Vec3I vector, cmmt_int_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static Vec3I subValVec3I(Vec3I vector, cmmt_int_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static Vec3I mulValVec3I(Vec3I vector, cmmt_int_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static Vec3I divValVec3I(Vec3I vector, cmmt_int_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}
inline static Vec3I andValVec3I(Vec3I vector, cmmt_int_t value)
{
	vector.x &= value;
	vector.y &= value;
	vector.z &= value;
	return vector;
}
inline static Vec3I orValVec3I(Vec3I vector, cmmt_int_t value)
{
	vector.x |= value;
	vector.y |= value;
	vector.z |= value;
	return vector;
}
inline static Vec3I xorValVec3I(Vec3I vector, cmmt_int_t value)
{
	vector.x ^= value;
	vector.y ^= value;
	vector.z ^= value;
	return vector;
}

inline static bool compVec3I(Vec3I a, Vec3I b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}
inline static Vec3I negVec3I(Vec3I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	return vector;
}
inline static Vec3I notVec3I(Vec3I vector)
{
	vector.x = !vector.x;
	vector.y = !vector.y;
	vector.z = !vector.z;
	return vector;
}
inline static cmmt_float_t dotVec3I(Vec3I a, Vec3I b)
{
	return (cmmt_float_t)(
		a.x * b.x +
		a.y * b.y +
		a.z * b.z);
}
inline static cmmt_float_t lenVec3I(Vec3I vector)
{
	return cmmtSqrt((cmmt_float_t)(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z));
}
inline static cmmt_float_t distPowVec3I(Vec3I a, Vec3I b)
{
	return (cmmt_float_t)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z));
}
inline static cmmt_float_t distVec3I(Vec3I a,Vec3I b)
{
	return cmmtSqrt((cmmt_float_t)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z)));
}
inline static Vec3F normVec3I(Vec3I vector)
{
	cmmt_float_t length = cmmtSqrt((cmmt_float_t)(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z));
	assert(length > (cmmt_float_t)0.0);

	Vec3F result;
	result.x = (cmmt_float_t)vector.x / length;
	result.y = (cmmt_float_t)vector.y / length;
	result.z = (cmmt_float_t)vector.z / length;
	return result;
}
inline static Vec3F reflVec3I(Vec3I vector, Vec3I normal)
{
	cmmt_float_t dot = (cmmt_float_t)(
		normal.x * vector.x +
		normal.y * vector.y +
		normal.z * vector.z) * (cmmt_float_t)2.0;

	Vec3F result;
	result.x = (cmmt_float_t)vector.x - (cmmt_float_t)normal.x * dot;
	result.y = (cmmt_float_t)vector.y - (cmmt_float_t)normal.y * dot;
	result.z = (cmmt_float_t)vector.z - (cmmt_float_t)normal.z * dot;
	return result;
}

inline static Vec4I vec4I(cmmt_int_t x, cmmt_int_t y, cmmt_int_t z, cmmt_int_t w)
{
	Vec4I vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static Vec4I valVec4I(cmmt_int_t value)
{
	Vec4I vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}

inline static Vec4I addVec4I(Vec4I a, Vec4I b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static Vec4I subVec4I(Vec4I a, Vec4I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static Vec4I mulVec4I(Vec4I a, Vec4I b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static Vec4I divVec4I(Vec4I a, Vec4I b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}
inline static Vec4I andVec4I(Vec4I a, Vec4I b)
{
	a.x &= b.x;
	a.y &= b.y;
	a.z &= b.z;
	a.w &= b.w;
	return a;
}
inline static Vec4I orVec4I(Vec4I a, Vec4I b)
{
	a.x |= b.x;
	a.y |= b.y;
	a.z |= b.z;
	a.w |= b.w;
	return a;
}
inline static Vec4I xorVec4I(Vec4I a, Vec4I b)
{
	a.x ^= b.x;
	a.y ^= b.y;
	a.z ^= b.z;
	a.w ^= b.w;
	return a;
}

inline static Vec4I addValVec4I(Vec4I vector, cmmt_int_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static Vec4I subValVec4I(Vec4I vector, cmmt_int_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static Vec4I mulValVec4I(Vec4I vector, cmmt_int_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static Vec4I divValVec4I(Vec4I vector, cmmt_int_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}
inline static Vec4I andValVec4I(Vec4I vector, cmmt_int_t value)
{
	vector.x &= value;
	vector.y &= value;
	vector.z &= value;
	vector.w &= value;
	return vector;
}
inline static Vec4I orValVec4I(Vec4I vector, cmmt_int_t value)
{
	vector.x |= value;
	vector.y |= value;
	vector.z |= value;
	vector.w |= value;
	return vector;
}
inline static Vec4I xorValVec4I(Vec4I vector, cmmt_int_t value)
{
	vector.x ^= value;
	vector.y ^= value;
	vector.z ^= value;
	vector.w ^= value;
	return vector;
}

inline static bool compVec4I(Vec4I a, Vec4I b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
inline static Vec4I negVec4I(Vec4I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	vector.w = -vector.w;
	return vector;
}
inline static Vec4I notVec4I(Vec4I vector)
{
	vector.x = !vector.x;
	vector.y = !vector.y;
	vector.z = !vector.z;
	vector.w = !vector.w;
	return vector;
}
inline static cmmt_float_t dotVec4I(Vec4I a, Vec4I b)
{
	return (cmmt_float_t)(
		a.x * b.x +
		a.y * b.y +
		a.z * b.z +
		a.w * b.w);
}
inline static cmmt_float_t lenVec4I(Vec4I vector)
{
	return cmmtSqrt((cmmt_float_t)(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z +
		vector.w * vector.w));
}
inline static cmmt_float_t distPowVec4I(Vec4I a, Vec4I b)
{
	return (cmmt_float_t)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z) +
		(a.w - b.w) * (a.w - b.w));
}
inline static cmmt_float_t distVec4I(Vec4I a, Vec4I b)
{
	return cmmtSqrt((cmmt_float_t)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z) +
		(a.w - b.w) * (a.w - b.w)));
}
inline static Vec4F normVec4I(Vec4I vector)
{
	cmmt_float_t length = cmmtSqrt((cmmt_float_t)(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z +
		vector.w * vector.w));
	assert(length > (cmmt_float_t)0.0);

	Vec4F result;
	result.x = (cmmt_float_t)vector.x / length;
	result.y = (cmmt_float_t)vector.y / length;
	result.z = (cmmt_float_t)vector.z / length;
	result.w = (cmmt_float_t)vector.w / length;
	return result;
}
inline static Vec4F reflVec4I(Vec4I vector, Vec4I normal)
{
	cmmt_float_t dot = (cmmt_float_t)(
		normal.x * vector.x +
		normal.y * vector.y +
		normal.z * vector.z +
		normal.w * vector.w) * (cmmt_float_t)2.0;

	Vec4F result;
	result.x = (cmmt_float_t)vector.x - (cmmt_float_t)normal.x * dot;
	result.y = (cmmt_float_t)vector.y - (cmmt_float_t)normal.y * dot;
	result.z = (cmmt_float_t)vector.z - (cmmt_float_t)normal.z * dot;
	result.w = (cmmt_float_t)vector.w - (cmmt_float_t)normal.w * dot;
	return result;
}
