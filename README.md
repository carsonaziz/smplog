# smplog - A Simple C++ Logger

## Overview

smplog is a simple logging class for C++ projects that don't require advanced logging features. The feature set however, will grow over time.

Features:

- Predefined colored output for various severity levels
- Several severity levels
- Log to console or file
- Not currently thread safe

## Macros

The macro `LOG_LEVEL` is short for `smplog::log_level`

## Log Levels

- `smplog::log_level::Debug`
- `smplog::log_level::Info`
- `smplog::log_level::Warning`
- `smplog::log_level::Error`

## Example Usage

Features are demonstrated in main.cpp as well

```c++
using LOG = smplog::Logger;

int main()
{
    // Create console log with name "CONSOLE"
    LOG log("CONSOLE");
    // Set severity level of log to info. Logger will only log messages with level info and more severe
    log.set_level(LOG_LEVEL::Info);

    // Log messages at different severity levels
    log.debug("Testing %ist debug log", 1);
    log.info("File: %s, successfully loaded", "default.txt");
    log.warn("Variable %s may not have been set to %f", "weight", 66.54);

    // Create file log with name "FILE"
    LOG log_file("FILE", "log.txt");
    // Set severity level of log to warning. Logger will only log messages with level warning and more severe
    log_file.set_level(LOG_LEVEL::Warning);

    // Log messages at different severity levels
    log_file.warn("Variable %s may not have been set to %f", weight, 66.54);
    log_file.error("Could not initialize variable %s from file %s", "Alligator" "alligator.txt);
}
```

## Output

```
[CONSOLE][INFO]File: default.txt, successfully loaded
[CONSOLE][WARN]Variable weight may not have been set to 66.54
```
