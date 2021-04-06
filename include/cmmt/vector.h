#pragma once
#include <math.h>
#include <stdbool.h>

#define LEFT_AXIS_VALUE -1
#define RIGHT_AXIS_VALUE 1
#define BOTTOM_AXIS_VALUE -1
#define TOP_AXIS_VALUE 1
#define BACK_AXIS_VALUE -1
#define FRONT_AXIS_VALUE 1

struct Vec2F
{
	float x, y;
};
struct Vec3F
{
	float x, y, z;
};
struct Vec4F
{
	float x, y, z, w;
};
struct Vec2I
{
	int x, y;
};
struct Vec3I
{
	int x, y, z;
};
struct Vec4I
{
	int x, y, z, w;
};

inline static struct Vec2F vec2F(
	float x,
	float y)
{
	struct Vec2F vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static struct Vec2F valVec2F(
	float value)
{
	struct Vec2F vector;
	vector.x = value;
	vector.y = value;
	return vector;
}
inline static struct Vec2F zeroVec2F()
{
	struct Vec2F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	return vector;
}
inline static struct Vec2F oneVec2F()
{
	struct Vec2F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	return vector;
}
inline static struct Vec2F minOneVec2F()
{
	struct Vec2F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	return vector;
}

inline static struct Vec2F addVec2F(
	struct Vec2F a,
	struct Vec2F b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static struct Vec2F subVec2F(
	struct Vec2F a,
	struct Vec2F b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static struct Vec2F mulVec2F(
	struct Vec2F a,
	struct Vec2F b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static struct Vec2F divVec2F(
	struct Vec2F a,
	struct Vec2F b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static struct Vec2F addValVec2F(
	struct Vec2F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static struct Vec2F subValVec2F(
	struct Vec2F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static struct Vec2F mulValVec2F(
	struct Vec2F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static struct Vec2F divValVec2F(
	struct Vec2F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2F(
	struct Vec2F a,
	struct Vec2F b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}
inline static struct Vec2F negVec2F(
	struct Vec2F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}
inline static float dotVec2F(
	struct Vec2F a,
	struct Vec2F b)
{
	return
		(a.x * b.x) +
		(a.y * b.y);
}
inline static float lenVec2F(
	struct Vec2F vector)
{
	return sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y));
}
inline static float distPowVec2F(
	struct Vec2F a,
	struct Vec2F b)
{
	return
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y));
}
inline static float distVec2F(
	struct Vec2F a,
	struct Vec2F b)
{
	return sqrtf(
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)));
}
inline static struct Vec2F normVec2F(
	struct Vec2F vector)
{
	float length = sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y));

	vector.x /= length;
	vector.y /= length;
	return vector;
}
inline static struct Vec2F reflVec2F(
	struct Vec2F vector,
	struct Vec2F normal)
{
	float dot =
		(normal.x * vector.x) +
		(normal.y * vector.y) * 2.0f;

	normal.x *= dot;
	normal.y *= dot;

	vector.x -= normal.x;
	vector.y -= normal.y;
	return vector;
}

inline static struct Vec3F vec3F(
	float x,
	float y,
	float z)
{
	struct Vec3F vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static struct Vec3F valVec3F(
	float value)
{
	struct Vec3F vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}
inline static struct Vec3F zeroVec3F()
{
	struct Vec3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static struct Vec3F oneVec3F()
{
	struct Vec3F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	vector.z = 1.0f;
	return vector;
}
inline static struct Vec3F minOneVec3F()
{
	struct Vec3F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	vector.z = -1.0f;
	return vector;
}

inline static struct Vec3F leftVec3F()
{
	struct Vec3F vector;
	vector.x = LEFT_AXIS_VALUE;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static struct Vec3F rightVec3F()
{
	struct Vec3F vector;
	vector.x = RIGHT_AXIS_VALUE;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static struct Vec3F bottomVec3F()
{
	struct Vec3F vector;
	vector.x = 0.0f;
	vector.y = BOTTOM_AXIS_VALUE;
	vector.z = 0.0f;
	return vector;
}
inline static struct Vec3F topVec3F()
{
	struct Vec3F vector;
	vector.x = 0.0f;
	vector.y = TOP_AXIS_VALUE;
	vector.z = 0.0f;
	return vector;
}
inline static struct Vec3F backVec3F()
{
	struct Vec3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = BACK_AXIS_VALUE;
	return vector;
}
inline static struct Vec3F frontVec3F()
{
	struct Vec3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = FRONT_AXIS_VALUE;
	return vector;
}

inline static struct Vec3F addVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static struct Vec3F subVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static struct Vec3F mulVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static struct Vec3F divVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static struct Vec3F addValVec3F(
	struct Vec3F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static struct Vec3F subValVec3F(
	struct Vec3F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static struct Vec3F mulValVec3F(
	struct Vec3F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static struct Vec3F divValVec3F(
	struct Vec3F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}
inline static struct Vec3F negVec3F(
	struct Vec3F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	return vector;
}
inline static float dotVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	return
		(a.x * b.x) +
		(a.y * b.y) +
		(a.z * b.z);
}
inline static struct Vec3F crossVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	struct Vec3F vector;
	vector.x = a.y * b.z - a.z * b.y;
	vector.y = a.z * b.x - a.x * b.z;
	vector.z = a.x * b.y - a.y * b.x;
	return vector;
}
inline static float lenVec3F(
	struct Vec3F vector)
{
	return sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y) +
		(vector.z * vector.z));
}
inline static float distPowVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	return
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)) +
		((a.z - b.z) * (a.z - b.z));
}
inline static float distVec3F(
	struct Vec3F a,
	struct Vec3F b)
{
	return sqrtf(
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)) +
		((a.z - b.z) * (a.z - b.z)));
}
inline static struct Vec3F normVec3F(
	struct Vec3F vector)
{
	float length = sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y) +
		(vector.z * vector.z));

	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	return vector;
}
inline static struct Vec3F reflVec3F(
	struct Vec3F vector,
	struct Vec3F normal)
{
	float dot =
		(normal.x * vector.x) +
		(normal.y * vector.y) +
		(normal.z * vector.z) * 2.0f;

