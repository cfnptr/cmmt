#pragma once
#include "vector.h"

typedef struct Ray2F
{
	Vec2F position;
	Vec2F direction;
} Ray2F;
typedef struct Ray3F
{
	Vec3F position;
	Vec3F direction;
} Ray3F;

inline static Ray2F ray2F(
	Vec2F position,
	Vec2F direction)
{
	Ray2F ray;
	ray.position = position;
	ray.direction = direction;
	return ray;
}

inline static Ray3F ray3F(
	Vec3F position,
	Vec3F direction)
{
	Ray3F ray;
	ray.position = position;
	ray.direction = direction;
	return ray;
}
