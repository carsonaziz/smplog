#include "logger.h"

using LOG = smplog::Logger;

int main() {
    LOG console_log("APP", "log.txt");
    console_log.set_level(LOG_LEVEL::Debug);
    console_log.debug("Application version %d initialized", 1.1);
    console_log.info("Successfully loaded textures");
    console_log.warn("This is the %ist warning message", 1);

    LOG app_log("CONSOLE");
    app_log.set_level(LOG_LEVEL::Debug);
    app_log.error("Could not open %i files: %s, %s", 2, "default.txt", "temp.txt");
    return 0;
}
