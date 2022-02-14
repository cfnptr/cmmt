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
#include "cmmt/ray.h"

typedef struct Box2F
{
	Vec2F minimum;
	Vec2F maximum;
} Box2F;
typedef struct Box3F
{
	Vec3F minimum;
	Vec3F maximum;
} Box3F;

typedef struct Sphere2F
{
	Vec2F position;
	cmmt_float_t radiusPow;
} Sphere2F;
typedef struct Sphere3F
{
	Vec3F position;
	cmmt_float_t radiusPow;
} Sphere3F;

static const Box2F oneSizeBox2F = {
	(cmmt_float_t)-0.5, (cmmt_float_t)-0.5,
	(cmmt_float_t)0.5, (cmmt_float_t)0.5,
};
static const Box2F oneExtBox2F = {
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
	(cmmt_float_t)1.0, (cmmt_float_t)1.0,
};

static const Box3F oneSizeBox3F = {
	(cmmt_float_t)-0.5, (cmmt_float_t)-0.5, (cmmt_float_t)-0.5,
	(cmmt_float_t)0.5, (cmmt_float_t)0.5, (cmmt_float_t)0.5,
};
static const Box3F oneExtBox3F = {
	(cmmt_float_t)-1.0, (cmmt_float_t)-1.0, (cmmt_float_t)-1.0,
	(cmmt_float_t)1.0, (cmmt_float_t)1.0, (cmmt_float_t)1.0,
};

static const Sphere2F oneSizeSphere2F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.25,
};
static const Sphere2F oneExtSphere2F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)1.0,
};

static const Sphere3F oneSizeSphere3F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.25,
};
static const Sphere3F oneExtSphere3F = {
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)1.0,
};

inline static Box2F box2F(Vec2F minimum, Vec2F maximum)
{
	Box2F box;
	box.minimum = minimum;
	box.maximum = maximum;
	return box;
}
inline static Box2F posSizeBox2F(Vec2F position, Vec2F size)
{
	size.x *= (cmmt_float_t)0.5;
	size.y *= (cmmt_float_t)0.5;

	Box2F box;
	box.minimum = vec2F(
		position.x - size.x,
		position.y - size.y);
	box.maximum = vec2F(
		position.x + size.x,
		position.y + size.y);
	return box;
}
inline static Box2F posExtBox2F(Vec2F position, Vec2F extent)
{
	Box2F box;
	box.minimum = vec2F(
		position.x - extent.x,
		position.y - extent.y);
	box.maximum = vec2F(
		position.x + extent.x,
		position.y + extent.y);
	return box;
}

inline static Vec2F getPosBox2F(Box2F box)
{
	return vec2F(
		(box.minimum.x + box.maximum.x) * (cmmt_float_t)0.5,
		(box.minimum.y + box.maximum.y) * (cmmt_float_t)0.5);
}
inline static Vec2F getSizeBox2F(Box2F box)
{
	return vec2F(
		(box.maximum.x - ((box.minimum.x + box.maximum.x) * (cmmt_float_t)0.5)) * (cmmt_float_t)2.0,
		(box.maximum.y - ((box.minimum.y + box.maximum.y) * (cmmt_float_t)0.5)) * (cmmt_float_t)2.0);
}
inline static Vec2F getExtBox2F(Box2F box)
{
	return vec2F(
		box.maximum.x - ((box.minimum.x + box.maximum.x) * (cmmt_float_t)0.5),
		box.maximum.y - ((box.minimum.y + box.maximum.y) * (cmmt_float_t)0.5));
}

inline static bool isPointInBox2F(Box2F box, Vec2F point)
{
	return
		(box.minimum.x <= point.x &&
		box.maximum.x >= point.x) &&
		(box.minimum.y <= point.y &&
		box.maximum.y >= point.y);
}
inline static bool isBoxInBox2F(Box2F a, Box2F b)
{
	return
		(a.minimum.x <= b.maximum.x &&
		a.maximum.x >= b.minimum.x) &&
		(a.minimum.y <= b.maximum.y &&
		a.maximum.y >= b.minimum.y);
}
inline static cmmt_float_t castRayBox2F(Box2F box, Ray2F ray)
{
	cmmt_float_t minX = (box.minimum.x - ray.position.x) / ray.direction.x;
	cmmt_float_t maxX = (box.maximum.x - ray.position.x) / ray.direction.x;
	cmmt_float_t minY = (box.minimum.y - ray.position.y) / ray.direction.y;
	cmmt_float_t maxY = (box.maximum.y - ray.position.y) / ray.direction.y;

	cmmt_float_t min = cmmtFmax(
		cmmtFmin(minX, maxX),
		cmmtFmin(minY, maxY));
	cmmt_float_t max = cmmtFmin(
		cmmtFmax(minX, maxX),
		cmmtFmax(minY, maxY));

	if (min > max || max < (cmmt_float_t)0.0)
		return INFINITY;

	return min < (cmmt_float_t)0.0 ? max : min;
}

