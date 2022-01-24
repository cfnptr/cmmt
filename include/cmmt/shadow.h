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

// Camera NDC spaces
// ZeroOne - Vulkan API
// NegOne - OpenGL

static const Mat4F shadBiasZeroOneF = {
	(cmmt_float_t)0.5, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.5, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)1.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.5, (cmmt_float_t)0.5, (cmmt_float_t)0.0, (cmmt_float_t)1.0,
};
static const Mat4F shadBiasNegOneF = {
	(cmmt_float_t)0.5, (cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.5, (cmmt_float_t)0.0, (cmmt_float_t)0.0,
	(cmmt_float_t)0.0, (cmmt_float_t)0.0, (cmmt_float_t)0.5, (cmmt_float_t)0.0,
	(cmmt_float_t)0.5, (cmmt_float_t)0.5, (cmmt_float_t)0.5, (cmmt_float_t)1.0,
};
