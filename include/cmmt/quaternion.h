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
#include "cmmt/matrix.h"

// TODO: quaternion lerp, slerp

typedef struct Quat
{
	float x, y, z, w;
} Quat;

static const Quat zeroQuat = {
	0.0f, 0.0f, 0.0f, 0.0f,
};
static const Quat oneQuat = {
	0.0f, 0.0f, 0.0f, 1.0f,
};

inline static Quat quat(
	float x, float y, float z, float w)
{
	Quat quaternion;
	quaternion.x = x;
	quaternion.y = y;
	quaternion.z = z;
	quaternion.w = w;
	return quaternion;
}
inline static Quat eulerQuat(Vec3F eulerAngles)
{
	float sinX = sinf(eulerAngles.x * 0.5f);
	float sinY = sinf(eulerAngles.y * 0.5f);
	float sinZ = sinf(eulerAngles.z * 0.5f);

	float cosX = cosf(eulerAngles.x * 0.5f);
	float cosY = cosf(eulerAngles.y * 0.5f);
	float cosZ = cosf(eulerAngles.z * 0.5f);

	Quat quaternion;
	quaternion.x = sinX * cosY * cosZ - cosX * sinY * sinZ;
	quaternion.y = cosX * sinY * cosZ + sinX * cosY * sinZ;
	quaternion.z = cosX * cosY * sinZ - sinX * sinY * cosZ;
	quaternion.w = cosX * cosY * cosZ + sinX * sinY * sinZ;
	return quaternion;
}
inline static Quat axisQuat(
	float angle,
	Vec3F axis)
{
	float sin = sinf(angle * 0.5f);

	Quat quaternion;
	quaternion.x = axis.x * sin;
	quaternion.y = axis.y * sin;
	quaternion.z = axis.z * sin;
	quaternion.w = cosf(angle * 0.5f);
	return quaternion;
}

inline static float getQuatPitch(Quat quaternion)
{
	float y = 2.0f * (
		quaternion.y * quaternion.z +
		quaternion.w * quaternion.x);
	float x =
		quaternion.w * quaternion.w -
		quaternion.x * quaternion.x -
		quaternion.y * quaternion.y +
		quaternion.z * quaternion.z;
	return atan2f(y, x);
}
inline static float getQuatYaw(Quat quaternion)
{
	float v = -2.0f * (
		quaternion.x * quaternion.z -
		quaternion.w * quaternion.y);

	if (v < -1.0f)
		v = -1.0f;
	else if (v > 1.0f)
		v = 1.0f;

	return asinf(v);
}
inline static float getQuatRoll(Quat quaternion)
{
	float y = 2.0f * (
		quaternion.x * quaternion.y +
		quaternion.w * quaternion.z);
	float x =
		quaternion.w * quaternion.w +
		quaternion.x * quaternion.x -
		quaternion.y * quaternion.y -
		quaternion.z * quaternion.z;
	return atan2f(y, x);
}
inline static Vec3F getQuatEuler(Quat quaternion)
{
	return vec3F(
		getQuatPitch(quaternion),
		getQuatYaw(quaternion),
		getQuatRoll(quaternion));
}
inline static Mat4F getQuatMatF4(Quat quaternion)
{
	float xx = quaternion.x * quaternion.x;
	float yy = quaternion.y * quaternion.y;
	float zz = quaternion.z * quaternion.z;
	float xz = quaternion.x * quaternion.z;
	float xy = quaternion.x * quaternion.y;
	float yz = quaternion.y * quaternion.z;
	float wx = quaternion.w * quaternion.x;
	float wy = quaternion.w * quaternion.y;
	float wz = quaternion.w * quaternion.z;

	Mat4F matrix;
	matrix.m00 = 1.0f - 2.0f * (yy + zz);
	matrix.m01 = 2.0f * (xy + wz);
	matrix.m02 = 2.0f * (xz - wy);
	matrix.m03 = 0.0f;

	matrix.m10 = 2.0f * (xy - wz);
	matrix.m11 = 1.0f - 2.0f * (xx + zz);
	matrix.m12 = 2.0f * (yz + wx);
	matrix.m13 = 0.0f;

	matrix.m20 = 2.0f * (xz + wy);
	matrix.m21 = 2.0f * (yz - wx);
	matrix.m22 = 1.0f - 2.0f * (xx + yy);
	matrix.m23 = 0.0f;

	matrix.m30 = 0.0f;
	matrix.m31 = 0.0f;
	matrix.m32 = 0.0f;
	matrix.m33 = 1.0f;
	return matrix;
}
inline static Quat getMatQuatF4(Mat4F matrix)
{
	float fourXSquaredMinus1 = matrix.m00 - matrix.m11 - matrix.m22;
	float fourYSquaredMinus1 = matrix.m11 - matrix.m00 - matrix.m22;
	float fourZSquaredMinus1 = matrix.m22 - matrix.m00 - matrix.m11;
	float fourWSquaredMinus1 = matrix.m00 + matrix.m11 + matrix.m22;

	float fourBiggestSquaredMinus1 = fourWSquaredMinus1;
	int biggestIndex = 0;

	if(fourXSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		biggestIndex = 1;
	}
	if(fourYSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		biggestIndex = 2;
	}
	if(fourZSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		biggestIndex = 3;
	}

	float biggestValue = sqrtf(
		fourBiggestSquaredMinus1 + 1.0f) * 0.5f;
	float multiplier = 0.25f / biggestValue;

	switch (biggestIndex)
	{
	default:
		abort();
	case 0:
		return quat(
			(matrix.m12 - matrix.m21) * multiplier,
			(matrix.m20 - matrix.m02) * multiplier,
			(matrix.m01 - matrix.m10) * multiplier,
			biggestValue);
	case 1:
		return quat(
			biggestValue,
			(matrix.m01 + matrix.m10) * multiplier,
			(matrix.m20 + matrix.m02) * multiplier,
			(matrix.m12 - matrix.m21) * multiplier);
	case 2:
		return quat(
			(matrix.m01 + matrix.m10) * multiplier,
			biggestValue,
			(matrix.m12 + matrix.m21) * multiplier,
			(matrix.m20 - matrix.m02) * multiplier);
	case 3:
		return quat(
			(matrix.m20 + matrix.m02) * multiplier,
			(matrix.m12 + matrix.m21) * multiplier,
			biggestValue,
			(matrix.m01 - matrix.m10) * multiplier);
	}
}

