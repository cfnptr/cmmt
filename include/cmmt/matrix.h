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

// TODO: Mat2, Mat3, Mat23...
// TODO: rotate matrix

typedef struct Mat4F
{
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;
	float m30, m31, m32, m33;
} Mat4F;

inline static Mat4F matF4(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33)
{
	Mat4F matrix;
	matrix.m00 = m00;
	matrix.m01 = m01;
	matrix.m02 = m02;
	matrix.m03 = m03;

	matrix.m10 = m10;
	matrix.m11 = m11;
	matrix.m12 = m12;
	matrix.m13 = m13;

	matrix.m20 = m20;
	matrix.m21 = m21;
	matrix.m22 = m22;
	matrix.m23 = m23;

	matrix.m30 = m30;
	matrix.m31 = m31;
	matrix.m32 = m32;
	matrix.m33 = m33;
	return matrix;
}
inline static Mat4F zeroMatF4()
{
	Mat4F matrix;
	matrix.m00 = 0.0f;
	matrix.m01 = 0.0f;
	matrix.m02 = 0.0f;
	matrix.m03 = 0.0f;

	matrix.m10 = 0.0f;
	matrix.m11 = 0.0f;
	matrix.m12 = 0.0f;
	matrix.m13 = 0.0f;

	matrix.m20 = 0.0f;
	matrix.m21 = 0.0f;
	matrix.m22 = 0.0f;
	matrix.m23 = 0.0f;

	matrix.m30 = 0.0f;
	matrix.m31 = 0.0f;
	matrix.m32 = 0.0f;
	matrix.m33 = 0.0f;
	return matrix;
}
inline static Mat4F oneMat4F()
{
	Mat4F matrix;
	matrix.m00 = 1.0f;
	matrix.m01 = 1.0f;
	matrix.m02 = 1.0f;
	matrix.m03 = 1.0f;

	matrix.m10 = 1.0f;
	matrix.m11 = 1.0f;
	matrix.m12 = 1.0f;
	matrix.m13 = 1.0f;

	matrix.m20 = 1.0f;
	matrix.m21 = 1.0f;
	matrix.m22 = 1.0f;
	matrix.m23 = 1.0f;

	matrix.m30 = 1.0f;
	matrix.m31 = 1.0f;
	matrix.m32 = 1.0f;
	matrix.m33 = 1.0f;
	return matrix;
}
inline static Mat4F minOneMat4F()
{
	Mat4F matrix;
	matrix.m00 = -1.0f;
	matrix.m01 = -1.0f;
	matrix.m02 = -1.0f;
	matrix.m03 = -1.0f;

	matrix.m10 = -1.0f;
	matrix.m11 = -1.0f;
	matrix.m12 = -1.0f;
	matrix.m13 = -1.0f;

	matrix.m20 = -1.0f;
	matrix.m21 = -1.0f;
	matrix.m22 = -1.0f;
	matrix.m23 = -1.0f;

	matrix.m30 = -1.0f;
	matrix.m31 = -1.0f;
	matrix.m32 = -1.0f;
	matrix.m33 = -1.0f;
	return matrix;
}
inline static Mat4F identMat4F()
{
	Mat4F matrix;
	matrix.m00 = 1.0f;
	matrix.m01 = 0.0f;
	matrix.m02 = 0.0f;
	matrix.m03 = 0.0f;

	matrix.m10 = 0.0f;
	matrix.m11 = 1.0f;
	matrix.m12 = 0.0f;
	matrix.m13 = 0.0f;

	matrix.m20 = 0.0f;
	matrix.m21 = 0.0f;
	matrix.m22 = 1.0f;
	matrix.m23 = 0.0f;

	matrix.m30 = 0.0f;
	matrix.m31 = 0.0f;
	matrix.m32 = 0.0f;
	matrix.m33 = 1.0f;
	return matrix;
}

