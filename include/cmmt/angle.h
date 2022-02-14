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
#include "cmmt/common.h"

inline static cmmt_float_t radToDeg(cmmt_float_t radians)
{
	return radians * (cmmt_float_t)(180.0 / M_PI);
}
inline static cmmt_float_t degToRad(cmmt_float_t degrees)
{
	return degrees * (cmmt_float_t)(M_PI / 180.0);
}
