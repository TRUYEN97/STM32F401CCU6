// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License

#pragma once

#if __cplusplus < 201103L && (!defined(_MSC_VER) || _MSC_VER < 1910)
#  error ArduinoJson requires C++11 or newer. Configure your compiler for C++11 or downgrade ArduinoJson to 6.20.
#endif

#include <Json/Configuration.hpp>

// Include Arduino.h before stdlib.h to avoid conflict with atexit()
// https://github.com/bblanchon/ArduinoJson/pull/1693#issuecomment-1001060240
#if ARDUINOJSON_ENABLE_ARDUINO_STRING || ARDUINOJSON_ENABLE_ARDUINO_STREAM || \
    ARDUINOJSON_ENABLE_ARDUINO_PRINT ||                                       \
    (ARDUINOJSON_ENABLE_PROGMEM && defined(ARDUINO))
#  include <Arduino.h>
#endif

#if !ARDUINOJSON_DEBUG
#  ifdef __clang__
#    pragma clang system_header
#  elif defined __GNUC__
#    pragma GCC system_header
#  endif
#endif

#include <Json/Array/JsonArray.hpp>
#include <Json/Object/JsonObject.hpp>
#include <Json/Variant/JsonVariantConst.hpp>

#include <Json/Document/JsonDocument.hpp>

#include <Json/Array/ArrayImpl.hpp>
#include <Json/Array/ElementProxy.hpp>
#include <Json/Array/Utilities.hpp>
#include <Json/Collection/CollectionImpl.hpp>
#include <Json/Memory/ResourceManagerImpl.hpp>
#include <Json/Object/MemberProxy.hpp>
#include <Json/Object/ObjectImpl.hpp>
#include <Json/Variant/ConverterImpl.hpp>
#include <Json/Variant/JsonVariantCopier.hpp>
#include <Json/Variant/VariantCompare.hpp>
#include <Json/Variant/VariantImpl.hpp>
#include <Json/Variant/VariantRefBaseImpl.hpp>

#include <Json/Json/JsonDeserializer.hpp>
#include <Json/Json/JsonSerializer.hpp>
#include <Json/Json/PrettyJsonSerializer.hpp>
#include <Json/MsgPack/MsgPackBinary.hpp>
#include <Json/MsgPack/MsgPackDeserializer.hpp>
#include <Json/MsgPack/MsgPackExtension.hpp>
#include <Json/MsgPack/MsgPackSerializer.hpp>

#include <Json/compatibility.hpp>