inline static Mat4F addMat4F(
	Mat4F a,
	Mat4F b)
{
	a.m00 += b.m00;
	a.m01 += b.m01;
	a.m02 += b.m02;
	a.m03 += b.m03;

	a.m10 += b.m10;
	a.m11 += b.m11;
	a.m12 += b.m12;
	a.m13 += b.m13;

	a.m20 += b.m20;
	a.m21 += b.m21;
	a.m22 += b.m22;
	a.m23 += b.m23;

	a.m30 += b.m30;
	a.m31 += b.m31;
	a.m32 += b.m32;
	a.m33 += b.m33;
	return a;
}
inline static Mat4F subMat4F(
	Mat4F a,
	Mat4F b)
{
	a.m00 -= b.m00;
	a.m01 -= b.m01;
	a.m02 -= b.m02;
	a.m03 -= b.m03;

	a.m10 -= b.m10;
	a.m11 -= b.m11;
	a.m12 -= b.m12;
	a.m13 -= b.m13;

	a.m20 -= b.m20;
	a.m21 -= b.m21;
	a.m22 -= b.m22;
	a.m23 -= b.m23;

	a.m30 -= b.m30;
	a.m31 -= b.m31;
	a.m32 -= b.m32;
	a.m33 -= b.m33;
	return a;
}
inline static Mat4F mulMat4F(
	Mat4F a,
	Mat4F b)
{
	a.m00 *= b.m00;
	a.m01 *= b.m01;
	a.m02 *= b.m02;
	a.m03 *= b.m03;

	a.m10 *= b.m10;
	a.m11 *= b.m11;
	a.m12 *= b.m12;
	a.m13 *= b.m13;

	a.m20 *= b.m20;
	a.m21 *= b.m21;
	a.m22 *= b.m22;
	a.m23 *= b.m23;

	a.m30 *= b.m30;
	a.m31 *= b.m31;
	a.m32 *= b.m32;
	a.m33 *= b.m33;
	return a;
}
inline static Mat4F divMat4F(
	Mat4F a,
	Mat4F b)
{
	a.m00 /= b.m00;
	a.m01 /= b.m01;
	a.m02 /= b.m02;
	a.m03 /= b.m03;

	a.m10 /= b.m10;
	a.m11 /= b.m11;
	a.m12 /= b.m12;
	a.m13 /= b.m13;

	a.m20 /= b.m20;
	a.m21 /= b.m21;
	a.m22 /= b.m22;
	a.m23 /= b.m23;

	a.m30 /= b.m30;
	a.m31 /= b.m31;
	a.m32 /= b.m32;
	a.m33 /= b.m33;
	return a;
}

inline static Mat4F addValMat4F(
	Mat4F matrix,
	float value)
{
	matrix.m00 += value;
	matrix.m01 += value;
	matrix.m02 += value;
	matrix.m03 += value;

	matrix.m10 += value;
	matrix.m11 += value;
	matrix.m12 += value;
	matrix.m13 += value;

	matrix.m20 += value;
	matrix.m21 += value;
	matrix.m22 += value;
	matrix.m23 += value;

	matrix.m30 += value;
	matrix.m31 += value;
	matrix.m32 += value;
	matrix.m33 += value;
	return matrix;
}
inline static Mat4F subValMat4F(
	Mat4F matrix,
	float value)
{
	matrix.m00 -= value;
	matrix.m01 -= value;
	matrix.m02 -= value;
	matrix.m03 -= value;

	matrix.m10 -= value;
	matrix.m11 -= value;
	matrix.m12 -= value;
	matrix.m13 -= value;

	matrix.m20 -= value;
	matrix.m21 -= value;
	matrix.m22 -= value;
	matrix.m23 -= value;

	matrix.m30 -= value;
	matrix.m31 -= value;
	matrix.m32 -= value;
	matrix.m33 -= value;
	return matrix;
}
inline static Mat4F mulValMat4F(
	Mat4F matrix,
	float value)
{
	matrix.m00 *= value;
	matrix.m01 *= value;
	matrix.m02 *= value;
	matrix.m03 *= value;

	matrix.m10 *= value;
	matrix.m11 *= value;
	matrix.m12 *= value;
	matrix.m13 *= value;

	matrix.m20 *= value;
	matrix.m21 *= value;
	matrix.m22 *= value;
	matrix.m23 *= value;

	matrix.m30 *= value;
	matrix.m31 *= value;
	matrix.m32 *= value;
	matrix.m33 *= value;
	return matrix;
}
inline static Mat4F divValMat4F(
	Mat4F matrix,
	float value)
{
	matrix.m00 /= value;
	matrix.m01 /= value;
	matrix.m02 /= value;
	matrix.m03 /= value;

	matrix.m10 /= value;
	matrix.m11 /= value;
	matrix.m12 /= value;
	matrix.m13 /= value;

	matrix.m20 /= value;
	matrix.m21 /= value;
	matrix.m22 /= value;
	matrix.m23 /= value;

	matrix.m30 /= value;
	matrix.m31 /= value;
	matrix.m32 /= value;
	matrix.m33 /= value;
	return matrix;
}

