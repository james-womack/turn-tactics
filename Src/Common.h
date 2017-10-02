#pragma once
#include <array>

// Type defs for raw characters
using UChar = unsigned char;
using Char = char;
using WChar = wchar_t;

// Typedef for byte
using Byte = char;

// Type defs for integer types
using Int8 = char;
using UInt8 = unsigned char;
using Int16 = short;
using UInt16 = unsigned short;
using Int32 = int;
using UInt32 = unsigned int;
using Int64 = long;
using UInt64 = unsigned long;

// Typedefs for floating point types
using Float32 = float;
using Float64 = double;

namespace lse
{
  enum class Renderer : UChar
  {
    Undefined,
    SDL,
    OpenGL // Not implemented yet...
  };
}