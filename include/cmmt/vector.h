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
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEFT_AXIS_VALUE -1
#define RIGHT_AXIS_VALUE 1
#define BOTTOM_AXIS_VALUE -1
#define TOP_AXIS_VALUE 1
#define BACK_AXIS_VALUE -1
#define FRONT_AXIS_VALUE 1

typedef struct Vec2F
{
	float x, y;
} Vec2F;
typedef struct Vec3F
{
	float x, y, z;
} Vec3F;
typedef struct Vec4F
{
	float x, y, z, w;
} Vec4F;

typedef struct Vec2I
{
	int32_t x, y;
} Vec2I;
typedef struct Vec3I
{
	int32_t x, y, z;
} Vec3I;
typedef struct Vec4I
{
	int32_t x, y, z, w;
} Vec4I;

typedef struct Vec2U
{
	uint32_t x, y;
} Vec2U;
typedef struct Vec3U
{
	uint32_t x, y, z;
} Vec3U;
typedef struct Vec4U
{
	uint32_t x, y, z, w;
} Vec4U;

typedef struct Vec2S
{
	size_t x, y;
} Vec2S;
typedef struct Vec3S
{
	size_t x, y, z;
} Vec3S;
typedef struct Vec4S
{
	size_t x, y, z, w;
} Vec4S;

