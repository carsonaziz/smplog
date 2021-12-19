#include <iostream>

#include "logger.h"

using LOG = Logger::Logger;

int main() {
    LOG console_log("APP");
    console_log.set_level(LOG_LEVEL::Info);
    console_log.info("Succesfully loaded textures");
    console_log.warn("This is the %ist warning message", 1);

    LOG app_log("CONSOLE");
    app_log.set_level(LOG_LEVEL::Debug);
    app_log.error("Could not open %i files: %s, %s", 2, "default.txt", "temp.txt");
    return 0;
}
