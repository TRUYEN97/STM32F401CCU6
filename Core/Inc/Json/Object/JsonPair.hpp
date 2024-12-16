// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License

#pragma once

#include <Json/Strings/JsonString.hpp>
#include <Json/Variant/JsonVariant.hpp>
#include <Json/Variant/JsonVariantConst.hpp>

ARDUINOJSON_BEGIN_PUBLIC_NAMESPACE

// A key-value pair.
// https://arduinojson.org/v7/api/jsonobject/begin_end/
class JsonPair {
 public:
  // INTERNAL USE ONLY
  JsonPair(detail::ObjectData::iterator iterator,
           detail::ResourceManager* resources) {
    if (!iterator.done()) {
      key_ = iterator->asString();
      iterator.next(resources);
      value_ = JsonVariant(iterator.data(), resources);
    }
  }

  // Returns the key.
  JsonString key() const {
    return key_;
  }

  // Returns the value.
  JsonVariant value() {
    return value_;
  }

 private:
  JsonString key_;
  JsonVariant value_;
};

// A read-only key-value pair.
// https://arduinojson.org/v7/api/jsonobjectconst/begin_end/
class JsonPairConst {
 public:
  JsonPairConst(detail::ObjectData::iterator iterator,
                const detail::ResourceManager* resources) {
    if (!iterator.done()) {
      key_ = iterator->asString();
      iterator.next(resources);
      value_ = JsonVariantConst(iterator.data(), resources);
    }
  }

  // Returns the key.
  JsonString key() const {
    return key_;
  }

  // Returns the value.
  JsonVariantConst value() const {
    return value_;
  }

 private:
  JsonString key_;
  JsonVariantConst value_;
};

ARDUINOJSON_END_PUBLIC_NAMESPACE
