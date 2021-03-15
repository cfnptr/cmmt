#pragma once
#include <stdlib.h>
#include "cmmt/vector.h"

struct Box2F
{
	struct Vec2F minimum;
	struct Vec2F maximum;
};
struct Box3F
{
	struct Vec3F minimum;
	struct Vec3F maximum;
};

struct Sphere2F
{
	struct Vec2F position;
	float radiusPow;
};
struct Sphere3F
{
	struct Vec3F position;
	float radiusPow;
};

inline static struct Box2F box2F(
	struct Vec2F minimum,
	struct Vec2F maximum)
{
	struct Box2F box;
	box.minimum = minimum;
	box.maximum = maximum;
	return box;
}
inline static struct Box2F posSizeBox2F(
	struct Vec2F position,
	struct Vec2F size)
{
	size.x /= 2.0f;
	size.y /= 2.0f;

	struct Box2F box;
	box.minimum = vec2F(
		position.x - size.x,
		position.y - size.y);
	box.maximum = vec2F(
		position.x + size.x,
		position.y + size.y);
	return box;
}
inline static struct Box2F posExtBox2F(
	struct Vec2F position,
	struct Vec2F extent)
{
	struct Box2F box;
	box.minimum = vec2F(
		position.x - extent.x,
		position.y - extent.y);
	box.maximum = vec2F(
		position.x + extent.x,
		position.y + extent.y);
	return box;
}

inline static bool isPointInBox2F(
	struct Box2F box,
	struct Vec2F point)
{
	return
		(box.minimum.x <= point.x &&
		box.maximum.x >= point.x) &&
		(box.minimum.y <= point.y &&
		box.maximum.y >= point.y);
}
inline static bool isBoxInBox2F(
	struct Box2F a,
	struct Box2F b)
{
	return
		(a.minimum.x <= b.maximum.x &&
		a.maximum.x >= b.minimum.x) &&
		(a.minimum.y <= b.maximum.y &&
		a.maximum.y >= b.minimum.y);
}
inline static float rayCastBox2F(
	struct Box2F box,
	struct Vec2F position,
	struct Vec2F direction)
{
	float minX = (box.minimum.x - position.x) / direction.x;
	float maxX = (box.maximum.x - position.x) / direction.x;
	float minY = (box.minimum.y - position.y) / direction.y;
	float maxY = (box.maximum.y - position.y) / direction.y;

	float min = fmaxf(
		fminf(minX, maxX),
		fminf(minY, maxY));
	float max = fminf(
		fmaxf(minX, maxX),
		fmaxf(minY, maxY));

	if (min > max || max < 0.0f)
		return INFINITY;

	return min < 0.0f ? max : min;
}

inline static struct Box3F box3F(
	struct Vec3F minimum,
	struct Vec3F maximum)
{
	struct Box3F box;
	box.minimum = minimum;
	box.maximum = maximum;
	return box;
}
inline static struct Box3F posSizeBox3F(
	struct Vec3F position,
	struct Vec3F size)
{
	size.x /= 2.0f;
	size.y /= 2.0f;
	size.z /= 2.0f;

	struct Box3F box;
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
inline static struct Box3F posExtBox3F(
	struct Vec3F position,
	struct Vec3F extent)
{
	struct Box3F box;
	box.minimum = vec3F(
		position.x - extent.x,
		position.y - extent.y,
		position.z - extent.z);
	box.maximum = vec3F(
		position.x + extent.x,
		position.y + extent.y,
		position.z - extent.z);
	return box;
}

inline static bool isPointInBox3F(
	struct Box3F box,
	struct Vec3F point)
{
	return
		(box.minimum.x <= point.x &&
		box.maximum.x >= point.x) &&
		(box.minimum.y <= point.y &&
		box.maximum.y >= point.y) &&
		(box.minimum.z <= point.z &&
		box.maximum.z >= point.z);
}
inline static bool isBoxInBox3F(
	struct Box3F a,
	struct Box3F b)
{
	return
		(a.minimum.x <= b.maximum.x &&
		a.maximum.x >= b.minimum.x) &&
		(a.minimum.y <= b.maximum.y &&
		a.maximum.y >= b.minimum.y) &&
		(a.minimum.z <= b.maximum.z &&
		a.maximum.z >= b.minimum.z);
}
inline static float rayCastBox3F(
	struct Box3F box,
	struct Vec3F position,
	struct Vec3F direction)
{
	float minX = (box.minimum.x - position.x) / direction.x;
	float maxX = (box.maximum.x - position.x) / direction.x;
	float minY = (box.minimum.y - position.y) / direction.y;
	float maxY = (box.maximum.y - position.y) / direction.y;
	float minZ = (box.minimum.z - position.z) / direction.z;
	float maxZ = (box.maximum.z - position.z) / direction.z;

	float min = fmaxf(
		fmaxf(
			fminf(minX, maxX),
			fminf(minY, maxY)),
		fminf(minZ, maxZ));
	float max = fminf(
		fminf(
			fmaxf(minX, maxX),
			fmaxf(minY, maxY)),
		fmaxf(minZ, maxZ));

