#pragma once
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
	struct Vec2F center;
	float radiusPow;
};
struct Sphere3F
{
	struct Vec3F center;
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
inline static struct Box2F centerSizeBox2F(
	struct Vec2F center,
	struct Vec2F size)
{
	size.x /= 2.0f;
	size.y /= 2.0f;

	struct Box2F box;
	box.minimum = vec2F(
		center.x - size.x,
		center.y - size.y);
	box.maximum = vec2F(
		center.x + size.x,
		center.y + size.y);
	return box;
}
inline static struct Box2F centerExtentBox2F(
	struct Vec2F center,
	struct Vec2F extent)
{
	struct Box2F box;
	box.minimum = vec2F(
		center.x - extent.x,
		center.y - extent.y);
	box.maximum = vec2F(
		center.x + extent.x,
		center.y + extent.y);
	return box;
}

inline static bool isPointInBox2F(
	struct Box2F box,
	struct Vec2F point)
{
	return
		box.minimum.x <= point.x &&
		box.maximum.x >= point.x &&
		box.minimum.y <= point.y &&
		box.maximum.y >= point.y;
}
inline static bool isBoxInBox2F(
	struct Box2F a,
	struct Box2F b)
{
	return
		a.minimum.x <= b.maximum.x &&
		a.maximum.x >= b.minimum.x &&
		a.minimum.y <= b.maximum.y &&
		a.maximum.y >= b.minimum.y;
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
inline static struct Box3F centerSizeBox3F(
	struct Vec3F center,
	struct Vec3F size)
{
	size.x /= 2.0f;
	size.y /= 2.0f;
	size.z /= 2.0f;

	struct Box3F box;
	box.minimum = vec3F(
		center.x - size.x,
		center.y - size.y,
		center.z - size.z);
	box.maximum = vec3F(
		center.x + size.x,
		center.y + size.y,
		center.z + size.z);
	return box;
}
inline static struct Box3F centerExtentBox3F(
	struct Vec3F center,
	struct Vec3F extent)
{
	struct Box3F box;
	box.minimum = vec3F(
		center.x - extent.x,
		center.y - extent.y,
		center.z - extent.z);
	box.maximum = vec3F(
		center.x + extent.x,
		center.y + extent.y,
		center.z - extent.z);
	return box;
}

inline static bool isPointInBox3F(
	struct Box3F box,
	struct Vec3F point)
{
	return
		box.minimum.x <= point.x &&
		box.maximum.x >= point.x &&
		box.minimum.y <= point.y &&
		box.maximum.y >= point.y &&
		box.minimum.z <= point.z &&
		box.maximum.z >= point.z;
}
inline static bool isBoxInBox3F(
	struct Box3F a,
	struct Box3F b)
{
	return
		a.minimum.x <= b.maximum.x &&
		a.maximum.x >= b.minimum.x &&
		a.minimum.y <= b.maximum.y &&
		a.maximum.y >= b.minimum.y &&
		a.minimum.z <= b.maximum.z &&
		a.maximum.z >= b.minimum.z;
}

inline static struct Sphere2F powSphere2F(
	struct Vec2F center,
	float radiusPow)
{
	struct Sphere2F sphere;
	sphere.center = center;
	sphere.radiusPow = radiusPow;
	return sphere;
}
inline static struct Sphere2F sphere2F(
	struct Vec2F center,
	float radius)
{
	struct Sphere2F sphere;
	sphere.center = center;
	sphere.radiusPow = radius * radius;
	return sphere;
}

inline static bool isPointInSphere2F(
	struct Sphere2F sphere,
	struct Vec2F point)
{
	return
		(sphere.center.x * (sphere.center.x - point.x)) +
		(sphere.center.y * (sphere.center.y - point.y)) <=
		sphere.radiusPow;
}
inline static bool isSphereInSphere2F(
	struct Sphere2F a,
	struct Sphere2F b)
{
	return
		(a.center.x * (a.center.x - b.center.x)) +
		(a.center.y * (a.center.y - b.center.y)) <=
		a.radiusPow + b.radiusPow;
}
inline static bool isSphereInBox2F(
	struct Sphere2F sphere,
	struct Box2F box)
{
	struct Vec2F point = vec2F(
		fmaxf(box.minimum.x, fminf(sphere.center.x, box.maximum.x)),
		fmaxf(box.minimum.y, fminf(sphere.center.y, box.maximum.y)));

	return
		(sphere.center.x * (sphere.center.x - point.x)) +
		(sphere.center.y * (sphere.center.y - point.y)) <=
		sphere.radiusPow;
}

inline static struct Sphere3F powSphere3F(
	struct Vec3F center,
	float radiusPow)
{
	struct Sphere3F sphere;
	sphere.center = center;
	sphere.radiusPow = radiusPow;
	return sphere;
}
inline static struct Sphere3F sphere3F(
	struct Vec3F center,
	float radius)
{
	struct Sphere3F sphere;
	sphere.center = center;
	sphere.radiusPow = radius * radius;
	return sphere;
}

inline static bool isPointInSphere3F(
	struct Sphere3F sphere,
	struct Vec3F point)
{
	return
		(sphere.center.x * (sphere.center.x - point.x)) +
		(sphere.center.y * (sphere.center.y - point.y)) +
		(sphere.center.z * (sphere.center.z - point.z)) <=
		sphere.radiusPow;
}
inline static bool isSphereInSphere3F(
	struct Sphere3F a,
	struct Sphere3F b)
{
	return
		(a.center.x * (a.center.x - b.center.x)) +
		(a.center.y * (a.center.y - b.center.y)) +
		(a.center.z * (a.center.z - b.center.z))<=
		a.radiusPow + b.radiusPow;
}
inline static bool isSphereInBox3F(
	struct Sphere3F sphere,
	struct Box3F box)
{
	struct Vec3F point = vec3F(
		fmaxf(box.minimum.x, fminf(sphere.center.x, box.maximum.x)),
		fmaxf(box.minimum.y, fminf(sphere.center.y, box.maximum.y)),
		fmaxf(box.minimum.z, fminf(sphere.center.z, box.maximum.z)));

	return
		(sphere.center.x * (sphere.center.x - point.x)) +
		(sphere.center.y * (sphere.center.y - point.y)) +
		(sphere.center.z * (sphere.center.z - point.z)) <=
		sphere.radiusPow;
}
