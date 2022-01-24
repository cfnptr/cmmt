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

inline static Ray2F ray2F(Vec2F position, Vec2F direction)
{
	Ray2F ray;
	ray.position = position;
	ray.direction = direction;
	return ray;
}
inline static Ray3F ray3F(Vec3F position, Vec3F direction)
{
	Ray3F ray;
	ray.position = position;
	ray.direction = direction;
	return ray;
}