	if (min > max || max < 0.0f)
		return INFINITY;

	return min < 0.0f ? max : min;
}

inline static struct Sphere2F sphere2F(
	struct Vec2F position,
	float radiusPow)
{
	struct Sphere2F sphere;
	sphere.position = position;
	sphere.radiusPow = radiusPow;
	return sphere;
}
inline static struct Sphere2F spherePow2F(
	struct Vec2F position,
	float radius)
{
	struct Sphere2F sphere;
	sphere.position = position;
	sphere.radiusPow = radius * radius;
	return sphere;
}

inline static bool isPointInSphere2F(
	struct Sphere2F sphere,
	struct Vec2F point)
{
	return
		((point.x - sphere.position.x) *
		(point.x - sphere.position.x)) +
		((point.y - sphere.position.y) *
		(point.y - sphere.position.y)) <=
		sphere.radiusPow;
}
inline static bool isSphereInSphere2F(
	struct Sphere2F a,
	struct Sphere2F b)
{
	return
		((a.position.x - b.position.x) *
		(a.position.x - b.position.x)) +
		((a.position.y - b.position.y) *
		(a.position.y - b.position.y)) <=
		a.radiusPow + b.radiusPow;
}
inline static bool isSphereInBox2F(
	struct Sphere2F sphere,
	struct Box2F box)
{
	float x = fmaxf(box.minimum.x,
		fminf(sphere.position.x, box.maximum.x));
	float y = fmaxf(box.minimum.y,
		fminf(sphere.position.y, box.maximum.y));

	return
		((x - sphere.position.x) *
		(x - sphere.position.x)) +
		((y - sphere.position.y) *
		(y - sphere.position.y)) <=
		sphere.radiusPow;
}

inline static float rayCastSphere2F(
	struct Sphere2F sphere,
	struct Vec2F position,
	struct Vec2F direction)
{
	float distance =
		((sphere.position.x - position.x) *
		(sphere.position.x - position.x)) +
		((sphere.position.y - position.y) *
		(sphere.position.y - position.y));
	float dot =
		((sphere.position.x - position.x) * direction.x) +
		((sphere.position.y - position.y) * direction.y);

	if ((sphere.radiusPow - distance) + (dot * dot) < 0.0f)
		return INFINITY;

	distance = distance < sphere.radiusPow ?
		dot + sqrtf(sphere.radiusPow - (distance - (dot * dot))) :
		dot - sqrtf(sphere.radiusPow - (distance - (dot * dot)));
	return distance < 0.0f ? INFINITY : distance;
}

inline static struct Sphere3F sphere3F(
	struct Vec3F position,
	float radiusPow)
{
	struct Sphere3F sphere;
	sphere.position = position;
	sphere.radiusPow = radiusPow;
	return sphere;
}
inline static struct Sphere3F spherePow3F(
	struct Vec3F position,
	float radius)
{
	struct Sphere3F sphere;
	sphere.position = position;
	sphere.radiusPow = radius * radius;
	return sphere;
}

inline static bool isPointInSphere3F(
	struct Sphere3F sphere,
	struct Vec3F point)
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
inline static bool isSphereInSphere3F(
	struct Sphere3F a,
	struct Sphere3F b)
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
inline static bool isSphereInBox3F(
	struct Sphere3F sphere,
	struct Box3F box)
{
	float x = fmaxf(box.minimum.x,
		fminf(sphere.position.x, box.maximum.x));
	float y = fmaxf(box.minimum.y,
		fminf(sphere.position.y, box.maximum.y));
	float z = fmaxf(box.minimum.z,
		fminf(sphere.position.z, box.maximum.z));

	return
		((x - sphere.position.x) *
		(x - sphere.position.x)) +
		((y - sphere.position.y) *
		(y - sphere.position.y)) +
		((z - sphere.position.z) *
		(z - sphere.position.z)) <=
		sphere.radiusPow;
}
inline static float rayCastSphere3F(
	struct Sphere3F sphere,
	struct Vec3F position,
	struct Vec3F direction)
{
	float distance =
		((position.x - sphere.position.x) *
		(position.x - sphere.position.x)) +
		((position.y - sphere.position.y) *
		(position.y - sphere.position.y)) +
		((position.z - sphere.position.z) *
		(position.z - sphere.position.z));
	float dot =
		(position.x - sphere.position.x) * direction.x +
		(position.y - sphere.position.y) * direction.y +
		(position.z - sphere.position.z) * direction.z;

	if (sphere.radiusPow - distance + (dot * dot) < 0.0f)
		return INFINITY;

	distance = distance < sphere.radiusPow ?
		dot + sqrtf(sphere.radiusPow - (distance - (dot * dot))) :
		dot - sqrtf(sphere.radiusPow - (distance - (dot * dot)));
	return distance < 0.0f ? INFINITY : distance;
}
