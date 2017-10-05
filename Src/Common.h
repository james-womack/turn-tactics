#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

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
  using String = std::string;

  // Maps stl containers to alias's incase we implement own data
  // structures later
  namespace containers
  {
    template<class TKey, class TValue>
    using Map = std::map<TKey, TValue>;

    template<class TKey, class TValue>
    using UnorderedMap = std::unordered_map<TKey, TValue>;

    template<class TValue>
    using Vector = std::vector<TValue>;
    

  }

  // Converts enum class to underlying type
  template<typename E>
  constexpr auto to_integral(E e) -> typename std::underlying_type<E>::type {
    return static_cast<typename std::underlying_type<E>::type>(e);
  }

  // Converts a string to upper case inplace (replacing old string)
  inline void to_upper_inplace(String& str)
  {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  }

  // Converts a string to upper case creating a copy and returning it
  inline String to_upper(String str)
  {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return std::move(str);
  }

  // Converts a string to lower case inplace (replacing old string)
  inline void to_lower_inplace(String& str)
  {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  }

  // Converts a string to lower case creating a copy and returning it
  inline String to_lower(String str)
  {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return std::move(str);
  }
}