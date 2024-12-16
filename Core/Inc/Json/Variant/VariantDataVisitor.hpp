// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License

#pragma once

#include <Json/Array/ArrayData.hpp>
#include <Json/Numbers/JsonFloat.hpp>
#include <Json/Numbers/JsonInteger.hpp>
#include <Json/Object/ObjectData.hpp>

ARDUINOJSON_BEGIN_PRIVATE_NAMESPACE

template <typename TResult>
struct VariantDataVisitor {
  using result_type = TResult;

  template <typename T>
  TResult visit(const T&) {
    return TResult();
  }
};

ARDUINOJSON_END_PRIVATE_NAMESPACE
