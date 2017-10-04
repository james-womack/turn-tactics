/******************************************************************************
File: Common.h
Created: 10/1/2017 8:27:28 PM
Copyright (c) 2017 Turn Tactics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Purpose: Holds common type defs for geometric and mathmatical types along with base operations

Author: James Womack

********************************************************************************/
#pragma once

#include <array>
#include <type_traits>
#include "../Common.h"

// Typedefs for Point, Size and Vector types
using Point2D = std::array<Int32, 2>;
using Point3D = std::array<Int32, 3>;
using Size2D = std::array<Int32, 2>;
using Size3D = std::array<Int32, 3>;
using Vector2D = std::array<Float32, 2>;
using Vector3D = std::array<Float32, 3>;

struct Rectange
{
  Size2D extents;
  Point2D location; // Location is upper-left corner of extents
};

struct Box // 3-D rectangular volume
{
  Size3D extents;
  Point3D location;
};

struct Ellipse
{
  Size2D radii;
  Point2D location; // This is the upper-left corner of bounding rectangle around ellipse
};

struct Sphere
{
  Size2D radii;
  Point3D location; // Upper-left corner of bounding box around sphere
};
