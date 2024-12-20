// THIS FILE WAS GENERATED BY `xtp-cpp-bindgen`. DO NOT EDIT.
#define EXTISM_CPP_IMPLEMENTATION
#include "pdk.gen.hpp"
#include <extism-pdk.hpp>
#include <jsoncons/json.hpp>

JSONCONS_N_MEMBER_NAME_TRAITS(pdk::InputClear, 1, (color, "color"))
JSONCONS_N_MEMBER_NAME_TRAITS(pdk::InputUpdate, 1, (time, "time"))

namespace pdk {

namespace exports {

int32_t EXTISM_EXPORTED_FUNCTION(load) {
  extism::log_debug("load: calling implementation function");
  auto result = impl::load();
  if (!result) {
    extism::error_set("load: failed");
    return -3;
  }
  extism::log_debug("load: returning");
  return 0;
}

int32_t EXTISM_EXPORTED_FUNCTION(unload) {
  extism::log_debug("unload: calling implementation function");
  auto result = impl::unload();
  if (!result) {
    extism::error_set("unload: failed");
    return -3;
  }
  extism::log_debug("unload: returning");
  return 0;
}

int32_t EXTISM_EXPORTED_FUNCTION(update) {
  extism::log_debug("update: getting JSON input");
  auto input_str = extism::input().string();
  if (!input_str.size()) {
    extism::error_set("0 length input cannot be json");
    return -1;
  }
  auto input = jsoncons::decode_json<InputUpdate>(std::move(input_str));
  extism::log_debug("update: calling implementation function");
  auto result = impl::update(std::move(input));
  if (!result) {
    extism::error_set("update: failed");
    return -3;
  }
  extism::log_debug("update: returning");
  return 0;
}

} // namespace exports

namespace imports {

EXTISM_IMPORT_USER("clear")
extern void clear(extism::imports::RawHandle);

} // namespace imports

std::expected<void, Error> clear(InputClear input) {
  std::string encoded;
  jsoncons::encode_json(input, encoded);
  auto in_handle = extism::UniqueHandle<char>::from(encoded);
  if (!in_handle) {
    return std::unexpected(Error::extism);
  }
  imports::clear(*in_handle);
  return std::expected<void, Error>();
}

} // namespace pdk
