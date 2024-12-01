#include "pdk.gen.hpp"

/**
 * Called when your cart is loaded
 */
std::expected<void, pdk::Error> impl::load() {
  return std::unexpected(pdk::Error::not_implemented);
}

/**
 * Called when your cart is unloaded
 */
std::expected<void, pdk::Error> impl::unload() {
  return std::unexpected(pdk::Error::not_implemented);
}

/**
 * Called each frame
 *
 * @param input
 */
std::expected<void, pdk::Error> impl::update(pdk::InputUpdate input) {
  return std::unexpected(pdk::Error::not_implemented);
}
