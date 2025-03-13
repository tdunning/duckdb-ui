#include "settings.hpp"

#include <duckdb.hpp>

namespace duckdb {

std::string GetRemoteUrl(const ClientContext &context) {
  if (!context.db->config.options.allow_unsigned_extensions) {
    return UI_REMOTE_URL_SETTING_DEFAULT;
  }
  return internal::GetSetting<std::string>(context, UI_REMOTE_URL_SETTING_NAME);
}

uint16_t GetLocalPort(const ClientContext &context) {
  return internal::GetSetting<uint16_t>(context, UI_LOCAL_PORT_SETTING_NAME);
}

uint32_t GetPollingInterval(const ClientContext &context) {
  return internal::GetSetting<uint32_t>(context,
                                        UI_POLLING_INTERVAL_SETTING_NAME);
}

std::string GetUrlRandomizer(const ClientContext &context) {
  return internal::GetSetting<std::string>(context, UI_LOCAL_URL_RANDOMIZER);
}
} // namespace duckdb