inline static Vec2F vec2F(
	float x,
	float y)
{
	Vec2F vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static Vec2F valVec2F(
	float value)
{
	Vec2F vector;
	vector.x = value;
	vector.y = value;
	return vector;
}
inline static Vec2F zeroVec2F()
{
	Vec2F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	return vector;
}
inline static Vec2F oneVec2F()
{
	Vec2F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	return vector;
}
inline static Vec2F minOneVec2F()
{
	Vec2F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	return vector;
}
inline static Vec2F infVec2F()
{
	Vec2F vector;
	vector.x = INFINITY;
	vector.y = INFINITY;
	return vector;
}
inline static Vec2F minInfVec2F()
{
	Vec2F vector;
	vector.x = -INFINITY;
	vector.y = -INFINITY;
	return vector;
}

inline static Vec2F addVec2F(
	Vec2F a,
	Vec2F b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static Vec2F subVec2F(
	Vec2F a,
	Vec2F b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static Vec2F mulVec2F(
	Vec2F a,
	Vec2F b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static Vec2F divVec2F(
	Vec2F a,
	Vec2F b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static Vec2F addValVec2F(
	Vec2F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static Vec2F subValVec2F(
	Vec2F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static Vec2F mulValVec2F(
	Vec2F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static Vec2F divValVec2F(
	Vec2F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2F(
	Vec2F a,
	Vec2F b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}
inline static Vec2F negVec2F(
	Vec2F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}
inline static float dotVec2F(
	Vec2F a,
	Vec2F b)
{
	return
		a.x * b.x +
		a.y * b.y;
}
inline static float lenVec2F(
	Vec2F vector)
{
	return sqrtf(
		vector.x * vector.x +
		vector.y * vector.y);
}
inline static float distPowVec2F(
	Vec2F a,
	Vec2F b)
{
	return
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y);
}
inline static float distVec2F(
	Vec2F a,
	Vec2F b)
{
	return sqrtf(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y));
}
inline static Vec2F normVec2F(
	Vec2F vector)
{
	float length = sqrtf(
		vector.x * vector.x +
		vector.y * vector.y);

	vector.x /= length;
	vector.y /= length;
	return vector;
}
inline static Vec2F reflVec2F(
	Vec2F vector,
	Vec2F normal)
{
	float dot =
		(normal.x * vector.x +
		normal.y * vector.y) * 2.0f;

	vector.x -= normal.x * dot;
	vector.y -= normal.y * dot;
	return vector;
}
inline static Vec2F mixValVec2F(
	Vec2F a,
	Vec2F b,
	float v)
{
	float n = 1.0f - v;

	Vec2F result;
	result.x = (a.x * n) + (b.x * v);
	result.y = (a.y * n) + (b.y * v);
	return result;
}
inline static Vec2F mixVec2F(
	Vec2F a,
	Vec2F b,
	Vec2F v)
{
	Vec2F result;
	result.x = (a.x * (1.0f - v.x)) + (b.x * v.x);
	result.y = (a.y * (1.0f - v.y)) + (b.y * v.y);
	return result;
}

inline static Vec3F vec3F(
	float x,
	float y,
	float z)
{
	Vec3F vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static Vec3F valVec3F(
	float value)
{
	Vec3F vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}
inline static Vec3F zeroVec3F()
{
	Vec3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static Vec3F oneVec3F()
{
	Vec3F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	vector.z = 1.0f;
	return vector;
}
inline static Vec3F minOneVec3F()
{
	Vec3F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	vector.z = -1.0f;
	return vector;
}
inline static Vec3F infVec3F()
{
	Vec3F vector;
	vector.x = INFINITY;
	vector.y = INFINITY;
	vector.z = INFINITY;
	return vector;
}
inline static Vec3F minInfVec3F()
{
	Vec3F vector;
	vector.x = -INFINITY;
	vector.y = -INFINITY;
	vector.z = -INFINITY;
	return vector;
}

inline static Vec3F leftVec3F()
{
	Vec3F vector;
	vector.x = LEFT_AXIS_VALUE;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static Vec3F rightVec3F()
{
	Vec3F vector;
	vector.x = RIGHT_AXIS_VALUE;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static Vec3F bottomVec3F()
{
	Vec3F vector;
	vector.x = 0.0f;
	vector.y = BOTTOM_AXIS_VALUE;
	vector.z = 0.0f;
	return vector;
}
inline static Vec3F topVec3F()
{
	Vec3F vector;
	vector.x = 0.0f;
	vector.y = TOP_AXIS_VALUE;
	vector.z = 0.0f;
	return vector;
}
inline static Vec3F backVec3F()
{
	Vec3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = BACK_AXIS_VALUE;
	return vector;
}
inline static Vec3F frontVec3F()
{
	Vec3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = FRONT_AXIS_VALUE;
	return vector;
}

inline static Vec3F addVec3F(
	Vec3F a,
	Vec3F b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static Vec3F subVec3F(
	Vec3F a,
	Vec3F b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static Vec3F mulVec3F(
	Vec3F a,
	Vec3F b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static Vec3F divVec3F(
	Vec3F a,
	Vec3F b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static Vec3F addValVec3F(
	Vec3F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static Vec3F subValVec3F(
	Vec3F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static Vec3F mulValVec3F(
	Vec3F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static Vec3F divValVec3F(
	Vec3F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3F(
	Vec3F a,
	Vec3F b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}
inline static Vec3F negVec3F(
	Vec3F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	return vector;
}
inline static float dotVec3F(
	Vec3F a,
	Vec3F b)
{
	return
		(a.x * b.x) +
		(a.y * b.y) +
		(a.z * b.z);
}
inline static Vec3F crossVec3F(
	Vec3F a,
	Vec3F b)
{
	Vec3F vector;
	vector.x = a.y * b.z - a.z * b.y;
	vector.y = a.z * b.x - a.x * b.z;
	vector.z = a.x * b.y - a.y * b.x;
	return vector;
}
inline static float lenVec3F(
	Vec3F vector)
{
	return sqrtf(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z);
}
inline static float distPowVec3F(
	Vec3F a,
	Vec3F b)
{
	return
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z);
}
inline static float distVec3F(
	Vec3F a,
	Vec3F b)
{
	return sqrtf(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z));
}
inline static Vec3F normVec3F(
	Vec3F vector)
{
	float length = sqrtf(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z);

	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	return vector;
}
inline static Vec3F reflVec3F(
	Vec3F vector,
	Vec3F normal)
{
	float dot =
		(normal.x * vector.x +
		normal.y * vector.y +
		normal.z * vector.z) * 2.0f;

	vector.x -= normal.x * dot;
	vector.y -= normal.y * dot;
	vector.z -= normal.z * dot;
	return vector;
}
inline static Vec3F mixValVec3F(
	Vec3F a,
	Vec3F b,
	float v)
{
	float n = 1.0f - v;

	Vec3F result;
	result.x = (a.x * n) + (b.x * v);
	result.y = (a.y * n) + (b.y * v);
	result.z = (a.z * n) + (b.z * v);
	return result;
}
inline static Vec3F mixVec3F(
	Vec3F a,
	Vec3F b,
	Vec3F v)
{
	Vec3F result;
	result.x = (a.x * (1.0f - v.x)) + (b.x * v.x);
	result.y = (a.y * (1.0f - v.y)) + (b.y * v.y);
	result.z = (a.z * (1.0f - v.z)) + (b.z * v.z);
	return result;
}

inline static Vec4F vec4F(
	float x,
	float y,
	float z,
	float w)
{
	Vec4F vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static Vec4F valVec4F(
	float value)
{
	Vec4F vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}
inline static Vec4F zeroVec4F()
{
	Vec4F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = 0.0f;
	vector.w = 0.0f;
	return vector;
}
inline static Vec4F oneVec4F()
{
	Vec4F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	vector.z = 1.0f;
	vector.w = 1.0f;
	return vector;
}
inline static Vec4F minOneVec4F()
{
	Vec4F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	vector.z = -1.0f;
	vector.w = -1.0f;
	return vector;
}
inline static Vec4F infVec4F()
{
	Vec4F vector;
	vector.x = INFINITY;
	vector.y = INFINITY;
	vector.z = INFINITY;
	vector.w = INFINITY;
	return vector;
}
inline static Vec4F minInfVec4F()
{
	Vec4F vector;
	vector.x = -INFINITY;
	vector.y = -INFINITY;
	vector.z = -INFINITY;
	vector.w = -INFINITY;
	return vector;
}

inline static Vec4F addVec4F(
	Vec4F a,
	Vec4F b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static Vec4F subVec4F(
	Vec4F a,
	Vec4F b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static Vec4F mulVec4F(
	Vec4F a,
	Vec4F b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static Vec4F divVec4F(
	Vec4F a,
	Vec4F b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static Vec4F addValVec4F(
	Vec4F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static Vec4F subValVec4F(
	Vec4F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static Vec4F mulValVec4F(
	Vec4F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static Vec4F divValVec4F(
	Vec4F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4F(
	Vec4F a,
	Vec4F b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
inline static Vec4F negVec4F(
	Vec4F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	vector.w = -vector.w;
	return vector;
}
inline static float dotVec4F(
	Vec4F a,
	Vec4F b)
{
	return
		a.x * b.x +
		a.y * b.y +
		a.z * b.z +
		a.w * b.w;
}
inline static float lenVec4F(
	Vec4F vector)
{
	return sqrtf(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z +
		vector.w * vector.w);
}
inline static float distPowVec4F(
	Vec4F a,
	Vec4F b)
{
	return
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z) +
		(a.w - b.w) * (a.w - b.w);
}
inline static float distVec4F(
	Vec4F a,
	Vec4F b)
{
	return sqrtf(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z) +
		(a.w - b.w) * (a.w - b.w));
}
inline static Vec4F normVec4F(
	Vec4F vector)
{
	float length = sqrtf(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z +
		vector.w * vector.w);

	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	vector.w /= length;
	return vector;
}
inline static Vec4F reflVec4F(
	Vec4F vector,
	Vec4F normal)
{
	float dot =
		(normal.x * vector.x +
		normal.y * vector.y +
		normal.z * vector.z +
		normal.w * vector.w) * 2.0f;

	vector.x -= normal.x * dot;
	vector.y -= normal.y * dot;
	vector.z -= normal.z * dot;
	vector.w -= normal.w * dot;
	return vector;
}
inline static Vec4F mixValVec4F(
	Vec4F a,
	Vec4F b,
	float v)
{
	float n = 1.0f - v;

	Vec4F result;
	result.x = (a.x * n) + (b.x * v);
	result.y = (a.y * n) + (b.y * v);
	result.z = (a.z * n) + (b.z * v);
	result.w = (a.w * n) + (b.w * v);
	return result;
}
inline static Vec4F mixVec4F(
	Vec4F a,
	Vec4F b,
	Vec4F v)
{
	Vec4F result;
	result.x = (a.x * (1.0f - v.x)) + (b.x * v.x);
	result.y = (a.y * (1.0f - v.y)) + (b.y * v.y);
	result.z = (a.z * (1.0f - v.z)) + (b.z * v.z);
	result.w = (a.w * (1.0f - v.w)) + (b.w * v.w);
	return result;
}

inline static Vec2I vec2I(
	int32_t x,
	int32_t y)
{
	Vec2I vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static Vec2I valVec2I(
	int32_t value)
{
	Vec2I vector;
	vector.x = value;
	vector.y = value;
	return vector;
}
inline static Vec2I zeroVec2I()
{
	Vec2I vector;
	vector.x = 0;
	vector.y = 0;
	return vector;
}
inline static Vec2I oneVec2I()
{
	Vec2I vector;
	vector.x = 1;
	vector.y = 1;
	return vector;
}
inline static Vec2I minOneVec2I()
{
	Vec2I vector;
	vector.x = -1;
	vector.y = -1;
	return vector;
}
inline static Vec2I minVec2I()
{
	Vec2I vector;
	vector.x = INT32_MIN;
	vector.y = INT32_MIN;
	return vector;
}
inline static Vec2I maxVec2I()
{
	Vec2I vector;
	vector.x = INT32_MAX;
	vector.y = INT32_MAX;
	return vector;
}

inline static Vec2I addVec2I(
	Vec2I a,
	Vec2I b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static Vec2I subVec2I(
	Vec2I a,
	Vec2I b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static Vec2I mulVec2I(
	Vec2I a,
	Vec2I b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static Vec2I divVec2I(
	Vec2I a,
	Vec2I b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static Vec2I addValVec2I(
	Vec2I vector,
	int32_t value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static Vec2I subValVec2I(
	Vec2I vector,
	int32_t value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static Vec2I mulValVec2I(
	Vec2I vector,
	int32_t value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static Vec2I divValVec2I(
	Vec2I vector,
	int32_t value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2I(
	Vec2I a,
	Vec2I b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}
inline static Vec2I negVec2I(
	Vec2I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}
inline static float dotVec2I(
	Vec2I a,
	Vec2I b)
{
	return (float)(
		a.x * b.x +
		a.y * b.y);
}
inline static float lenVec2I(
	Vec2I vector)
{
	return sqrtf((float)(
		vector.x * vector.x +
		vector.y * vector.y));
}
inline static float distPowVec2I(
	Vec2I a,
	Vec2I b)
{
	return (float)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y));
}
inline static float distVec2I(
	Vec2I a,
	Vec2I b)
{
	return sqrtf((float)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y)));
}
inline static Vec2F normVec2I(
	Vec2I vector)
{
	float length = sqrtf((float)(
		vector.x * vector.x +
		vector.y * vector.y));

	Vec2F result;
	result.x = (float)vector.x / length;
	result.y = (float)vector.y / length;
	return result;
}
inline static Vec2F reflVec2I(
	Vec2I vector,
	Vec2I normal)
{
	float dot = (float)(
		normal.x * vector.x +
		normal.y * vector.y) * 2.0f;

	Vec2F result;
	result.x = (float)vector.x - (float)normal.x * dot;
	result.y = (float)vector.y - (float)normal.y * dot;
	return result;
}

inline static Vec3I vec3I(
	int32_t x,
	int32_t y,
	int32_t z)
{
	Vec3I vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static Vec3I valVec3I(
	int32_t value)
{
	Vec3I vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}
inline static Vec3I zeroVec3I()
{
	Vec3I vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vec3I oneVec3I()
{
	Vec3I vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	return vector;
}
inline static Vec3I minOneVec3I()
{
	Vec3I vector;
	vector.x = -1;
	vector.y = -1;
	vector.z = -1;
	return vector;
}
inline static Vec3I minVec3I()
{
	Vec3I vector;
	vector.x = INT32_MIN;
	vector.y = INT32_MIN;
	vector.z = INT32_MIN;
	return vector;
}
inline static Vec3I maxVec3I()
{
	Vec3I vector;
	vector.x = INT32_MAX;
	vector.y = INT32_MAX;
	vector.z = INT32_MAX;
	return vector;
}

inline static Vec3I leftVec3I()
{
	Vec3I vector;
	vector.x = LEFT_AXIS_VALUE;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vec3I rightVec3I()
{
	Vec3I vector;
	vector.x = RIGHT_AXIS_VALUE;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vec3I bottomVec3I()
{
	Vec3I vector;
	vector.x = 0;
	vector.y = BOTTOM_AXIS_VALUE;
	vector.z = 0;
	return vector;
}
inline static Vec3I topVec3I()
{
	Vec3I vector;
	vector.x = 0;
	vector.y = TOP_AXIS_VALUE;
	vector.z = 0;
	return vector;
}
inline static Vec3F backVec3I()
{
	Vec3F vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = BACK_AXIS_VALUE;
	return vector;
}
inline static Vec3F frontVec3I()
{
	Vec3F vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = FRONT_AXIS_VALUE;
	return vector;
}

inline static Vec3I addVec3I(
	Vec3I a,
	Vec3I b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static Vec3I subVec3I(
	Vec3I a,
	Vec3I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static Vec3I mulVec3I(
	Vec3I a,
	Vec3I b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static Vec3I divVec3I(
	Vec3I a,
	Vec3I b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static Vec3I addValVec3I(
	Vec3I vector,
	int32_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static Vec3I subValVec3I(
	Vec3I vector,
	int32_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static Vec3I mulValVec3I(
	Vec3I vector,
	int32_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static Vec3I divValVec3I(
	Vec3I vector,
	int32_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3I(
	Vec3I a,
	Vec3I b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}
inline static Vec3I negVec3I(
	Vec3I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	return vector;
}
inline static float dotVec3I(
	Vec3I a,
	Vec3I b)
{
	return (float)(
		a.x * b.x +
		a.y * b.y +
		a.z * b.z);
}
inline static float lenVec3I(
	Vec3I vector)
{
	return sqrtf((float)(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z));
}
inline static float distPowVec3I(
	Vec3I a,
	Vec3I b)
{
	return (float)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z));
}
inline static float distVec3I(
	Vec3I a,
	Vec3I b)
{
	return sqrtf((float)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z)));
}
inline static Vec3F normVec3I(
	Vec3I vector)
{
	float length = sqrtf((float)(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z));

	Vec3F result;
	result.x = (float)vector.x / length;
	result.y = (float)vector.y / length;
	result.z = (float)vector.z / length;
	return result;
}
inline static Vec3F reflVec3I(
	Vec3I vector,
	Vec3I normal)
{
	float dot = (float)(
		normal.x * vector.x +
		normal.y * vector.y +
		normal.z * vector.z) * 2.0f;

	Vec3F result;
	result.x = (float)vector.x - (float)normal.x * dot;
	result.y = (float)vector.y - (float)normal.y * dot;
	result.z = (float)vector.z - (float)normal.z * dot;
	return result;
}

inline static Vec4I vec4I(
	int32_t x,
	int32_t y,
	int32_t z,
	int32_t w)
{
	Vec4I vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static Vec4I valVec4I(
	int32_t value)
{
	Vec4I vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}
inline static Vec4I zeroVec4I()
{
	Vec4I vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 0;
	return vector;
}
inline static Vec4I oneVec4I()
{
	Vec4I vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	vector.w = 1;
	return vector;
}
inline static Vec4I minOneVec4I()
{
	Vec4I vector;
	vector.x = -1;
	vector.y = -1;
	vector.z = -1;
	vector.w = -1;
	return vector;
}
inline static Vec4I minVec4I()
{
	Vec4I vector;
	vector.x = INT32_MIN;
	vector.y = INT32_MIN;
	vector.z = INT32_MIN;
	vector.w = INT32_MIN;
	return vector;
}
inline static Vec4I maxVec4I()
{
	Vec4I vector;
	vector.x = INT32_MAX;
	vector.y = INT32_MAX;
	vector.z = INT32_MAX;
	vector.w = INT32_MAX;
	return vector;
}

inline static Vec4I addVec4I(
	Vec4I a,
	Vec4I b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static Vec4I subVec4I(
	Vec4I a,
	Vec4I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static Vec4I mulVec4I(
	Vec4I a,
	Vec4I b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static Vec4I divVec4I(
	Vec4I a,
	Vec4I b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static Vec4I addValVec4I(
	Vec4I vector,
	int32_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static Vec4I subValVec4I(
	Vec4I vector,
	int32_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static Vec4I mulValVec4I(
	Vec4I vector,
	int32_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static Vec4I divValVec4I(
	Vec4I vector,
	int32_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4I(
	Vec4I a,
	Vec4I b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
inline static Vec4I negVec4I(
	Vec4I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	vector.w = -vector.w;
	return vector;
}
inline static float dotVec4I(
	Vec4I a,
	Vec4I b)
{
	return (float)(
		a.x * b.x +
		a.y * b.y +
		a.z * b.z +
		a.w * b.w);
}
inline static float lenVec4I(
	Vec4I vector)
{
	return sqrtf((float)(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z +
		vector.w * vector.w));
}
inline static float distPowVec4I(
	Vec4I a,
	Vec4I b)
{
	return (float)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z) +
		(a.w - b.w) * (a.w - b.w));
}
inline static float distVec4I(
	Vec4I a,
	Vec4I b)
{
	return sqrtf((float)(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z) +
		(a.w - b.w) * (a.w - b.w)));
}
inline static Vec4F normVec4I(
	Vec4I vector)
{
	float length = sqrtf((float)(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z +
		vector.w * vector.w));

	Vec4F result;
	result.x = (float)vector.x / length;
	result.y = (float)vector.y / length;
	result.z = (float)vector.z / length;
	result.w = (float)vector.w / length;
	return result;
}
inline static Vec4F reflVec4I(
	Vec4I vector,
	Vec4I normal)
{
	float dot = (float)(
		normal.x * vector.x +
		normal.y * vector.y +
		normal.z * vector.z +
		normal.w * vector.w) * 2.0f;

	Vec4F result;
	result.x = (float)vector.x - (float)normal.x * dot;
	result.y = (float)vector.y - (float)normal.y * dot;
	result.z = (float)vector.z - (float)normal.z * dot;
	result.w = (float)vector.w - (float)normal.w * dot;
	return result;
}

inline static Vec2U vec2U(
	uint32_t x,
	uint32_t y)
{
	Vec2U vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static Vec2U valVec2U(
	uint32_t value)
{
	Vec2U vector;
	vector.x = value;
	vector.y = value;
	return vector;
}
inline static Vec2U zeroVec2U()
{
	Vec2U vector;
	vector.x = 0;
	vector.y = 0;
	return vector;
}
inline static Vec2U oneVec2U()
{
	Vec2U vector;
	vector.x = 1;
	vector.y = 1;
	return vector;
}
inline static Vec2U minVec2U()
{
	Vec2U vector;
	vector.x = 0;
	vector.y = 0;
	return vector;
}
inline static Vec2U maxVec2U()
{
	Vec2U vector;
	vector.x = UINT32_MAX;
	vector.y = UINT32_MAX;
	return vector;
}

inline static Vec2U addVec2U(
	Vec2U a,
	Vec2U b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static Vec2U subVec2U(
	Vec2U a,
	Vec2U b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static Vec2U mulVec2U(
	Vec2U a,
	Vec2U b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static Vec2U divVec2U(
	Vec2U a,
	Vec2U b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static Vec2U addValVec2U(
	Vec2U vector,
	uint32_t value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static Vec2U subValVec2U(
	Vec2U vector,
	uint32_t value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static Vec2U mulValVec2U(
	Vec2U vector,
	uint32_t value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static Vec2U divValVec2U(
	Vec2U vector,
	uint32_t value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2U(
	Vec2U a,
	Vec2U b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}

inline static Vec3U vec3U(
	uint32_t x,
	uint32_t y,
	uint32_t z)
{
	Vec3U vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static Vec3U valVec3U(
	uint32_t value)
{
	Vec3U vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}
inline static Vec3U zeroVec3U()
{
	Vec3U vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vec3U oneVec3U()
{
	Vec3U vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	return vector;
}
inline static Vec3U minVec43()
{
	Vec3U vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vec3U maxVec3U()
{
	Vec3U vector;
	vector.x = UINT32_MAX;
	vector.y = UINT32_MAX;
	vector.z = UINT32_MAX;
	return vector;
}

inline static Vec3U addVec3U(
	Vec3U a,
	Vec3U b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static Vec3U subVec3U(
	Vec3U a,
	Vec3U b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static Vec3U mulVec3U(
	Vec3U a,
	Vec3U b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static Vec3U divVec3U(
	Vec3U a,
	Vec3U b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static Vec3U addValVec3U(
	Vec3U vector,
	uint32_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static Vec3U subValVec3U(
	Vec3U vector,
	uint32_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static Vec3U mulValVec3U(
	Vec3U vector,
	uint32_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static Vec3U divValVec3U(
	Vec3U vector,
	uint32_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3U(
	Vec3U a,
	Vec3U b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}

inline static Vec4U vec4U(
	uint32_t x,
	uint32_t y,
	uint32_t z,
	uint32_t w)
{
	Vec4U vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static Vec4U valVec4U(
	uint32_t value)
{
	Vec4U vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}
inline static Vec4U zeroVec4U()
{
	Vec4U vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 0;
	return vector;
}
inline static Vec4U oneVec4U()
{
	Vec4U vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	vector.w = 1;
	return vector;
}
inline static Vec4U minVec4U()
{
	Vec4U vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 0;
	return vector;
}
inline static Vec4U maxVec4U()
{
	Vec4U vector;
	vector.x = UINT32_MAX;
	vector.y = UINT32_MAX;
	vector.z = UINT32_MAX;
	vector.w = UINT32_MAX;
	return vector;
}

inline static Vec4U addVec4U(
	Vec4U a,
	Vec4U b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static Vec4U subVec4U(
	Vec4U a,
	Vec4U b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static Vec4U mulVec4U(
	Vec4U a,
	Vec4U b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static Vec4U divVec4U(
	Vec4U a,
	Vec4U b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static Vec4U addValVec4U(
	Vec4U vector,
	uint32_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static Vec4U subValVec4U(
	Vec4U vector,
	uint32_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static Vec4U mulValVec4U(
	Vec4U vector,
	uint32_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static Vec4U divValVec4U(
	Vec4U vector,
	uint32_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4U(
	Vec4U a,
	Vec4U b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}

inline static Vec2S vec2S(
	size_t x,
	size_t y)
{
	Vec2S vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static Vec2S valVec2S(
	size_t value)
{
	Vec2S vector;
	vector.x = value;
	vector.y = value;
	return vector;
}
inline static Vec2S zeroVec2S()
{
	Vec2S vector;
	vector.x = 0;
	vector.y = 0;
	return vector;
}
inline static Vec2S oneVec2S()
{
	Vec2S vector;
	vector.x = 1;
	vector.y = 1;
	return vector;
}
inline static Vec2S minVec2S()
{
	Vec2S vector;
	vector.x = 0;
	vector.y = 0;
	return vector;
}
inline static Vec2S maxVec2S()
{
	Vec2S vector;
	vector.x = SIZE_MAX;
	vector.y = SIZE_MAX;
	return vector;
}

inline static Vec2S addVec2S(
	Vec2S a,
	Vec2S b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static Vec2S subVec2S(
	Vec2S a,
	Vec2S b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static Vec2S mulVec2S(
	Vec2S a,
	Vec2S b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static Vec2S divVec2S(
	Vec2S a,
	Vec2S b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static Vec2S addValVec2S(
	Vec2S vector,
	size_t value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static Vec2S subValVec2S(
	Vec2S vector,
	size_t value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static Vec2S mulValVec2S(
	Vec2S vector,
	size_t value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static Vec2S divValVec2S(
	Vec2S vector,
	size_t value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2S(
	Vec2S a,
	Vec2S b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}

inline static Vec3S vec3S(
	size_t x,
	size_t y,
	size_t z)
{
	Vec3S vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static Vec3S valVec3S(
	size_t value)
{
	Vec3S vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}
inline static Vec3S zeroVec3S()
{
	Vec3S vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vec3S oneVec3S()
{
	Vec3S vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	return vector;
}
inline static Vec3S minVec3S()
{
	Vec3S vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vec3S maxVec3S()
{
	Vec3S vector;
	vector.x = SIZE_MAX;
	vector.y = SIZE_MAX;
	vector.z = SIZE_MAX;
	return vector;
}

inline static Vec3S addVec3S(
	Vec3S a,
	Vec3S b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static Vec3S subVec3S(
	Vec3S a,
	Vec3I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static Vec3S mulVec3S(
	Vec3S a,
	Vec3S b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static Vec3S divVec3S(
	Vec3S a,
	Vec3S b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static Vec3S addValVec3S(
	Vec3S vector,
	size_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static Vec3S subValVec3S(
	Vec3S vector,
	size_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static Vec3S mulValVec3S(
	Vec3S vector,
	size_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static Vec3S divValVec3S(
	Vec3S vector,
	size_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3S(
	Vec3S a,
	Vec3S b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}

inline static Vec4S vec4S(
	size_t x,
	size_t y,
	size_t z,
	size_t w)
{
	Vec4S vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static Vec4S valVec4S(
	size_t value)
{
	Vec4S vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}
inline static Vec4S zeroVec4S()
{
	Vec4S vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 0;
	return vector;
}
inline static Vec4S oneVec4S()
{
	Vec4S vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	vector.w = 1;
	return vector;
}
inline static Vec4S minVec4S()
{
	Vec4S vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 0;
	return vector;
}
inline static Vec4S maxVec4S()
{
	Vec4S vector;
	vector.x = SIZE_MAX;
	vector.y = SIZE_MAX;
	vector.z = SIZE_MAX;
	vector.w = SIZE_MAX;
	return vector;
}

inline static Vec4S addVec4S(
	Vec4S a,
	Vec4S b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static Vec4S subVec4S(
	Vec4S a,
	Vec4S b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static Vec4S mulVec4S(
	Vec4S a,
	Vec4S b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static Vec4S divVec4S(
	Vec4S a,
	Vec4S b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static Vec4S addValVec4S(
	Vec4S vector,
	size_t value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static Vec4S subValVec4S(
	Vec4S vector,
	size_t value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static Vec4S mulValVec4S(
	Vec4S vector,
	size_t value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static Vec4S divValVec4S(
	Vec4S vector,
	size_t value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4S(
	Vec4S a,
	Vec4S b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
