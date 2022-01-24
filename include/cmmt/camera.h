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
#include "cmmt/plane.h"
#include "cmmt/bounding.h"

// Camera NDC spaces
// ZeroOne - Vulkan API
// NegOne - OpenGL

typedef enum CameraType
{
	PERSP_CAMERA_TYPE = 0,
	ORTHO_CAMERA_TYPE = 1,
	CAMERA_TYPE_COUNT = 2,
} CameraType;

typedef struct PerspCamera
{
	uint8_t type;
	cmmt_float_t fieldOfView;
	cmmt_float_t aspectRatio;
	cmmt_float_t nearClipPlane;
	cmmt_float_t farClipPlane;
} PerspCamera;
typedef struct OrthoCamera
{
	uint8_t type;
	cmmt_float_t leftFrustum;
	cmmt_float_t rightFrustum;
	cmmt_float_t bottomFrustum;
	cmmt_float_t topFrustum;
	cmmt_float_t nearClipPlane;
	cmmt_float_t farClipPlane;
} OrthoCamera;
typedef union Camera
{
	PerspCamera persp;
	OrthoCamera ortho;
} Camera;

inline static Camera perspCamera(
	cmmt_float_t fieldOfView, cmmt_float_t aspectRatio,
	cmmt_float_t nearClipPlane, cmmt_float_t farClipPlane)
{
	Camera camera;
	camera.persp.type = PERSP_CAMERA_TYPE;
	camera.persp.fieldOfView = fieldOfView;
	camera.persp.aspectRatio = aspectRatio;
	camera.persp.nearClipPlane = nearClipPlane;
	camera.persp.farClipPlane = farClipPlane;
	return camera;
}
inline static Camera orthoCamera(
	cmmt_float_t leftFrustum, cmmt_float_t rightFrustum,
	cmmt_float_t bottomFrustum, cmmt_float_t topFrustum,
	cmmt_float_t nearClipPlane, cmmt_float_t farClipPlane)
{
	Camera camera;
	camera.ortho.type = ORTHO_CAMERA_TYPE;
	camera.ortho.leftFrustum = leftFrustum;
	camera.ortho.rightFrustum = rightFrustum;
	camera.ortho.bottomFrustum = bottomFrustum;
	camera.ortho.topFrustum = topFrustum;
	camera.ortho.nearClipPlane = nearClipPlane;
	camera.ortho.farClipPlane = farClipPlane;
	return camera;
}

