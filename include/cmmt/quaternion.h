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
	cmmt_float_t x, y, z, w;
} Quat;

static const Quat zeroQuat = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0,
};
static const Quat oneQuat = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)1.0,
};

inline static Quat quat(
	cmmt_float_t x, cmmt_float_t y, cmmt_float_t z, cmmt_float_t w)
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
	cmmt_float_t sinX = cmmtSin(eulerAngles.x * (cmmt_float_t)0.5);
	cmmt_float_t sinY = cmmtSin(eulerAngles.y * (cmmt_float_t)0.5);
	cmmt_float_t sinZ = cmmtSin(eulerAngles.z * (cmmt_float_t)0.5);

	cmmt_float_t cosX = cmmtCos(eulerAngles.x * (cmmt_float_t)0.5);
	cmmt_float_t cosY = cmmtCos(eulerAngles.y * (cmmt_float_t)0.5);
	cmmt_float_t cosZ = cmmtCos(eulerAngles.z * (cmmt_float_t)0.5);

	Quat quaternion;
	quaternion.x = sinX * cosY * cosZ - cosX * sinY * sinZ;
	quaternion.y = cosX * sinY * cosZ + sinX * cosY * sinZ;
	quaternion.z = cosX * cosY * sinZ - sinX * sinY * cosZ;
	quaternion.w = cosX * cosY * cosZ + sinX * sinY * sinZ;
	return quaternion;
}
inline static Quat axisQuat(cmmt_float_t angle, Vec3F axis)
{
	cmmt_float_t sinus = cmmtSin(angle * (cmmt_float_t)0.5);

	Quat quaternion;
	quaternion.x = axis.x * sinus;
	quaternion.y = axis.y * sinus;
	quaternion.z = axis.z * sinus;
	quaternion.w = cmmtCos(angle * (cmmt_float_t)0.5);
	return quaternion;
}
inline static Quat matQuat4F(Mat4F matrix)
{
	cmmt_float_t fourXSquaredMinus1 = matrix.m00 - matrix.m11 - matrix.m22;
	cmmt_float_t fourYSquaredMinus1 = matrix.m11 - matrix.m00 - matrix.m22;
	cmmt_float_t fourZSquaredMinus1 = matrix.m22 - matrix.m00 - matrix.m11;
	cmmt_float_t fourWSquaredMinus1 = matrix.m00 + matrix.m11 + matrix.m22;

	cmmt_float_t fourBiggestSquaredMinus1 = fourWSquaredMinus1;
	int biggestIndex = 0;

	if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		biggestIndex = 1;
	}
	if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		biggestIndex = 2;
	}
	if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		biggestIndex = 3;
	}

	cmmt_float_t biggestValue = cmmtSqrt(
		fourBiggestSquaredMinus1 + (cmmt_float_t)1.0) * (cmmt_float_t)0.5;
	cmmt_float_t multiplier = (cmmt_float_t)0.25 / biggestValue;

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

