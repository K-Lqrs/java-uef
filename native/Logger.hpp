#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static void Info(const char* format, ...);
    static void Warn(const char* format, ...);
    static void Error(const char* format, ...);

private:
    enum class Level {
        INFO,
        WARN,
        ERROR
    };

    static void log(Level level, const std::string& message);
    static std::string levelToString(Level level);
    static std::string getCurrentTime();
    static std::string formatString(const char* format, va_list args);
};

#endif // LOGGER_H