inline static Mat4F perspZeroOneMat4F(
	cmmt_float_t fieldOfView, cmmt_float_t aspectRatio,
	cmmt_float_t nearClipPlane, cmmt_float_t farClipPlane)
{
	cmmt_float_t tanHalfFov = cmmtTan(fieldOfView * (cmmt_float_t)0.5);

	Mat4F matrix;
	matrix.m00 = (cmmt_float_t)1.0 / (aspectRatio * tanHalfFov);
	matrix.m01 = (cmmt_float_t)0.0;
	matrix.m02 = (cmmt_float_t)0.0;
	matrix.m03 = (cmmt_float_t)0.0;

	matrix.m10 = (cmmt_float_t)0.0;
	matrix.m11 = (cmmt_float_t)-1.0 / tanHalfFov;
	matrix.m12 = (cmmt_float_t)0.0;
	matrix.m13 = (cmmt_float_t)0.0;

	matrix.m20 = (cmmt_float_t)0.0;
	matrix.m21 = (cmmt_float_t)0.0;
	matrix.m22 = farClipPlane / (farClipPlane - nearClipPlane);
	matrix.m23 = (cmmt_float_t)1.0;

	matrix.m30 = (cmmt_float_t)0.0;
	matrix.m31 = (cmmt_float_t)0.0;
	matrix.m32 = -(farClipPlane * nearClipPlane) / (farClipPlane - nearClipPlane);
	matrix.m33 = (cmmt_float_t)0.0;
	return matrix;
}
inline static Mat4F perspNegOneMat4F(
	cmmt_float_t fieldOfView, cmmt_float_t aspectRatio,
	cmmt_float_t nearClipPlane, cmmt_float_t farClipPlane)
{
	cmmt_float_t tanHalfFov = cmmtTan(fieldOfView * (cmmt_float_t)0.5);

	Mat4F matrix;
	matrix.m00 = (cmmt_float_t)1.0 / (aspectRatio * tanHalfFov);
	matrix.m01 = (cmmt_float_t)0.0;
	matrix.m02 = (cmmt_float_t)0.0;
	matrix.m03 = (cmmt_float_t)0.0;

	matrix.m10 = (cmmt_float_t)0.0;
	matrix.m11 = (cmmt_float_t)1.0 / tanHalfFov;
	matrix.m12 = (cmmt_float_t)0.0;
	matrix.m13 = (cmmt_float_t)0.0;

	matrix.m20 = (cmmt_float_t)0.0;
	matrix.m21 = (cmmt_float_t)0.0;
	matrix.m22 = (farClipPlane + nearClipPlane) / (farClipPlane - nearClipPlane);
	matrix.m23 = (cmmt_float_t)1.0;

	matrix.m30 = (cmmt_float_t)0.0;
	matrix.m31 = (cmmt_float_t)0.0;
	matrix.m32 = -((cmmt_float_t)2.0 * farClipPlane * nearClipPlane) / (farClipPlane - nearClipPlane);
	matrix.m33 = (cmmt_float_t)0.0;
	return matrix;
}

inline static Mat4F orthoZeroOneMat4F(
	cmmt_float_t leftFrustum, cmmt_float_t rightFrustum,
	cmmt_float_t bottomFrustum, cmmt_float_t topFrustum,
	cmmt_float_t nearClipPlane, cmmt_float_t farClipPlane)
{
	Mat4F matrix;
	matrix.m00 = (cmmt_float_t)2.0 / (rightFrustum - leftFrustum);
	matrix.m01 = (cmmt_float_t)0.0;
	matrix.m02 = (cmmt_float_t)0.0;
	matrix.m03 = (cmmt_float_t)0.0;

	matrix.m10 = (cmmt_float_t)0.0;
	matrix.m11 = (cmmt_float_t)-2.0 / (topFrustum - bottomFrustum);
	matrix.m12 = (cmmt_float_t)0.0;
	matrix.m13 = (cmmt_float_t)0.0;

	matrix.m20 = (cmmt_float_t)0.0;
	matrix.m21 = (cmmt_float_t)0.0;
	matrix.m22 = (cmmt_float_t)1.0 / (farClipPlane - nearClipPlane);
	matrix.m23 = (cmmt_float_t)0.0;

	matrix.m30 = -(rightFrustum + leftFrustum) / (rightFrustum - leftFrustum);
	matrix.m31 = -(topFrustum + bottomFrustum) / (topFrustum - bottomFrustum);
	matrix.m32 = -nearClipPlane / (farClipPlane - nearClipPlane);
	matrix.m33 = (cmmt_float_t)1.0;
	return matrix;
}
inline static Mat4F orthoNegOneMat4F(
	cmmt_float_t leftFrustum, cmmt_float_t rightFrustum,
	cmmt_float_t bottomFrustum, cmmt_float_t topFrustum,
	cmmt_float_t nearClipPlane, cmmt_float_t farClipPlane)
{
	Mat4F matrix;
	matrix.m00 = (cmmt_float_t)2.0 / (rightFrustum - leftFrustum);
	matrix.m01 = (cmmt_float_t)0.0;
	matrix.m02 = (cmmt_float_t)0.0;
	matrix.m03 = (cmmt_float_t)0.0;

	matrix.m10 = (cmmt_float_t)0.0;
	matrix.m11 = (cmmt_float_t)2.0 / (topFrustum - bottomFrustum);
	matrix.m12 = (cmmt_float_t)0.0;
	matrix.m13 = (cmmt_float_t)0.0;

	matrix.m20 = (cmmt_float_t)0.0;
	matrix.m21 = (cmmt_float_t)0.0;
	matrix.m22 = (cmmt_float_t)2.0f / (farClipPlane - nearClipPlane);
	matrix.m23 = (cmmt_float_t)0.0;

	matrix.m30 = -(rightFrustum + leftFrustum) / (rightFrustum - leftFrustum);
	matrix.m31 = -(topFrustum + bottomFrustum) / (topFrustum - bottomFrustum);
	matrix.m32 = -(farClipPlane + nearClipPlane) / (farClipPlane - nearClipPlane);
	matrix.m33 = (cmmt_float_t)1.0;
	return matrix;
}