inline static Box3F box3F(Vec3F minimum, Vec3F maximum)
{
	Box3F box;
	box.minimum = minimum;
	box.maximum = maximum;
	return box;
}
inline static Box3F posSizeBox3F(Vec3F position, Vec3F size)
{
	size.x *= (cmmt_float_t)0.5;
	size.y *= (cmmt_float_t)0.5;
	size.z *= (cmmt_float_t)0.5;

	Box3F box;
	box.minimum = vec3F(
		position.x - size.x,
		position.y - size.y,
		position.z - size.z);
	box.maximum = vec3F(
		position.x + size.x,
		position.y + size.y,
		position.z + size.z);
	return box;
}
inline static Box3F posExtBox3F(Vec3F position, Vec3F extent)
{
	Box3F box;
	box.minimum = vec3F(
		position.x - extent.x,
		position.y - extent.y,
		position.z - extent.z);
	box.maximum = vec3F(
		position.x + extent.x,
		position.y + extent.y,
		position.z + extent.z);
	return box;
}

inline static Vec3F getPosBox3F(Box3F box)
{
	return vec3F(
		(box.minimum.x + box.maximum.x) * (cmmt_float_t)0.5,
		(box.minimum.y + box.maximum.y) * (cmmt_float_t)0.5,
		(box.minimum.z + box.maximum.z) * (cmmt_float_t)0.5);
}
inline static Vec3F getSizeBox3F(Box3F box)
{
	return vec3F(
		(box.maximum.x - ((box.minimum.x + box.maximum.x) * (cmmt_float_t)0.5)) * (cmmt_float_t)2.0,
		(box.maximum.y - ((box.minimum.y + box.maximum.y) * (cmmt_float_t)0.5)) * (cmmt_float_t)2.0,
		(box.maximum.z - ((box.minimum.z + box.maximum.z) * (cmmt_float_t)0.5)) * (cmmt_float_t)2.0);
}
inline static Vec3F getExtBox3F(Box3F box)
{
	return vec3F(
		box.maximum.x - ((box.minimum.x + box.maximum.x) * (cmmt_float_t)0.5),
		box.maximum.y - ((box.minimum.y + box.maximum.y) * (cmmt_float_t)0.5),
		box.maximum.z - ((box.minimum.z + box.maximum.z) * (cmmt_float_t)0.5));
}

inline static bool isPointInBox3F(Box3F box, Vec3F point)
{
	return
		(box.minimum.x <= point.x &&
		box.maximum.x >= point.x) &&
		(box.minimum.y <= point.y &&
		box.maximum.y >= point.y) &&
		(box.minimum.z <= point.z &&
		box.maximum.z >= point.z);
}
inline static bool isBoxInBox3F(Box3F a, Box3F b)
{
	return
		(a.minimum.x <= b.maximum.x &&
		a.maximum.x >= b.minimum.x) &&
		(a.minimum.y <= b.maximum.y &&
		a.maximum.y >= b.minimum.y) &&
		(a.minimum.z <= b.maximum.z &&
		a.maximum.z >= b.minimum.z);
}
inline static cmmt_float_t castRayBox3F(Box3F box, Ray3F ray)
{
	cmmt_float_t minX = (box.minimum.x - ray.position.x) / ray.direction.x;
	cmmt_float_t maxX = (box.maximum.x - ray.position.x) / ray.direction.x;
	cmmt_float_t minY = (box.minimum.y - ray.position.y) / ray.direction.y;
	cmmt_float_t maxY = (box.maximum.y - ray.position.y) / ray.direction.y;
	cmmt_float_t minZ = (box.minimum.z - ray.position.z) / ray.direction.z;
	cmmt_float_t maxZ = (box.maximum.z - ray.position.z) / ray.direction.z;

	cmmt_float_t min = cmmtFmax(
		cmmtFmax(cmmtFmin(minX, maxX), cmmtFmin(minY, maxY)),
		cmmtFmin(minZ, maxZ));
	cmmt_float_t max = cmmtFmin(
		cmmtFmin(cmmtFmax(minX, maxX), cmmtFmax(minY, maxY)),
		cmmtFmax(minZ, maxZ));

	if (min > max || max < (cmmt_float_t)0.0)
		return INFINITY;

	return min < (cmmt_float_t)0.0 ? max : min;
}

inline static Sphere2F sphere2F(Vec2F position, cmmt_float_t radiusPow)
{
	Sphere2F sphere;
	sphere.position = position;
	sphere.radiusPow = radiusPow;
	return sphere;
}
inline static Sphere2F spherePow2F(Vec2F position, cmmt_float_t radius)
{
	Sphere2F sphere;
	sphere.position = position;
	sphere.radiusPow = radius * radius;
	return sphere;
}

