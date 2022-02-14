# CMMT ![CI](https://github.com/cfnptr/cmmt/actions/workflows/cmake.yml/badge.svg)

A library providing common mathematics functions: vectors, matrices, quaternions, etc.

## Features

* Vector (2D / 3D / 4D, float / int / uint /size)
* Matrix (4x4 float)
* Quaternion (float)
* Ray (2D / 3D float)
* Bounding box (2D / 3D float)
* Bounding sphere (2D / 3D float)
* Plane (2D / 3D float)
* Camera (orthographic / perspective float)
* Frustum culling (float)
* Color (float)
* Shadow bias (float)

## Build requirements

* C99 compiler
* [Git 2.30+](https://git-scm.com/)
* [CMake 3.10+](https://cmake.org/)

## Cloning

```
git clone https://github.com/cfnptr/cmmt
```

### CMake options

| Name             | Description                   | Default value |
|------------------|-------------------------------|---------------|
| CMMT_USE_INT64   | Use double precision integers | `OFF`         |
| CMMT_USE_FLOAT64 | Use double precision floats   | `OFF`         |

## Examples

You can find examples of use in [this](https://github.com/cfnptr/mpgx/) library source code.
