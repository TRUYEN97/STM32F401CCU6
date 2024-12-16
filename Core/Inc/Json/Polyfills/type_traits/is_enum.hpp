// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License

#pragma once

#include <Json/Polyfills/type_traits/is_class.hpp>
#include <Json/Polyfills/type_traits/is_convertible.hpp>
#include <Json/Polyfills/type_traits/is_floating_point.hpp>
#include <Json/Polyfills/type_traits/is_integral.hpp>
#include <Json/Polyfills/type_traits/is_same.hpp>

ARDUINOJSON_BEGIN_PRIVATE_NAMESPACE

template <typename T>
struct is_enum {
  static const bool value = is_convertible<T, long long>::value &&
                            !is_class<T>::value && !is_integral<T>::value &&
                            !is_floating_point<T>::value;
};

ARDUINOJSON_END_PRIVATE_NAMESPACE
