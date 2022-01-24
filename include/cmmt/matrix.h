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

// TODO: rotate matrix

typedef struct Mat4F
{
	cmmt_float_t m00, m01, m02, m03;
	cmmt_float_t m10, m11, m12, m13;
	cmmt_float_t m20, m21, m22, m23;
	cmmt_float_t m30, m31, m32, m33;
} Mat4F;
typedef struct Mat4I
{
	cmmt_int_t m00, m01, m02, m03;
	cmmt_int_t m10, m11, m12, m13;
	cmmt_int_t m20, m21, m22, m23;
	cmmt_int_t m30, m31, m32, m33;
} Mat4I;

static const Mat4F zeroMat4F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
};
static const Mat4F oneMat4F = {
	(cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0,
	(cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0,
	(cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0,
	(cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0,
};
static const Mat4F minOneMat4F = {
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
};
static const Mat4F identMat4F = {
	(cmmt_float_t)1.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)1.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)1.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)1.0,
};

static const Mat4I zeroMat4I = {
	(cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0,
	(cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0,
	(cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0,
	(cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0,
};
static const Mat4I oneMat4I = {
	(cmmt_int_t)1, (cmmt_int_t)1, (cmmt_int_t)1, (cmmt_int_t)1,
	(cmmt_int_t)1, (cmmt_int_t)1, (cmmt_int_t)1, (cmmt_int_t)1,
	(cmmt_int_t)1, (cmmt_int_t)1, (cmmt_int_t)1, (cmmt_int_t)1,
	(cmmt_int_t)1, (cmmt_int_t)1, (cmmt_int_t)1, (cmmt_int_t)1,
};
static const Mat4I minOneMat4I = {
	(cmmt_int_t)-1, (cmmt_int_t)-1, (cmmt_int_t)-1, (cmmt_int_t)-1,
	(cmmt_int_t)-1, (cmmt_int_t)-1, (cmmt_int_t)-1, (cmmt_int_t)-1,
	(cmmt_int_t)-1, (cmmt_int_t)-1, (cmmt_int_t)-1, (cmmt_int_t)-1,
	(cmmt_int_t)-1, (cmmt_int_t)-1, (cmmt_int_t)-1, (cmmt_int_t)-1,
};
static const Mat4I identMat4I = {
	(cmmt_int_t)1, (cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0,
	(cmmt_int_t)0, (cmmt_int_t)1, (cmmt_int_t)0, (cmmt_int_t)0,
	(cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)1, (cmmt_int_t)0,
	(cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)0, (cmmt_int_t)1,
};

inline static Mat4F mat4F(
	cmmt_float_t m00, cmmt_float_t m01, cmmt_float_t m02, cmmt_float_t m03,
	cmmt_float_t m10, cmmt_float_t m11, cmmt_float_t m12, cmmt_float_t m13,
	cmmt_float_t m20, cmmt_float_t m21, cmmt_float_t m22, cmmt_float_t m23,
	cmmt_float_t m30, cmmt_float_t m31, cmmt_float_t m32, cmmt_float_t m33)
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

inline static Mat4F addMat4F(Mat4F a, Mat4F b)
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
inline static Mat4F subMat4F(Mat4F a, Mat4F b)
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
inline static Mat4F mulMat4F(Mat4F a, Mat4F b)
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
inline static Mat4F divMat4F(Mat4F a, Mat4F b)
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

inline static Mat4F addValMat4F(Mat4F matrix, cmmt_float_t value)
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
inline static Mat4F subValMat4F(Mat4F matrix, cmmt_float_t value)
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
inline static Mat4F mulValMat4F(Mat4F matrix, cmmt_float_t value)
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
inline static Mat4F divValMat4F(Mat4F matrix, cmmt_float_t value)
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

inline static Mat4F negMat4F(Mat4F matrix)
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

inline static Mat4F dotMat4F(Mat4F a, Mat4F b)
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
inline static Vec4F dotVecMat4F(Vec4F vector, Mat4F matrix)
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
inline static Vec4F dotMatVec4F(Mat4F matrix, Vec4F vector)
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
inline static cmmt_float_t detMat4F(Mat4F matrix)
{
	cmmt_float_t f0 = matrix.m22 * matrix.m33 - matrix.m32 * matrix.m23;
	cmmt_float_t f1 = matrix.m21 * matrix.m33 - matrix.m31 * matrix.m23;
	cmmt_float_t f2 = matrix.m21 * matrix.m32 - matrix.m31 * matrix.m22;
	cmmt_float_t f3 = matrix.m20 * matrix.m33 - matrix.m30 * matrix.m23;
	cmmt_float_t f4 = matrix.m20 * matrix.m32 - matrix.m30 * matrix.m22;
	cmmt_float_t f5 = matrix.m20 * matrix.m31 - matrix.m30 * matrix.m21;

	cmmt_float_t c0 = matrix.m11 * f0 - matrix.m12 * f1 + matrix.m13 * f2;
	cmmt_float_t c1 = -(matrix.m10 * f0 - matrix.m12 * f3 + matrix.m13 * f4);
	cmmt_float_t c2 = matrix.m10 * f1 -matrix. m11 * f3 + matrix.m13 * f5;
	cmmt_float_t c3 = -(matrix.m10 * f2 - matrix.m11 * f4 + matrix.m12 * f5);

	return matrix.m00 * c0 + matrix.m01 * c1 + matrix.m02 * c2 + matrix.m03 * c3;
}
inline static Mat4F transposeMat4F(Mat4F matrix)
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
inline static Mat4F invMat4F(Mat4F matrix)
{
	cmmt_float_t s0 = matrix.m00 * matrix.m11 - matrix.m10 * matrix.m01;
	cmmt_float_t s1 = matrix.m00 * matrix.m12 - matrix.m10 * matrix.m02;
	cmmt_float_t s2 = matrix.m00 * matrix.m13 - matrix.m10 * matrix.m03;
	cmmt_float_t s3 = matrix.m01 * matrix.m12 - matrix.m11 * matrix.m02;
	cmmt_float_t s4 = matrix.m01 * matrix.m13 - matrix.m11 * matrix.m03;
	cmmt_float_t s5 = matrix.m02 * matrix.m13 - matrix.m12 * matrix.m03;

	cmmt_float_t c0 = matrix.m20 * matrix.m31 - matrix.m30 * matrix.m21;
	cmmt_float_t c1 = matrix.m20 * matrix.m32 - matrix.m30 * matrix.m22;
	cmmt_float_t c2 = matrix.m20 * matrix.m33 - matrix.m30 * matrix.m23;
	cmmt_float_t c3 = matrix.m21 * matrix.m32 - matrix.m31 * matrix.m22;
	cmmt_float_t c4 = matrix.m21 * matrix.m33 - matrix.m31 * matrix.m23;
	cmmt_float_t c5 = matrix.m22 * matrix.m33 - matrix.m32 * matrix.m23;

	cmmt_float_t id = (cmmt_float_t)1.0 /
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
inline static Mat4F scaleMat4F(Mat4F matrix, Vec3F scale)
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
inline static Vec3F getScaleMat4F(Mat4F matrix)
{
	Vec3F scale;
	scale.x = cmmtSqrt(
		(matrix.m00 * matrix.m00) +
		(matrix.m01 * matrix.m01) +
		(matrix.m02 * matrix.m02));
	scale.y = cmmtSqrt(
		(matrix.m10 * matrix.m10) +
		(matrix.m11 * matrix.m11) +
		(matrix.m12 * matrix.m12));
	scale.z = cmmtSqrt(
		(matrix.m20 * matrix.m20) +
		(matrix.m21 * matrix.m21) +
		(matrix.m22 * matrix.m22));
	return scale;
}
inline static Mat4F translateMat4F(Mat4F matrix, Vec3F translation)
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
inline static Vec3F getTranslationMat4F(Mat4F matrix)
{
	Vec3F translation;
	translation.x = matrix.m30;
	translation.y = matrix.m31;
	translation.z = matrix.m32;
	return translation;
}
inline static Mat4F lookAtMat4F(Vec3F eye, Vec3F center, Vec3F up)
{
	cmmt_float_t fX = center.x - eye.x;
	cmmt_float_t fY = center.y - eye.y;
	cmmt_float_t fZ = center.z - eye.z;

	cmmt_float_t l = cmmtSqrt(fX * fX + fY * fY + fZ * fZ);
	fX /= l; fY /= l; fZ /= l;

	cmmt_float_t sX = up.y * fZ - up.z * fY;
	cmmt_float_t sY = up.z * fX - up.x * fZ;
	cmmt_float_t sZ = up.x * fY - up.y * fX;

	l = cmmtSqrt(sX * sX + sY * sY + sZ * sZ);
	sX /= l; sY /= l; sZ /= l;

	cmmt_float_t uX = fY * sZ - fZ * sY;
	cmmt_float_t uY = fZ * sX - fX * sZ;
	cmmt_float_t uZ = fX * sY - fY * sX;

	Mat4F matrix;
	matrix.m00 = sX;
	matrix.m01 = uX;
	matrix.m02 = fX;
	matrix.m03 = (cmmt_float_t)0.0;

	matrix.m10 = sY;
	matrix.m11 = uY;
	matrix.m12 = fY;
	matrix.m13 = (cmmt_float_t)0.0;

	matrix.m20 = sZ;
	matrix.m21 = uZ;
	matrix.m22 = fZ;
	matrix.m23 = (cmmt_float_t)0.0;

	matrix.m30 = -((sX * eye.x) + (sY * eye.y) + (sZ * eye.z));
	matrix.m31 = -((uX * eye.x) + (uY * eye.y) + (uZ * eye.z));
	matrix.m32 = -((fX * eye.x) + (fY * eye.y) + (fZ * eye.z));
	matrix.m33 = (cmmt_float_t)1.0;
	return matrix;
}

inline static Mat4I mat4I(
	cmmt_int_t m00, cmmt_int_t m01, cmmt_int_t m02, cmmt_int_t m03,
	cmmt_int_t m10, cmmt_int_t m11, cmmt_int_t m12, cmmt_int_t m13,
	cmmt_int_t m20, cmmt_int_t m21, cmmt_int_t m22, cmmt_int_t m23,
	cmmt_int_t m30, cmmt_int_t m31, cmmt_int_t m32, cmmt_int_t m33)
{
	Mat4I matrix;
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

inline static Mat4I addMat4I(Mat4I a, Mat4I b)
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
inline static Mat4I subMat4I(Mat4I a, Mat4I b)
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
inline static Mat4I mulMat4I(Mat4I a, Mat4I b)
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
inline static Mat4I divMat4I(Mat4I a, Mat4I b)
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
inline static Mat4I andMat4I(Mat4I a, Mat4I b)
{
	a.m00 &= b.m00;
	a.m01 &= b.m01;
	a.m02 &= b.m02;
	a.m03 &= b.m03;

	a.m10 &= b.m10;
	a.m11 &= b.m11;
	a.m12 &= b.m12;
	a.m13 &= b.m13;

	a.m20 &= b.m20;
	a.m21 &= b.m21;
	a.m22 &= b.m22;
	a.m23 &= b.m23;

	a.m30 &= b.m30;
	a.m31 &= b.m31;
	a.m32 &= b.m32;
	a.m33 &= b.m33;
	return a;
}
inline static Mat4I orMat4I(Mat4I a, Mat4I b)
{
	a.m00 |= b.m00;
	a.m01 |= b.m01;
	a.m02 |= b.m02;
	a.m03 |= b.m03;

	a.m10 |= b.m10;
	a.m11 |= b.m11;
	a.m12 |= b.m12;
	a.m13 |= b.m13;

	a.m20 |= b.m20;
	a.m21 |= b.m21;
	a.m22 |= b.m22;
	a.m23 |= b.m23;

	a.m30 |= b.m30;
	a.m31 |= b.m31;
	a.m32 |= b.m32;
	a.m33 |= b.m33;
	return a;
}
inline static Mat4I xorMat4I(Mat4I a, Mat4I b)
{
	a.m00 ^= b.m00;
	a.m01 ^= b.m01;
	a.m02 ^= b.m02;
	a.m03 ^= b.m03;

	a.m10 ^= b.m10;
	a.m11 ^= b.m11;
	a.m12 ^= b.m12;
	a.m13 ^= b.m13;

	a.m20 ^= b.m20;
	a.m21 ^= b.m21;
	a.m22 ^= b.m22;
	a.m23 ^= b.m23;

	a.m30 ^= b.m30;
	a.m31 ^= b.m31;
	a.m32 ^= b.m32;
	a.m33 ^= b.m33;
	return a;
}

inline static Mat4I addValMat4I(Mat4I matrix, cmmt_int_t value)
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
inline static Mat4I subValMat4I(Mat4I matrix, cmmt_int_t value)
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
inline static Mat4I mulValMat4I(Mat4I matrix, cmmt_int_t value)
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
inline static Mat4I divValMat4I(Mat4I matrix, cmmt_int_t value)
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
inline static Mat4I andValMat4I(Mat4I matrix, cmmt_int_t value)
{
	matrix.m00 &= value;
	matrix.m01 &= value;
	matrix.m02 &= value;
	matrix.m03 &= value;

	matrix.m10 &= value;
	matrix.m11 &= value;
	matrix.m12 &= value;
	matrix.m13 &= value;

	matrix.m20 &= value;
	matrix.m21 &= value;
	matrix.m22 &= value;
	matrix.m23 &= value;

	matrix.m30 &= value;
	matrix.m31 &= value;
	matrix.m32 &= value;
	matrix.m33 &= value;
	return matrix;
}
inline static Mat4I orValMat4I(Mat4I matrix, cmmt_int_t value)
{
	matrix.m00 |= value;
	matrix.m01 |= value;
	matrix.m02 |= value;
	matrix.m03 |= value;

	matrix.m10 |= value;
	matrix.m11 |= value;
	matrix.m12 |= value;
	matrix.m13 |= value;

	matrix.m20 |= value;
	matrix.m21 |= value;
	matrix.m22 |= value;
	matrix.m23 |= value;

	matrix.m30 |= value;
	matrix.m31 |= value;
	matrix.m32 |= value;
	matrix.m33 |= value;
	return matrix;
}
inline static Mat4I xorValMat4I(Mat4I matrix, cmmt_int_t value)
{
	matrix.m00 ^= value;
	matrix.m01 ^= value;
	matrix.m02 ^= value;
	matrix.m03 ^= value;

	matrix.m10 ^= value;
	matrix.m11 ^= value;
	matrix.m12 ^= value;
	matrix.m13 ^= value;

	matrix.m20 ^= value;
	matrix.m21 ^= value;
	matrix.m22 ^= value;
	matrix.m23 ^= value;

	matrix.m30 ^= value;
	matrix.m31 ^= value;
	matrix.m32 ^= value;
	matrix.m33 ^= value;
	return matrix;
}

inline static Mat4I negMat4I(Mat4I matrix)
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
inline static Mat4I notMat4I(Mat4I matrix)
{
	matrix.m00 = !matrix.m00;
	matrix.m01 = !matrix.m01;
	matrix.m02 = !matrix.m02;
	matrix.m03 = !matrix.m03;

	matrix.m10 = !matrix.m10;
	matrix.m11 = !matrix.m11;
	matrix.m12 = !matrix.m12;
	matrix.m13 = !matrix.m13;

	matrix.m20 = !matrix.m20;
	matrix.m21 = !matrix.m21;
	matrix.m22 = !matrix.m22;
	matrix.m23 = !matrix.m23;

	matrix.m30 = !matrix.m30;
	matrix.m31 = !matrix.m31;
	matrix.m32 = !matrix.m32;
	matrix.m33 = !matrix.m33;
	return matrix;
}

inline static Mat4I dotMat4I(Mat4I a, Mat4I b)
{
	Mat4I matrix;
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
inline static Vec4I dotVecMat4I(Vec4I vector, Mat4I matrix)
{
	Vec4I result;
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
inline static Vec4I dotMatVec4I(Mat4I matrix, Vec4I vector)
{
	Vec4I result;
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
inline static cmmt_int_t detMat4I(Mat4I matrix)
{
	cmmt_int_t f0 = matrix.m22 * matrix.m33 - matrix.m32 * matrix.m23;
	cmmt_int_t f1 = matrix.m21 * matrix.m33 - matrix.m31 * matrix.m23;
	cmmt_int_t f2 = matrix.m21 * matrix.m32 - matrix.m31 * matrix.m22;
	cmmt_int_t f3 = matrix.m20 * matrix.m33 - matrix.m30 * matrix.m23;
	cmmt_int_t f4 = matrix.m20 * matrix.m32 - matrix.m30 * matrix.m22;
	cmmt_int_t f5 = matrix.m20 * matrix.m31 - matrix.m30 * matrix.m21;

	cmmt_int_t c0 = matrix.m11 * f0 - matrix.m12 * f1 + matrix.m13 * f2;
	cmmt_int_t c1 = -(matrix.m10 * f0 - matrix.m12 * f3 + matrix.m13 * f4);
	cmmt_int_t c2 = matrix.m10 * f1 -matrix. m11 * f3 + matrix.m13 * f5;
	cmmt_int_t c3 = -(matrix.m10 * f2 - matrix.m11 * f4 + matrix.m12 * f5);

	return matrix.m00 * c0 + matrix.m01 * c1 + matrix.m02 * c2 + matrix.m03 * c3;
}
inline static Mat4I transposeMat4I(Mat4I matrix)
{
	Mat4I transposed;
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