inline static cmmt_float_t getQuatPitch(Quat quaternion)
{
	cmmt_float_t y = (cmmt_float_t)2.0 *
		(quaternion.y * quaternion.z +
		quaternion.w * quaternion.x);
	cmmt_float_t x =
		quaternion.w * quaternion.w -
		quaternion.x * quaternion.x -
		quaternion.y * quaternion.y +
		quaternion.z * quaternion.z;
	return cmmtAtan2(y, x);
}
inline static cmmt_float_t getQuatYaw(Quat quaternion)
{
	cmmt_float_t v = (cmmt_float_t)-2.0 *
		(quaternion.x * quaternion.z -
		quaternion.w * quaternion.y);

	if (v < (cmmt_float_t)-1.0)
		v = (cmmt_float_t)-1.0;
	else if (v > (cmmt_float_t)1.0)
		v = (cmmt_float_t)1.0;

	return cmmtAsin(v);
}
inline static cmmt_float_t getQuatRoll(Quat quaternion)
{
	cmmt_float_t y = (cmmt_float_t)2.0 *
		(quaternion.x * quaternion.y +
		quaternion.w * quaternion.z);
	cmmt_float_t x =
		quaternion.w * quaternion.w +
		quaternion.x * quaternion.x -
		quaternion.y * quaternion.y -
		quaternion.z * quaternion.z;
	return cmmtAtan2(y, x);
}
inline static Vec3F getQuatEuler(Quat quaternion)
{
	return vec3F(
		getQuatPitch(quaternion),
		getQuatYaw(quaternion),
		getQuatRoll(quaternion));
}
inline static Mat4F getQuatMat4F(Quat quaternion)
{
	cmmt_float_t xx = quaternion.x * quaternion.x;
	cmmt_float_t yy = quaternion.y * quaternion.y;
	cmmt_float_t zz = quaternion.z * quaternion.z;
	cmmt_float_t xz = quaternion.x * quaternion.z;
	cmmt_float_t xy = quaternion.x * quaternion.y;
	cmmt_float_t yz = quaternion.y * quaternion.z;
	cmmt_float_t wx = quaternion.w * quaternion.x;
	cmmt_float_t wy = quaternion.w * quaternion.y;
	cmmt_float_t wz = quaternion.w * quaternion.z;

	Mat4F matrix;
	matrix.m00 = (cmmt_float_t)1.0 - (cmmt_float_t)2.0 * (yy + zz);
	matrix.m01 = (cmmt_float_t)2.0 * (xy + wz);
	matrix.m02 = (cmmt_float_t)2.0 * (xz - wy);
	matrix.m03 = (cmmt_float_t)0.0;

	matrix.m10 = (cmmt_float_t)2.0 * (xy - wz);
	matrix.m11 = (cmmt_float_t)1.0 - (cmmt_float_t)2.0 * (xx + zz);
	matrix.m12 = (cmmt_float_t)2.0 * (yz + wx);
	matrix.m13 = (cmmt_float_t)0.0;

	matrix.m20 = (cmmt_float_t)2.0 * (xz + wy);
	matrix.m21 = (cmmt_float_t)2.0 * (yz - wx);
	matrix.m22 = (cmmt_float_t)1.0 - (cmmt_float_t)2.0 * (xx + yy);
	matrix.m23 = (cmmt_float_t)0.0;

	matrix.m30 = (cmmt_float_t)0.0;
	matrix.m31 = (cmmt_float_t)0.0;
	matrix.m32 = (cmmt_float_t)0.0;
	matrix.m33 = (cmmt_float_t)1.0;
	return matrix;
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
	cmmt_float_t dot =
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
inline static Quat dotQuat(Quat a, Quat b)
{
	Quat quaternion;
	quaternion.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	quaternion.y = a.w * b.y + a.y * b.w + a.z * b.x - a.x * b.z;
	quaternion.z = a.w * b.z + a.z * b.w + a.x * b.y - a.y * b.x;
	quaternion.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	return quaternion;
}
inline static Vec3F dotQuatVec3F(Quat quaternion, Vec3F vector)
{
	cmmt_float_t cvX = quaternion.y * vector.z - quaternion.z * vector.y;
	cmmt_float_t cvY = quaternion.z * vector.x - quaternion.x * vector.z;
	cmmt_float_t cvZ = quaternion.x * vector.y - quaternion.y * vector.x;

	cmmt_float_t ccvX = quaternion.y * cvZ - quaternion.z * cvY;
	cmmt_float_t ccvY = quaternion.z * cvX - quaternion.x * cvZ;
	cmmt_float_t ccvZ = quaternion.x * cvY - quaternion.y * cvX;

	vector.x = vector.x + ((cvX * quaternion.w) + ccvX) * (cmmt_float_t)2.0;
	vector.y = vector.y + ((cvY * quaternion.w) + ccvY) * (cmmt_float_t)2.0;
	vector.z = vector.z + ((cvZ * quaternion.w) + ccvZ) * (cmmt_float_t)2.0;
	return vector;
}
inline static Vec3F dotVecQuat3F(Vec3F vector, Quat quaternion)
{
	return dotQuatVec3F(invQuat(quaternion), vector);
}
inline static Quat normQuat(Quat quaternion)
{
	cmmt_float_t length = cmmtSqrt(
		(quaternion.x * quaternion.x) +
		(quaternion.y * quaternion.y) +
		(quaternion.z * quaternion.z) +
		(quaternion.w * quaternion.w));
	assert(length > (cmmt_float_t)0.0);

	length = (cmmt_float_t)1.0 / length;

	quaternion.x *= length;
	quaternion.y *= length;
	quaternion.z *= length;
	quaternion.w *= length;
	return quaternion;
}

inline static bool compQuat(Quat a, Quat b)
{
	return
		a.x == b.x &&
		a.y == b.y &&
		a.z == b.z &&
		a.w == b.w;
}
