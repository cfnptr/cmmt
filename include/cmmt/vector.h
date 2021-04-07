#pragma once
#include <math.h>
#include <stdbool.h>

#define LEFT_AXIS_VALUE -1
#define RIGHT_AXIS_VALUE 1
#define BOTTOM_AXIS_VALUE -1
#define TOP_AXIS_VALUE 1
#define BACK_AXIS_VALUE -1
#define FRONT_AXIS_VALUE 1

// TODO: use full names

typedef struct Vector2F
{
	float x, y;
} Vector2F;
typedef struct Vector3F
{
	float x, y, z;
} Vector3F;
typedef struct Vector4F
{
	float x, y, z, w;
} Vector4F;
typedef struct Vector2I
{
	int x, y;
} Vector2I;
typedef struct Vector3I
{
	int x, y, z;
} Vector3I;
typedef struct Vector4I
{
	int x, y, z, w;
} Vector4I;

inline static Vector2F vec2F(
	float x,
	float y)
{
	Vector2F vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static Vector2F valVec2F(
	float value)
{
	Vector2F vector;
	vector.x = value;
	vector.y = value;
	return vector;
}
inline static Vector2F zeroVec2F()
{
	Vector2F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	return vector;
}
inline static Vector2F oneVec2F()
{
	Vector2F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	return vector;
}
inline static Vector2F minOneVec2F()
{
	Vector2F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	return vector;
}

inline static Vector2F addVec2F(
	Vector2F a,
	Vector2F b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static Vector2F subVec2F(
	Vector2F a,
	Vector2F b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static Vector2F mulVec2F(
	Vector2F a,
	Vector2F b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static Vector2F divVec2F(
	Vector2F a,
	Vector2F b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static Vector2F addValVec2F(
	Vector2F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static Vector2F subValVec2F(
	Vector2F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static Vector2F mulValVec2F(
	Vector2F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static Vector2F divValVec2F(
	Vector2F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2F(
	Vector2F a,
	Vector2F b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}
inline static Vector2F negVec2F(
	Vector2F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}
inline static float dotVec2F(
	Vector2F a,
	Vector2F b)
{
	return
		(a.x * b.x) +
		(a.y * b.y);
}
inline static float lenVec2F(
	Vector2F vector)
{
	return sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y));
}
inline static float distPowVec2F(
	Vector2F a,
	Vector2F b)
{
	return
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y));
}
inline static float distVec2F(
	Vector2F a,
	Vector2F b)
{
	return sqrtf(
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)));
}
inline static Vector2F normVec2F(
	Vector2F vector)
{
	float length = sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y));

	vector.x /= length;
	vector.y /= length;
	return vector;
}
inline static Vector2F reflVec2F(
	Vector2F vector,
	Vector2F normal)
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

inline static Vector3F vec3F(
	float x,
	float y,
	float z)
{
	Vector3F vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static Vector3F valVec3F(
	float value)
{
	Vector3F vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}
inline static Vector3F zeroVec3F()
{
	Vector3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static Vector3F oneVec3F()
{
	Vector3F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	vector.z = 1.0f;
	return vector;
}
inline static Vector3F minOneVec3F()
{
	Vector3F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	vector.z = -1.0f;
	return vector;
}

inline static Vector3F leftVec3F()
{
	Vector3F vector;
	vector.x = LEFT_AXIS_VALUE;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static Vector3F rightVec3F()
{
	Vector3F vector;
	vector.x = RIGHT_AXIS_VALUE;
	vector.y = 0.0f;
	vector.z = 0.0f;
	return vector;
}
inline static Vector3F bottomVec3F()
{
	Vector3F vector;
	vector.x = 0.0f;
	vector.y = BOTTOM_AXIS_VALUE;
	vector.z = 0.0f;
	return vector;
}
inline static Vector3F topVec3F()
{
	Vector3F vector;
	vector.x = 0.0f;
	vector.y = TOP_AXIS_VALUE;
	vector.z = 0.0f;
	return vector;
}
inline static Vector3F backVec3F()
{
	Vector3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = BACK_AXIS_VALUE;
	return vector;
}
inline static Vector3F frontVec3F()
{
	Vector3F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = FRONT_AXIS_VALUE;
	return vector;
}

inline static Vector3F addVec3F(
	Vector3F a,
	Vector3F b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static Vector3F subVec3F(
	Vector3F a,
	Vector3F b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static Vector3F mulVec3F(
	Vector3F a,
	Vector3F b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static Vector3F divVec3F(
	Vector3F a,
	Vector3F b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static Vector3F addValVec3F(
	Vector3F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static Vector3F subValVec3F(
	Vector3F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static Vector3F mulValVec3F(
	Vector3F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static Vector3F divValVec3F(
	Vector3F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3F(
	Vector3F a,
	Vector3F b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}
inline static Vector3F negVec3F(
	Vector3F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	return vector;
}
inline static float dotVec3F(
	Vector3F a,
	Vector3F b)
{
	return
		(a.x * b.x) +
		(a.y * b.y) +
		(a.z * b.z);
}
inline static Vector3F crossVec3F(
	Vector3F a,
	Vector3F b)
{
	Vector3F vector;
	vector.x = a.y * b.z - a.z * b.y;
	vector.y = a.z * b.x - a.x * b.z;
	vector.z = a.x * b.y - a.y * b.x;
	return vector;
}
inline static float lenVec3F(
	Vector3F vector)
{
	return sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y) +
		(vector.z * vector.z));
}
inline static float distPowVec3F(
	Vector3F a,
	Vector3F b)
{
	return
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)) +
		((a.z - b.z) * (a.z - b.z));
}
inline static float distVec3F(
	Vector3F a,
	Vector3F b)
{
	return sqrtf(
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)) +
		((a.z - b.z) * (a.z - b.z)));
}
inline static Vector3F normVec3F(
	Vector3F vector)
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
inline static Vector3F reflVec3F(
	Vector3F vector,
	Vector3F normal)
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

inline static Vector4F vec4F(
	float x,
	float y,
	float z,
	float w)
{
	Vector4F vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static Vector4F valVec4F(
	float value)
{
	Vector4F vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}
inline static Vector4F zeroVec4F()
{
	Vector4F vector;
	vector.x = 0.0f;
	vector.y = 0.0f;
	vector.z = 0.0f;
	vector.w = 0.0f;
	return vector;
}
inline static Vector4F oneVec4F()
{
	Vector4F vector;
	vector.x = 1.0f;
	vector.y = 1.0f;
	vector.z = 1.0f;
	vector.w = 1.0f;
	return vector;
}
inline static Vector4F minOneVec4F()
{
	Vector4F vector;
	vector.x = -1.0f;
	vector.y = -1.0f;
	vector.z = -1.0f;
	vector.w = -1.0f;
	return vector;
}

inline static Vector4F addVec4F(
	Vector4F a,
	Vector4F b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static Vector4F subVec4F(
	Vector4F a,
	Vector4F b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static Vector4F mulVec4F(
	Vector4F a,
	Vector4F b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static Vector4F divVec4F(
	Vector4F a,
	Vector4F b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static Vector4F addValVec4F(
	Vector4F vector,
	float value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static Vector4F subValVec4F(
	Vector4F vector,
	float value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static Vector4F mulValVec4F(
	Vector4F vector,
	float value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static Vector4F divValVec4F(
	Vector4F vector,
	float value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4F(
	Vector4F a,
	Vector4F b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
inline static Vector4F negVec4F(
	Vector4F vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	vector.w = -vector.w;
	return vector;
}
inline static float dotVec4F(
	Vector4F a,
	Vector4F b)
{
	return
		(a.x * b.x) +
		(a.y * b.y) +
		(a.z * b.z) +
		(a.w * b.w);
}
inline static float lenVec4F(
	Vector4F vector)
{
	return sqrtf(
		(vector.x * vector.x) +
		(vector.y * vector.y) +
		(vector.z * vector.z) +
		(vector.w * vector.w));
}
inline static float distPowVec4F(
	Vector4F a,
	Vector4F b)
{
	return
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)) +
		((a.z - b.z) * (a.z - b.z)) +
		((a.w - b.w) * (a.w - b.w));
}
inline static float distVec4F(
	Vector4F a,
	Vector4F b)
{
	return sqrtf(
		((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y)) +
		((a.z - b.z) * (a.z - b.z)) +
		((a.w - b.w) * (a.w - b.w)));
}
inline static Vector4F normVec4F(
	Vector4F vector)
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
inline static Vector4F reflVec4F(
	Vector4F vector,
	Vector4F normal)
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

inline static Vector2I vec2I(
	int x,
	int y)
{
	Vector2I vector;
	vector.x = x;
	vector.y = y;
	return vector;
}
inline static Vector2I valVec2I(
	int value)
{
	Vector2I vector;
	vector.x = value;
	vector.y = value;
	return vector;
}
inline static Vector2I zeroVec2I()
{
	Vector2I vector;
	vector.x = 0;
	vector.y = 0;
	return vector;
}
inline static Vector2I oneVec2I()
{
	Vector2I vector;
	vector.x = 1;
	vector.y = 1;
	return vector;
}
inline static Vector2I minOneVec2I()
{
	Vector2I vector;
	vector.x = -1;
	vector.y = -1;
	return vector;
}

inline static Vector2I addVec2I(
	Vector2I a,
	Vector2I b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}
inline static Vector2I subVec2I(
	Vector2I a,
	Vector2I b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
inline static Vector2I mulVec2I(
	Vector2I a,
	Vector2I b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
inline static Vector2I divVec2I(
	Vector2I a,
	Vector2I b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline static Vector2I addValVec2I(
	Vector2I vector,
	int value)
{
	vector.x += value;
	vector.y += value;
	return vector;
}
inline static Vector2I subValVec2I(
	Vector2I vector,
	int value)
{
	vector.x -= value;
	vector.y -= value;
	return vector;
}
inline static Vector2I mulValVec2I(
	Vector2I vector,
	int value)
{
	vector.x *= value;
	vector.y *= value;
	return vector;
}
inline static Vector2I divValVec2I(
	Vector2I vector,
	int value)
{
	vector.x /= value;
	vector.y /= value;
	return vector;
}

inline static bool compVec2I(
	Vector2I a,
	Vector2I b)
{
	return
		a.x == b.x &&
		a.y == b.y;
}
inline static Vector2I negVec2I(
	Vector2I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}

inline static Vector3I vec3I(
	int x,
	int y,
	int z)
{
	Vector3I vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}
inline static Vector3I valVec3I(
	int value)
{
	Vector3I vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	return vector;
}
inline static Vector3I zeroVec3I()
{
	Vector3I vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vector3I oneVec3I()
{
	Vector3I vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	return vector;
}
inline static Vector3I minOneVec3I()
{
	Vector3I vector;
	vector.x = -1;
	vector.y = -1;
	vector.z = -1;
	return vector;
}

inline static Vector3I leftVec3I()
{
	Vector3I vector;
	vector.x = -1;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vector3I rightVec3I()
{
	Vector3I vector;
	vector.x = 1;
	vector.y = 0;
	vector.z = 0;
	return vector;
}
inline static Vector3I bottomVec3I()
{
	Vector3I vector;
	vector.x = 0;
	vector.y = -1;
	vector.z = 0;
	return vector;
}
inline static Vector3I topVec3I()
{
	Vector3I vector;
	vector.x = 0;
	vector.y = 1;
	vector.z = 0;
	return vector;
}
inline static Vector3F backVec3I()
{
	Vector3F vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = -1;
	return vector;
}
inline static Vector3F frontVec3I()
{
	Vector3F vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 1;
	return vector;
}

inline static Vector3I addVec3I(
	Vector3I a,
	Vector3I b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
inline static Vector3I subVec3I(
	Vector3I a,
	Vector3I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
inline static Vector3I mulVec3I(
	Vector3I a,
	Vector3I b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
inline static Vector3I divVec3I(
	Vector3I a,
	Vector3I b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline static Vector3I addValVec3I(
	Vector3I vector,
	int value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
inline static Vector3I subValVec3I(
	Vector3I vector,
	int value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
inline static Vector3I mulValVec3I(
	Vector3I vector,
	int value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
inline static Vector3I divValVec3I(
	Vector3I vector,
	int value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}

inline static bool compVec3I(
	Vector3I a,
	Vector3I b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z;
}
inline static Vector3I negVec3I(
	Vector3I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	return vector;
}

inline static Vector4I vec4I(
	int x,
	int y,
	int z,
	int w)
{
	Vector4I vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return vector;
}
inline static Vector4I valVec4I(
	int value)
{
	Vector4I vector;
	vector.x = value;
	vector.y = value;
	vector.z = value;
	vector.w = value;
	return vector;
}
inline static Vector4I zeroVec4I()
{
	Vector4I vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 0;
	return vector;
}
inline static Vector4I oneVec4I()
{
	Vector4I vector;
	vector.x = 1;
	vector.y = 1;
	vector.z = 1;
	vector.w = 1;
	return vector;
}
inline static Vector4I minOneVec4I()
{
	Vector4I vector;
	vector.x = -1;
	vector.y = -1;
	vector.z = -1;
	vector.w = -1;
	return vector;
}

inline static Vector4I addVec4I(
	Vector4I a,
	Vector4I b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
inline static Vector4I subVec4I(
	Vector4I a,
	Vector4I b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
inline static Vector4I mulVec4I(
	Vector4I a,
	Vector4I b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
inline static Vector4I divVec4I(
	Vector4I a,
	Vector4I b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline static Vector4I addValVec4I(
	Vector4I vector,
	int value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}
inline static Vector4I subValVec4I(
	Vector4I vector,
	int value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}
inline static Vector4I mulValVec4I(
	Vector4I vector,
	int value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}
inline static Vector4I divValVec4I(
	Vector4I vector,
	int value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

inline static bool compVec4I(
	Vector4I a,
	Vector4I b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
inline static Vector4I negVec4I(
	Vector4I vector)
{
	vector.x = -vector.x;
	vector.y = -vector.y;
	vector.z = -vector.z;
	vector.w = -vector.w;
	return vector;
}
