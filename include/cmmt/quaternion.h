#pragma once
#include "cmmt/matrix.h"

typedef struct Quat
{
	float x, y, z, w;
} Quat;

inline static Quat quat(
	float x,
	float y,
	float z,
	float w)
{
	Quat quaternion;
	quaternion.x = x;
	quaternion.y = y;
	quaternion.z = z;
	quaternion.w = w;
	return quaternion;
}
inline static Quat eulerQuat(
	Vec3F eulerAngles)
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
inline static Quat zeroQuat()
{
	Quat quaternion;
	quaternion.x = 0.0f;
	quaternion.y = 0.0f;
	quaternion.z = 0.0f;
	quaternion.w = 0.0f;
	return quaternion;
}
inline static Quat oneQuat()
{
	Quat quaternion;
	quaternion.x = 0.0f;
	quaternion.y = 0.0f;
	quaternion.z = 0.0f;
	quaternion.w = 1.0f;
	return quaternion;
}

inline static Mat4F getQuatMatF4(
	Quat quaternion)
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

	// TODO: investigate difference between
	// current variant and transposed

	Mat4F matrix;
	matrix.m00 = 1.0f - 2.0f * (yy + zz);
	matrix.m01 = 2.0f * (xy - wz);
	matrix.m02 = 2.0f * (xz + wy);
	matrix.m03 = 0.0f;

	matrix.m10 = 2.0f * (xy + wz);
	matrix.m11 = 1.0f - 2.0f * (xx + zz);
	matrix.m12 = 2.0f * (yz - wx);
	matrix.m13 = 0.0f;

	matrix.m20 = 2.0f * (xz - wy);
	matrix.m21 = 2.0f * (yz + wx);
	matrix.m22 = 1.0f - 2.0f * (xx + yy);
	matrix.m23 = 0.0f;

	matrix.m30 = 0.0f;
	matrix.m31 = 0.0f;
	matrix.m32 = 0.0f;
	matrix.m33 = 1.0f;
	return matrix;
}

// TODO: quaternion from matrix extraction
// TODO: quaternion vector multiplication
// TODO: quaternion pitch, yaw, roll extraction

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
inline static Vec3F dotVecQuat3F(
	Quat quaternion,
	Vec3F vector)
{
	Vec3F qv = vec3F(
		quaternion.x,
		quaternion.y,
		quaternion.z);
	Vec3F cv = crossVec3F(
		qv,
		vector);
	Vec3F ccv = crossVec3F(
		qv,
		cv);

	vector.x = vector.x + ((cv.x * quaternion.w) + ccv.x) * 2.0f;
	vector.y = vector.y + ((cv.y * quaternion.w) + ccv.y) * 2.0f;
	vector.z = vector.z + ((cv.z * quaternion.w) + ccv.z) * 2.0f;
	return vector;
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