inline static Plane3F normFrustumPlane3F(Plane3F plane)
{
	cmmt_float_t length = cmmtSqrt(
		plane.normal.x * plane.normal.x +
		plane.normal.y * plane.normal.y +
		plane.normal.z * plane.normal.z);

	plane.normal.x /= length;
	plane.normal.y /= length;
	plane.normal.z /= length;
	plane.distance /= length;
	return plane;
}

inline static void frustumZeroOneMat4F(
	Mat4F frustum,
	Plane3F* leftPlane,
	Plane3F* rightPlane,
	Plane3F* bottomPlane,
	Plane3F* topPlane,
	Plane3F* backPlane,
	Plane3F* frontPlane,
	bool normalize)
{
	Plane3F left;
	left.normal.x = frustum.m03 + frustum.m00;
	left.normal.y = frustum.m13 + frustum.m10;
	left.normal.z = frustum.m23 + frustum.m20;
	left.distance = frustum.m33 + frustum.m30;

	Plane3F right;
	right.normal.x = frustum.m03 - frustum.m00;
	right.normal.y = frustum.m13 - frustum.m10;
	right.normal.z = frustum.m23 - frustum.m20;
	right.distance = frustum.m33 - frustum.m30;

	Plane3F bottom;
	bottom.normal.x = frustum.m03 + frustum.m01;
	bottom.normal.y = frustum.m13 + frustum.m11;
	bottom.normal.z = frustum.m23 + frustum.m21;
	bottom.distance = frustum.m33 + frustum.m31;

	Plane3F top;
	top.normal.x = frustum.m03 - frustum.m01;
	top.normal.y = frustum.m13 - frustum.m11;
	top.normal.z = frustum.m23 - frustum.m21;
	top.distance = frustum.m33 - frustum.m31;

	Plane3F back;
	back.normal.x = frustum.m02;
	back.normal.y = frustum.m12;
	back.normal.z = frustum.m22;
	back.distance = frustum.m32;

	Plane3F front;
	front.normal.x = frustum.m03 - frustum.m02;
	front.normal.y = frustum.m13 - frustum.m12;
	front.normal.z = frustum.m23 - frustum.m22;
	front.distance = frustum.m33 - frustum.m32;

	if (normalize)
	{
		left = normFrustumPlane3F(left);
		right = normFrustumPlane3F(right);
		bottom = normFrustumPlane3F(bottom);
		top = normFrustumPlane3F(top);
		back = normFrustumPlane3F(back);
		front = normFrustumPlane3F(front);
	}

	*leftPlane = left;
	*rightPlane = right;
	*bottomPlane = bottom;
	*topPlane = top;
	*backPlane = back;
	*frontPlane = front;
}
inline static void frustumNegOneMat4F(
	Mat4F frustum,
	Plane3F* leftPlane,
	Plane3F* rightPlane,
	Plane3F* bottomPlane,
	Plane3F* topPlane,
	Plane3F* backPlane,
	Plane3F* frontPlane,
	bool normalize)
{
	Plane3F left;
	left.normal.x = frustum.m03 + frustum.m00;
	left.normal.y = frustum.m13 + frustum.m10;
	left.normal.z = frustum.m23 + frustum.m20;
	left.distance = frustum.m33 + frustum.m30;

	Plane3F right;
	right.normal.x = frustum.m03 - frustum.m00;
	right.normal.y = frustum.m13 - frustum.m10;
	right.normal.z = frustum.m23 - frustum.m20;
	right.distance = frustum.m33 - frustum.m30;

	Plane3F bottom;
	bottom.normal.x = frustum.m03 + frustum.m01;
	bottom.normal.y = frustum.m13 + frustum.m11;
	bottom.normal.z = frustum.m23 + frustum.m21;
	bottom.distance = frustum.m33 + frustum.m31;

	Plane3F top;
	top.normal.x = frustum.m03 - frustum.m01;
	top.normal.y = frustum.m13 - frustum.m11;
	top.normal.z = frustum.m23 - frustum.m21;
	top.distance = frustum.m33 - frustum.m31;

	Plane3F back;
	back.normal.x = frustum.m03 + frustum.m02;
	back.normal.y = frustum.m13 + frustum.m12;
	back.normal.z = frustum.m23 + frustum.m22;
	back.distance = frustum.m33 + frustum.m32;

	Plane3F front;
	front.normal.x = frustum.m03 - frustum.m02;
	front.normal.y = frustum.m13 - frustum.m12;
	front.normal.z = frustum.m23 - frustum.m22;
	front.distance = frustum.m33 - frustum.m32;

	if (normalize)
	{
		left = normFrustumPlane3F(left);
		right = normFrustumPlane3F(right);
		bottom = normFrustumPlane3F(bottom);
		top = normFrustumPlane3F(top);
		back = normFrustumPlane3F(back);
		front = normFrustumPlane3F(front);
	}

	*leftPlane = left;
	*rightPlane = right;
	*bottomPlane = bottom;
	*topPlane = top;
	*backPlane = back;
	*frontPlane = front;
}

