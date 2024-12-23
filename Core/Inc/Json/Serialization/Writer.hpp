// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License

#pragma once

#include <Json/Namespace.hpp>

ARDUINOJSON_BEGIN_PRIVATE_NAMESPACE

// The default writer is a simple wrapper for Writers that are not copiable
template <typename TDestination, typename Enable = void>
class Writer {
 public:
  explicit Writer(TDestination& dest) : dest_(&dest) {}

  size_t write(uint8_t c) {
    return dest_->write(c);
  }

  size_t write(const uint8_t* s, size_t n) {
    return dest_->write(s, n);
  }

 private:
  TDestination* dest_;
};

ARDUINOJSON_END_PRIVATE_NAMESPACE

#include <Json/Serialization/Writers/StaticStringWriter.hpp>

#if ARDUINOJSON_ENABLE_STD_STRING
#  include <Json/Serialization/Writers/StdStringWriter.hpp>
#endif

#if ARDUINOJSON_ENABLE_ARDUINO_STRING
#  include <Json/Serialization/Writers/ArduinoStringWriter.hpp>
#endif

#if ARDUINOJSON_ENABLE_STD_STREAM
#  include <Json/Serialization/Writers/StdStreamWriter.hpp>
#endif

#if ARDUINOJSON_ENABLE_ARDUINO_PRINT
#  include <Json/Serialization/Writers/PrintWriter.hpp>
#endif
