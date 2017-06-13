// Copyright: ThoughtSpot Inc 2017
// Author: Naresh Kumar (naresh.kumar@thoughtspot.com)

#ifndef CPP_UTILS_HPP_
#define CPP_UTILS_HPP_

#include <iostream>
#include <sstream>
#include <vector>

namespace utils {
// ToString(...) is a generic template which can be specialized for the various
// types we wish to support ToString for.
template <typename T> std::string ToString(const T& v);

// Use Choice<N> as first argument to disambiguate if multiple overload passes.
template <std::size_t N> struct Choice : Choice<N - 1> {};
template <> struct Choice<0> {};

template <typename T>
auto ToStringImpl(Choice<3>, const T& v)
    -> decltype(v.DebugString(), std::string()) {
  return v.DebugString();
}
template <typename T>
auto ToStringImpl(Choice<2>, const T& v)
    -> decltype(std::declval<std::ostream&>() << v, std::string()) {
  std::ostringstream ss;
  ss << v;
  return ss.str();
}
template <typename T>
auto ToStringImpl(Choice<1>, const T& v)
    -> decltype(v.begin(), v.end(), std::string()) {
  auto begin = v.begin();
  auto end = v.end();
  if (begin == end) return "[]";
  std::string ans = "[" + ToString(*begin++);
  while (begin != end) ans += ", " + ToString(*begin++);
  return ans + "]";
}
template <typename U, typename V>
std::string ToStringImpl(Choice<0>, const std::pair<U, V>& p) {
  return ToString(p.first) + ": " + ToString(p.second);
}
template <typename T>
inline std::string ToString(const T& v) {
  return ToStringImpl(Choice<3>{}, v);
}
template <>
inline std::string ToString(const std::string& v) {
  return "\"" + v + "\"";
}
}  // namespace utils

#endif  // CPP_UTILS_HPP_
