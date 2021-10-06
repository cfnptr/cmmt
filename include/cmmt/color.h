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

inline static float colToVal(
	uint8_t r)
{
	return (float)r / 255.0f;
}
inline static Vec2F colToVec2F(
	uint8_t r, uint8_t g)
{
	return vec2F(
		(float)r / 255.0f,
		(float)g / 255.0f);
}
inline static Vec3F colToVec3F(
	uint8_t r, uint8_t g, uint8_t b)
{
	return vec3F(
		(float)r / 255.0f,
		(float)g / 255.0f,
		(float)b / 255.0f);
}
inline static Vec4F colToVec4F(
	uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return vec4F(
		(float)r / 255.0f,
		(float)g / 255.0f,
		(float)b / 255.0f,
		(float)a / 255.0f);
}