inline static bool isPointInSphere2F(Sphere2F sphere, Vec2F point)
{
	return
		((point.x - sphere.position.x) *
		(point.x - sphere.position.x)) +
		((point.y - sphere.position.y) *
		(point.y - sphere.position.y)) <=
		sphere.radiusPow;
}
inline static bool isSphereInSphere2F(Sphere2F a, Sphere2F b)
{
	return
		((a.position.x - b.position.x) *
		(a.position.x - b.position.x)) +
		((a.position.y - b.position.y) *
		(a.position.y - b.position.y)) <=
		a.radiusPow + b.radiusPow;
}
inline static bool isSphereInBox2F(Sphere2F sphere, Box2F box)
{
	cmmt_float_t x = cmmtFmax(box.minimum.x,
		cmmtFmin(sphere.position.x, box.maximum.x));
	cmmt_float_t y = cmmtFmax(box.minimum.y,
		cmmtFmin(sphere.position.y, box.maximum.y));

	return
		((x - sphere.position.x) *
		(x - sphere.position.x)) +
		((y - sphere.position.y) *
		(y - sphere.position.y)) <=
		sphere.radiusPow;
}

inline static cmmt_float_t castRaySphere2F(Sphere2F sphere, Ray2F ray)
{
	cmmt_float_t distance =
		((sphere.position.x - ray.position.x) *
		(sphere.position.x - ray.position.x)) +
		((sphere.position.y - ray.position.y) *
		(sphere.position.y - ray.position.y));
	cmmt_float_t dot =
		((sphere.position.x - ray.position.x) * ray.direction.x) +
		((sphere.position.y - ray.position.y) * ray.direction.y);

	if ((sphere.radiusPow - distance) + (dot * dot) < (cmmt_float_t)0.0)
		return INFINITY;

	distance = distance < sphere.radiusPow ?
		dot + cmmtSqrt(sphere.radiusPow - (distance - (dot * dot))) :
		dot - cmmtSqrt(sphere.radiusPow - (distance - (dot * dot)));
	return distance < (cmmt_float_t)0.0 ? INFINITY : distance;
}

inline static Sphere3F sphere3F(Vec3F position, cmmt_float_t radiusPow)
{
	Sphere3F sphere;
	sphere.position = position;
	sphere.radiusPow = radiusPow;
	return sphere;
}
inline static Sphere3F spherePow3F(Vec3F position, cmmt_float_t radius)
{
	Sphere3F sphere;
	sphere.position = position;
	sphere.radiusPow = radius * radius;
	return sphere;
}

inline static bool isPointInSphere3F(Sphere3F sphere, Vec3F point)
{
	return
		((point.x - sphere.position.x) *
		(point.x - sphere.position.x)) +
		((point.y - sphere.position.y) *
		(point.y - sphere.position.y)) +
		((point.z - sphere.position.z) *
		(point.z - sphere.position.z)) <=
		sphere.radiusPow;
}
inline static bool isSphereInSphere3F(Sphere3F a, Sphere3F b)
{
	return
		((a.position.x - b.position.x) *
		(a.position.x - b.position.x)) +
		((a.position.y - b.position.y) *
		(a.position.y - b.position.y)) +
		((a.position.z - b.position.z) *
		(a.position.z - b.position.z)) <=
		a.radiusPow + b.radiusPow;
}
inline static bool isSphereInBox3F(Sphere3F sphere, Box3F box)
{
	cmmt_float_t x = cmmtFmax(box.minimum.x,
		cmmtFmin(sphere.position.x, box.maximum.x));
	cmmt_float_t y = cmmtFmax(box.minimum.y,
		cmmtFmin(sphere.position.y, box.maximum.y));
	cmmt_float_t z = cmmtFmax(box.minimum.z,
		cmmtFmin(sphere.position.z, box.maximum.z));

	return
		((x - sphere.position.x) *
		(x - sphere.position.x)) +
		((y - sphere.position.y) *
		(y - sphere.position.y)) +
		((z - sphere.position.z) *
		(z - sphere.position.z)) <=
		sphere.radiusPow;
}
inline static cmmt_float_t castRaySphere3F(Sphere3F sphere, Ray3F ray)
{
	cmmt_float_t distance =
		((ray.position.x - sphere.position.x) *
		(ray.position.x - sphere.position.x)) +
		((ray.position.y - sphere.position.y) *
		(ray.position.y - sphere.position.y)) +
		((ray.position.z - sphere.position.z) *
		(ray.position.z - sphere.position.z));
	cmmt_float_t dot =
		(ray.position.x - sphere.position.x) * ray.direction.x +
		(ray.position.y - sphere.position.y) * ray.direction.y +
		(ray.position.z - sphere.position.z) * ray.direction.z;

	if (sphere.radiusPow - distance + (dot * dot) < (cmmt_float_t)0.0)
		return INFINITY;

	distance = distance < sphere.radiusPow ?
		dot + cmmtSqrt(sphere.radiusPow - (distance - (dot * dot))) :
		dot - cmmtSqrt(sphere.radiusPow - (distance - (dot * dot)));
	return distance < (cmmt_float_t)0.0 ? INFINITY : distance;
}
