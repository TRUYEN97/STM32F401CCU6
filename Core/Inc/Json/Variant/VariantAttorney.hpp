// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License

#pragma once

#include <Json/Polyfills/attributes.hpp>
#include <Json/Polyfills/type_traits.hpp>
#include <Json/Variant/JsonVariantConst.hpp>
#include <Json/Variant/VariantData.hpp>
#include <Json/Variant/VariantTo.hpp>

ARDUINOJSON_BEGIN_PRIVATE_NAMESPACE

// Grants access to the internal variant API
class VariantAttorney {
 public:
  template <typename TClient>
  static auto getResourceManager(TClient& client)
      -> decltype(client.getResourceManager()) {
    return client.getResourceManager();
  }

  template <typename TClient>
  static auto getData(TClient& client) -> decltype(client.getData()) {
    return client.getData();
  }

  template <typename TClient>
  static VariantData* getOrCreateData(TClient& client) {
    return client.getOrCreateData();
  }
};

ARDUINOJSON_END_PRIVATE_NAMESPACE