inline static Quat conjQuat(Quat quaternion)
{
	quaternion.x = -quaternion.x;
	quaternion.y = -quaternion.y;
	quaternion.z = -quaternion.z;
	return quaternion;
}
inline static Quat invQuat(Quat quaternion)
{
	float dot =
		(quaternion.x * quaternion.x) +
		(quaternion.y * quaternion.y) +
		(quaternion.z * quaternion.z) +
		(quaternion.w * quaternion.w);

	quaternion.x = -quaternion.x / dot;
	quaternion.y = -quaternion.y / dot;
	quaternion.z = -quaternion.z / dot;
	quaternion.w = quaternion.w / dot;
	return quaternion;
}
inline static Quat dotQuat(
	Quat a,
	Quat b)
{
	Quat quaternion;
	quaternion.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	quaternion.y = a.w * b.y + a.y * b.w + a.z * b.x - a.x * b.z;
	quaternion.z = a.w * b.z + a.z * b.w + a.x * b.y - a.y * b.x;
	quaternion.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	return quaternion;
}
inline static Vec3F dotQuatVec3F(
	Quat quaternion,
	Vec3F vector)
{
	float cvX = quaternion.y * vector.z - quaternion.z * vector.y;
	float cvY = quaternion.z * vector.x - quaternion.x * vector.z;
	float cvZ = quaternion.x * vector.y - quaternion.y * vector.x;

	float ccvX = quaternion.y * cvZ - quaternion.z * cvY;
	float ccvY = quaternion.z * cvX - quaternion.x * cvZ;
	float ccvZ = quaternion.x * cvY - quaternion.y * cvX;

	vector.x = vector.x + ((cvX * quaternion.w) + ccvX) * 2.0f;
	vector.y = vector.y + ((cvY * quaternion.w) + ccvY) * 2.0f;
	vector.z = vector.z + ((cvZ * quaternion.w) + ccvZ) * 2.0f;
	return vector;
}
inline static Vec3F dotVecQuat3F(
	Vec3F vector,
	Quat quaternion)
{
	return dotQuatVec3F(invQuat(quaternion), vector);
}
inline static Quat normQuat(
	Quat quaternion)
{
	float length = sqrtf(
		(quaternion.x * quaternion.x) +
		(quaternion.y * quaternion.y) +
		(quaternion.z * quaternion.z) +
		(quaternion.w * quaternion.w));

	if (length <= 0.0f)
	{
		quaternion.x = 0.0f;
		quaternion.y = 0.0f;
		quaternion.z = 0.0f;
		quaternion.w = 1.0f;
		return quaternion;
	}

	length = 1.0f / length;

	quaternion.x *= length;
	quaternion.y *= length;
	quaternion.z *= length;
	quaternion.w *= length;
	return quaternion;
}

inline static bool compQuat(
	Quat a,
	Quat b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