	normal.x *= dot;
	normal.y *= dot;
	normal.z *= dot;

	vector.x -= normal.x;
	vector.y -= normal.y;
	vector.z -= normal.z;
	return vector;
}

inline static struct Vec4F vec4F(
	float x,
	float y,
	float z,
	float w)
{
	struct Vec4F vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static struct Vec4F valVec4F(
	float value)
{
	struct Vec4F vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}
inline static struct Vec4F zeroVec4F()
{
	struct Vec4F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = 0.0f;
	vector.w = 0.0f;
	return vector;
}
inline static struct Vec4F oneVec4F()
{
	struct Vec4F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	vector.z = 1.0f;
	vector.w = 1.0f;
	return vector;
}
inline static struct Vec4F minOneVec4F()
{
	struct Vec4F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	vector.z = -1.0f;
	vector.w = -1.0f;
	return vector;
}

inline static struct Vec4F addVec4F(
	struct Vec4F a,
	struct Vec4F b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static struct Vec4F subVec4F(
	struct Vec4F a,
	struct Vec4F b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static struct Vec4F mulVec4F(
	struct Vec4F a,
	struct Vec4F b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static struct Vec4F divVec4F(
	struct Vec4F a,
	struct Vec4F b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static struct Vec4F addValVec4F(
	struct Vec4F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static struct Vec4F subValVec4F(
	struct Vec4F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static struct Vec4F mulValVec4F(
	struct Vec4F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static struct Vec4F divValVec4F(
	struct Vec4F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4F(
	struct Vec4F a,
	struct Vec4F b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
inline static struct Vec4F negVec4F(
	struct Vec4F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	vector.w = -vector.w;
	return vector;
}
inline static float dotVec4F(
	struct Vec4F a,
	struct Vec4F b)
{
	return
		(a.x * b.x) +
		(a.y * b.y) +
		(a.z * b.z) +
		(a.w * b.w);
}
inline static float lenVec4F(
	struct Vec4F vector)
{
	return sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y) +
		(vector.z * vector.z) +
		(vector.w * vector.w));
}
inline static float distPowVec4F(
	struct Vec4F a,
	struct Vec4F b)
{
	return
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)) +
		((a.z - b.z) * (a.z - b.z)) +
		((a.w - b.w) * (a.w - b.w));
}
inline static float distVec4F(
	struct Vec4F a,
	struct Vec4F b)
{
	return sqrtf(
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)) +
		((a.z - b.z) * (a.z - b.z)) +
		((a.w - b.w) * (a.w - b.w)));
}
inline static struct Vec4F normVec4F(
	struct Vec4F vector)
{
	float length = sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y) +
		(vector.z * vector.z) +
		(vector.w * vector.w));

	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	vector.w /= length;
	return vector;
}
inline static struct Vec4F reflVec4F(
	struct Vec4F vector,
	struct Vec4F normal)
{
	float dot =
		(normal.x * vector.x) +
		(normal.y * vector.y) +
		(normal.z * vector.z) +
		(normal.w * vector.w) * 2.0f;

	normal.x *= dot;
	normal.y *= dot;
	normal.z *= dot;
	normal.w *= dot;

	vector.x -= normal.x;
	vector.y -= normal.y;
	vector.z -= normal.z;
	vector.w -= normal.w;
	return vector;
}

inline static struct Vec2I vec2I(
	int x,
	int y)
{
	struct Vec2I vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static struct Vec2I valVec2I(
	int value)
{
	struct Vec2I vector;
	vector.x = value;
	vector.y = value;
	return vector;
}
inline static struct Vec2I zeroVec2I()
{
	struct Vec2I vector;
	vector.x = 0;
	vector.y = 0;
	return vector;
}
inline static struct Vec2I oneVec2I()
{
	struct Vec2I vector;
	vector.x = 1;
	vector.y = 1;
	return vector;
}
inline static struct Vec2I minOneVec2I()
{
	struct Vec2I vector;
	vector.x = -1;
	vector.y = -1;
	return vector;
}

inline static struct Vec2I addVec2I(
	struct Vec2I a,
	struct Vec2I b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static struct Vec2I subVec2I(
	struct Vec2I a,
	struct Vec2I b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static struct Vec2I mulVec2I(
	struct Vec2I a,
	struct Vec2I b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static struct Vec2I divVec2I(
	struct Vec2I a,
	struct Vec2I b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static struct Vec2I addValVec2I(
	struct Vec2I vector,
	int value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static struct Vec2I subValVec2I(
	struct Vec2I vector,
	int value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static struct Vec2I mulValVec2I(
	struct Vec2I vector,
	int value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static struct Vec2I divValVec2I(
	struct Vec2I vector,
	int value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2I(
	struct Vec2I a,
	struct Vec2I b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}
inline static struct Vec2I negVec2I(
	struct Vec2I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}

inline static struct Vec3I vec3I(
	int x,
	int y,
	int z)
{
	struct Vec3I vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static struct Vec3I valVec3I(
	int value)
{
	struct Vec3I vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}
inline static struct Vec3I zeroVec3I()
{
	struct Vec3I vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static struct Vec3I oneVec3I()
{
	struct Vec3I vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	return vector;
}
inline static struct Vec3I minOneVec3I()
{
	struct Vec3I vector;
	vector.x = -1;
	vector.y = -1;
	vector.z = -1;
	return vector;
}

inline static struct Vec3I leftVec3I()
{
	struct Vec3I vector;
	vector.x = -1;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static struct Vec3I rightVec3I()
{
	struct Vec3I vector;
	vector.x = 1;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static struct Vec3I bottomVec3I()
{
	struct Vec3I vector;
	vector.x = 0;
	vector.y = -1;
	vector.z = 0;
	return vector;
}
inline static struct Vec3I topVec3I()
{
	struct Vec3I vector;
	vector.x = 0;
	vector.y = 1;
	vector.z = 0;
	return vector;
}
inline static struct Vec3F backVec3I()
{
	struct Vec3F vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = -1;
	return vector;
}
inline static struct Vec3F frontVec3I()
{
	struct Vec3F vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 1;
	return vector;
}

inline static struct Vec3I addVec3I(
	struct Vec3I a,
	struct Vec3I b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static struct Vec3I subVec3I(
	struct Vec3I a,
	struct Vec3I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static struct Vec3I mulVec3I(
	struct Vec3I a,
	struct Vec3I b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static struct Vec3I divVec3I(
	struct Vec3I a,
	struct Vec3I b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static struct Vec3I addValVec3I(
	struct Vec3I vector,
	int value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static struct Vec3I subValVec3I(
	struct Vec3I vector,
	int value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static struct Vec3I mulValVec3I(
	struct Vec3I vector,
	int value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static struct Vec3I divValVec3I(
	struct Vec3I vector,
	int value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3I(
	struct Vec3I a,
	struct Vec3I b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}
inline static struct Vec3I negVec3I(
	struct Vec3I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	return vector;
}

inline static struct Vec4I vec4I(
	int x,
	int y,
	int z,
	int w)
{
	struct Vec4I vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static struct Vec4I valVec4I(
	int value)
{
	struct Vec4I vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}
inline static struct Vec4I zeroVec4I()
{
	struct Vec4I vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 0;
	return vector;
}
inline static struct Vec4I oneVec4I()
{
	struct Vec4I vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	vector.w = 1;
	return vector;
}
inline static struct Vec4I minOneVec4I()
{
	struct Vec4I vector;
	vector.x = -1;
	vector.y = -1;
	vector.z = -1;
	vector.w = -1;
	return vector;
}

inline static struct Vec4I addVec4I(
	struct Vec4I a,
	struct Vec4I b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static struct Vec4I subVec4I(
	struct Vec4I a,
	struct Vec4I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static struct Vec4I mulVec4I(
	struct Vec4I a,
	struct Vec4I b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static struct Vec4I divVec4I(
	struct Vec4I a,
	struct Vec4I b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static struct Vec4I addValVec4I(
	struct Vec4I vector,
	int value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static struct Vec4I subValVec4I(
	struct Vec4I vector,
	int value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static struct Vec4I mulValVec4I(
	struct Vec4I vector,
	int value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static struct Vec4I divValVec4I(
	struct Vec4I vector,
	int value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4I(
	struct Vec4I a,
	struct Vec4I b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
inline static struct Vec4I negVec4I(
	struct Vec4I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	vector.w = -vector.w;
	return vector;
}