inline static Mat4F negMat4F(
	Mat4F matrix)
{
	matrix.m00 = -matrix.m00;
	matrix.m01 = -matrix.m01;
	matrix.m02 = -matrix.m02;
	matrix.m03 = -matrix.m03;

	matrix.m10 = -matrix.m10;
	matrix.m11 = -matrix.m11;
	matrix.m12 = -matrix.m12;
	matrix.m13 = -matrix.m13;

	matrix.m20 = -matrix.m20;
	matrix.m21 = -matrix.m21;
	matrix.m22 = -matrix.m22;
	matrix.m23 = -matrix.m23;

	matrix.m30 = -matrix.m30;
	matrix.m31 = -matrix.m31;
	matrix.m32 = -matrix.m32;
	matrix.m33 = -matrix.m33;
	return matrix;
}

inline static Mat4F dotMat4F(
	Mat4F a,
	Mat4F b)
{
	Mat4F matrix;
	matrix.m00 = a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02 + a.m30 * b.m03;
	matrix.m01 = a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02 + a.m31 * b.m03;
	matrix.m02 = a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02 + a.m32 * b.m03;
	matrix.m03 = a.m03 * b.m00 + a.m13 * b.m01 + a.m23 * b.m02 + a.m33 * b.m03;

	matrix.m10 = a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12 + a.m30 * b.m13;
	matrix.m11 = a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12 + a.m31 * b.m13;
	matrix.m12 = a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12 + a.m32 * b.m13;
	matrix.m13 = a.m03 * b.m10 + a.m13 * b.m11 + a.m23 * b.m12 + a.m33 * b.m13;

	matrix.m20 = a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22 + a.m30 * b.m23;
	matrix.m21 = a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22 + a.m31 * b.m23;
	matrix.m22 = a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22 + a.m32 * b.m23;
	matrix.m23 = a.m03 * b.m20 + a.m13 * b.m21 + a.m23 * b.m22 + a.m33 * b.m23;

	matrix.m30 = a.m00 * b.m30 + a.m10 * b.m31 + a.m20 * b.m32 + a.m30 * b.m33;
	matrix.m31 = a.m01 * b.m30 + a.m11 * b.m31 + a.m21 * b.m32 + a.m31 * b.m33;
	matrix.m32 = a.m02 * b.m30 + a.m12 * b.m31 + a.m22 * b.m32 + a.m32 * b.m33;
	matrix.m33 = a.m03 * b.m30 + a.m13 * b.m31 + a.m23 * b.m32 + a.m33 * b.m33;
	return matrix;
}
inline static Vec4F dotVecMat4F(
	Vec4F vector,
	Mat4F matrix)
{
	Vec4F result;
	result.x =
		matrix.m00 * vector.x +
		matrix.m01 * vector.y +
		matrix.m02 * vector.z +
		matrix.m03 * vector.w;
	result.y =
		matrix.m10 * vector.x +
		matrix.m11 * vector.y +
		matrix.m12 * vector.z +
		matrix.m13 * vector.w;
	result.z =
		matrix.m20 * vector.x +
		matrix.m21 * vector.y +
		matrix.m22 * vector.z +
		matrix.m23 * vector.w;
	result.w =
		matrix.m30 * vector.x +
		matrix.m31 * vector.y +
		matrix.m32 * vector.z +
		matrix.m33 * vector.w;
	return result;
}
inline static Vec4F dotMatVec4F(
	Mat4F matrix,
	Vec4F vector)
{
	Vec4F result;
	result.x =
		matrix.m00 * vector.x +
		matrix.m10 * vector.y +
		matrix.m20 * vector.z +
		matrix.m30 * vector.w;
	result.y =
		matrix.m01 * vector.x +
		matrix.m11 * vector.y +
		matrix.m21 * vector.z +
		matrix.m31 * vector.w;
	result.z =
		matrix.m02 * vector.x +
		matrix.m12 * vector.y +
		matrix.m22 * vector.z +
		matrix.m32 * vector.w;
	result.w =
		matrix.m03 * vector.x +
		matrix.m13 * vector.y +
		matrix.m23 * vector.z +
		matrix.m33 * vector.w;
	return result;
}
inline static float detMat4F(
	Mat4F matrix)
{
	float f0 = matrix.m22 * matrix.m33 - matrix.m32 * matrix.m23;
	float f1 = matrix.m21 * matrix.m33 - matrix.m31 * matrix.m23;
	float f2 = matrix.m21 * matrix.m32 - matrix.m31 * matrix.m22;
	float f3 = matrix.m20 * matrix.m33 - matrix.m30 * matrix.m23;
	float f4 = matrix.m20 * matrix.m32 - matrix.m30 * matrix.m22;
	float f5 = matrix.m20 * matrix.m31 - matrix.m30 * matrix.m21;

	float c0 = matrix.m11 * f0 - matrix.m12 * f1 + matrix.m13 * f2;
	float c1 = -(matrix.m10 * f0 - matrix.m12 * f3 + matrix.m13 * f4);
	float c2 = matrix.m10 * f1 -matrix. m11 * f3 + matrix.m13 * f5;
	float c3 = -(matrix.m10 * f2 - matrix.m11 * f4 + matrix.m12 * f5);

	return matrix.m00 * c0 + matrix.m01 * c1 + matrix.m02 * c2 + matrix.m03 * c3;
}
inline static Mat4F transposeMat4F(
	Mat4F matrix)
{
	Mat4F transposed;
	transposed.m00 = matrix.m00;
	transposed.m01 = matrix.m10;
	transposed.m02 = matrix.m20;
	transposed.m03 = matrix.m30;

	transposed.m10 = matrix.m01;
	transposed.m11 = matrix.m11;
	transposed.m12 = matrix.m21;
	transposed.m13 = matrix.m31;

	transposed.m20 = matrix.m02;
	transposed.m21 = matrix.m12;
	transposed.m22 = matrix.m22;
	transposed.m23 = matrix.m32;

	transposed.m30 = matrix.m03;
	transposed.m31 = matrix.m13;
	transposed.m32 = matrix.m23;
	transposed.m33 = matrix.m33;
	return transposed;
}
inline static Mat4F invMat4F(
	Mat4F matrix)
{
	float s0 = matrix.m00 * matrix.m11 - matrix.m10 * matrix.m01;
	float s1 = matrix.m00 * matrix.m12 - matrix.m10 * matrix.m02;
	float s2 = matrix.m00 * matrix.m13 - matrix.m10 * matrix.m03;
	float s3 = matrix.m01 * matrix.m12 - matrix.m11 * matrix.m02;
	float s4 = matrix.m01 * matrix.m13 - matrix.m11 * matrix.m03;
	float s5 = matrix.m02 * matrix.m13 - matrix.m12 * matrix.m03;

	float c0 = matrix.m20 * matrix.m31 - matrix.m30 * matrix.m21;
	float c1 = matrix.m20 * matrix.m32 - matrix.m30 * matrix.m22;
	float c2 = matrix.m20 * matrix.m33 - matrix.m30 * matrix.m23;
	float c3 = matrix.m21 * matrix.m32 - matrix.m31 * matrix.m22;
	float c4 = matrix.m21 * matrix.m33 - matrix.m31 * matrix.m23;
	float c5 = matrix.m22 * matrix.m33 - matrix.m32 * matrix.m23;

	float id = 1.0f /
		(s0 * c5 - s1 * c4 +
		s2 * c3 + s3 * c2 -
		s4 * c1 + s5 * c0);

	Mat4F inverted;
	inverted.m00 = (matrix.m11 * c5 - matrix.m12 * c4 + matrix.m13 * c3) * id;
	inverted.m01 = (-matrix.m01 * c5 + matrix.m02 * c4 - matrix.m03 * c3) * id;
	inverted.m02 = (matrix.m31 * s5 - matrix.m32 * s4 + matrix.m33 * s3) * id;
	inverted.m03 = (-matrix.m21 * s5 + matrix.m22 * s4 - matrix.m23 * s3) * id;

	inverted.m10 = (-matrix.m10 * c5 + matrix.m12 * c2 - matrix.m13 * c1) * id;
	inverted.m11 = (matrix.m00 * c5 - matrix.m02 * c2 + matrix.m03 * c1) * id;
	inverted.m12 = (-matrix.m30 * s5 + matrix.m32 * s2 - matrix.m33 * s1) * id;
	inverted.m13 = (matrix.m20 * s5 - matrix.m22 * s2 + matrix.m23 * s1) * id;

	inverted.m20 = (matrix.m10 * c4 - matrix.m11 * c2 + matrix.m13 * c0) * id;
	inverted.m21 = (-matrix.m00 * c4 + matrix.m01 * c2 - matrix.m03 * c0) * id;
	inverted.m22 = (matrix.m30 * s4 - matrix.m31 * s2 + matrix.m33 * s0) * id;
	inverted.m23 = (-matrix.m20 * s4 + matrix.m21 * s2 - matrix.m23 * s0) * id;

	inverted.m30 = (-matrix.m10 * c3 + matrix.m11 * c1 - matrix.m12 * c0) * id;
	inverted.m31 = (matrix.m00 * c3 - matrix.m01 * c1 + matrix.m02 * c0) * id;
	inverted.m32 = (-matrix.m30 * s3 + matrix.m31 * s1 - matrix.m32 * s0) * id;
	inverted.m33 = (matrix.m20 * s3 - matrix.m21 * s1 + matrix.m22 * s0) * id;
	return inverted;
}
inline static Mat4F scaleMat4F(
	Mat4F matrix,
	Vec3F scale)
{
	matrix.m00 *= scale.x;
	matrix.m01 *= scale.x;
	matrix.m02 *= scale.x;
	matrix.m03 *= scale.x;

	matrix.m10 *= scale.y;
	matrix.m11 *= scale.y;
	matrix.m12 *= scale.y;
	matrix.m13 *= scale.y;

	matrix.m20 *= scale.z;
	matrix.m21 *= scale.z;
	matrix.m22 *= scale.z;
	matrix.m23 *= scale.z;
	return matrix;
}
inline static Vec3F getScaleMat4F(
	Mat4F matrix)
{
	Vec3F scale;
	scale.x = sqrtf(
		(matrix.m00 * matrix.m00) +
		(matrix.m01 * matrix.m01) +
		(matrix.m02 * matrix.m02));
	scale.y = sqrtf(
		(matrix.m10 * matrix.m10) +
		(matrix.m11 * matrix.m11) +
		(matrix.m12 * matrix.m12));
	scale.z = sqrtf(
		(matrix.m20 * matrix.m20) +
		(matrix.m21 * matrix.m21) +
		(matrix.m22 * matrix.m22));
	return scale;
}
inline static Mat4F translateMat4F(
	Mat4F matrix,
	Vec3F translation)
{
	matrix.m30 =
		matrix.m00 * translation.x +
		matrix.m10 * translation.y +
		matrix.m20 * translation.z + matrix.m30;
	matrix.m31 =
		matrix.m01 * translation.x +
		matrix.m11 * translation.y +
		matrix.m21 * translation.z + matrix.m31;
	matrix.m32 =
		matrix.m02 * translation.x +
		matrix.m12 * translation.y +
		matrix.m22 * translation.z + matrix.m32;
	matrix.m33 =
		matrix.m03 * translation.x +
		matrix.m13 * translation.y +
		matrix.m23 * translation.z + matrix.m33;
	return matrix;
}
inline static Vec3F getTranslationMat4F(
	Mat4F matrix)
{
	Vec3F translation;
	translation.x = matrix.m30;
	translation.y = matrix.m31;
	translation.z = matrix.m32;
	return translation;
}
inline static Mat4F lookAtMat4F(
	Vec3F eye,
	Vec3F center,
	Vec3F up)
{
	float fX = center.x - eye.x;
	float fY = center.y - eye.y;
	float fZ = center.z - eye.z;

	float l = sqrtf(fX * fX + fY * fY + fZ * fZ);
	fX /= l; fY /= l; fZ /= l;

	float sX = up.y * fZ - up.z * fY;
	float sY = up.z * fX - up.x * fZ;
	float sZ = up.x * fY - up.y * fX;

	l = sqrtf(sX * sX + sY * sY + sZ * sZ);
	sX /= l; sY /= l; sZ /= l;

	float uX = fY * sZ - fZ * sY;
	float uY = fZ * sX - fX * sZ;
	float uZ = fX * sY - fY * sX;

	Mat4F matrix;
	matrix.m00 = sX;
	matrix.m01 = uX;
	matrix.m02 = fX;
	matrix.m03 = 0.0f;

	matrix.m10 = sY;
	matrix.m11 = uY;
	matrix.m12 = fY;
	matrix.m13 = 0.0f;

	matrix.m20 = sZ;
	matrix.m21 = uZ;
	matrix.m22 = fZ;
	matrix.m23 = 0.0f;

	matrix.m30 = -((sX * eye.x) + (sY * eye.y) + (sZ * eye.z));
	matrix.m31 = -((uX * eye.x) + (uY * eye.y) + (uZ * eye.z));
	matrix.m32 = -((fX * eye.x) + (fY * eye.y) + (fZ * eye.z));
	matrix.m33 = 1.0f;
	return matrix;
}
