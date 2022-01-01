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

typedef struct Plane2F
{
	Vec2F normal;
	float distance;
} Plane2F;
typedef struct Plane3F
{
	Vec3F normal;
	float distance;
} Plane3F;

inline static Plane2F plane2F(
	Vec2F normal,
	float distance)
{
	Plane2F plane;
	plane.normal = normal;
	plane.distance = distance;
	return plane;
}

inline static float distPlanePoint2F(
	Plane2F plane,
	Vec2F point)
{
	return
		plane.normal.x * point.x +
		plane.normal.y * point.y +
		plane.distance;
}
inline static bool compPlane2F(
	Plane2F a,
	Plane2F b)
{
	return
		a.normal.x == b.normal.x &&
		a.normal.y == b.normal.y &&
		a.distance == b.distance;
}

inline static Plane3F plane3F(
	Vec3F normal,
	float distance)
{
	Plane3F plane;
	plane.normal = normal;
	plane.distance = distance;
	return plane;
}
inline static Plane3F pointPlane3F(
	Vec3F a,
	Vec3F b,
	Vec3F c)
{
	// TODO: check if correct
	float cX = (b.y - a.y) * (c.z - a.z) - (b.z - a.z) * (c.y - a.y);
	float cY = (b.z - a.z) * (c.x - a.x) - (b.x - a.x) * (c.z - a.z);
	float cZ = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

	float length = sqrtf((cX * cX) + (cY * cY) + (cZ * cZ));

	cX /= length;
	cY /= length;
	cZ /= length;

	float distance = (cX * a.x) + (cY * a.y) + (cZ * a.z);

	Plane3F plane;
	plane.normal.x = cX;
	plane.normal.y = cY;
	plane.normal.z = cZ;
	plane.distance = distance;
	return plane;
}

inline static float distPlanePoint3F(
	Plane3F plane,
	Vec3F point)
{
	return
		plane.normal.x * point.x +
		plane.normal.y * point.y +
		plane.normal.z * point.z +
		plane.distance;
}
inline static bool compPlane3F(
	Plane3F a,
	Plane3F b)
{
	return
		a.normal.x == b.normal.x &&
		a.normal.y == b.normal.y &&
		a.normal.z == b.normal.z &&
		a.distance == b.distance;
}