inline static bool isBoxInFrustumPlane3F(Plane3F plane, Box3F box)
{
	return
		!(distPlanePoint3F(plane, vec3F(
			box.minimum.x, box.minimum.y, box.minimum.z)) < (cmmt_float_t)0.0 &&
		distPlanePoint3F(plane, vec3F(
			box.minimum.x, box.minimum.y, box.maximum.z)) < (cmmt_float_t)0.0 &&
		distPlanePoint3F(plane, vec3F(
			box.minimum.x, box.maximum.y, box.minimum.z)) < (cmmt_float_t)0.0 &&
		distPlanePoint3F(plane, vec3F(
			box.minimum.x, box.maximum.y, box.maximum.z)) < (cmmt_float_t)0.0 &&
		distPlanePoint3F(plane, vec3F(
			box.maximum.x, box.minimum.y, box.minimum.z)) < (cmmt_float_t)0.0 &&
		distPlanePoint3F(plane, vec3F(
			box.maximum.x, box.minimum.y, box.maximum.z)) < (cmmt_float_t)0.0 &&
		distPlanePoint3F(plane, vec3F(
			box.maximum.x, box.maximum.y, box.minimum.z)) < (cmmt_float_t)0.0 &&
		distPlanePoint3F(plane, vec3F(
			box.maximum.x, box.maximum.y, box.maximum.z)) < (cmmt_float_t)0.0);
}
inline static bool isBoxInFrustum3F(
	Plane3F leftPlane, Plane3F rightPlane,
	Plane3F bottomPlane, Plane3F topPlane,
	Plane3F backPlane, Plane3F frontPlane,
	Box3F box)
{
	return
		isBoxInFrustumPlane3F(leftPlane, box) &&
		isBoxInFrustumPlane3F(rightPlane, box) &&
		isBoxInFrustumPlane3F(bottomPlane, box) &&
		isBoxInFrustumPlane3F(topPlane, box) &&
		isBoxInFrustumPlane3F(backPlane, box) &&
		isBoxInFrustumPlane3F(frontPlane, box);
}
