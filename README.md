# CMMT
![CI](https://github.com/cfnptr/cmmt/actions/workflows/cmake.yml/badge.svg)

## Features
* Vector (2D/3D/4D, float/int/uint/size)
* Matrix (4x4 float)
* Quaternion (float)
* Ray (2D/3D float)
* Bounding box (2D/3D float)
* Bounding sphere (2D/3D float)
* Plane (2D/3D float)
* Camera (ortho/persp float)
* Frustum culling (float)
* Color (float)
* Shadow bias (float)

## Build requirements
* C99 compiler
* [CMake 3.10+](https://cmake.org/)

## Cloning
```
git clone https://github.com/cfnptr/cmmt
cd cmmt
```

## Building
```
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/
cmake --build build/
```

## Examples
You can find examples of use in [this](https://github.com/cfnptr/mpgx/) library source code.
