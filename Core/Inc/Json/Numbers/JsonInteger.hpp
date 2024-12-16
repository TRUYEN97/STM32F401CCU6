// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License

#pragma once

#include <Json/Configuration.hpp>
#include <Json/Namespace.hpp>
#include <stdint.h>  // int64_t

ARDUINOJSON_BEGIN_PUBLIC_NAMESPACE

#if ARDUINOJSON_USE_LONG_LONG
using JsonInteger = int64_t;
using JsonUInt = uint64_t;
#else
using JsonInteger = long;
using JsonUInt = unsigned long;
#endif

ARDUINOJSON_END_PUBLIC_NAMESPACE

#define ARDUINOJSON_ASSERT_INTEGER_TYPE_IS_SUPPORTED(T)                  \
  static_assert(sizeof(T) <= sizeof(ArduinoJson::JsonInteger),           \
                "To use 64-bit integers with ArduinoJson, you must set " \
                "ARDUINOJSON_USE_LONG_LONG to 1. See "                   \
                "https://arduinojson.org/v7/api/config/use_long_long/");