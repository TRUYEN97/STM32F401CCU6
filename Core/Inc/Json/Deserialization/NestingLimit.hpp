// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License

#pragma once

#include <Json/Namespace.hpp>
#include <Json/Polyfills/assert.hpp>

ARDUINOJSON_BEGIN_PUBLIC_NAMESPACE

namespace DeserializationOption {
class NestingLimit {
 public:
  NestingLimit() : value_(ARDUINOJSON_DEFAULT_NESTING_LIMIT) {}
  explicit NestingLimit(uint8_t n) : value_(n) {}

  NestingLimit decrement() const {
    ARDUINOJSON_ASSERT(value_ > 0);
    return NestingLimit(static_cast<uint8_t>(value_ - 1));
  }

  bool reached() const {
    return value_ == 0;
  }

 private:
  uint8_t value_;
};
}  // namespace DeserializationOption

ARDUINOJSON_END_PUBLIC_NAMESPACE
