#include "Logger.hpp"
#include <iostream>
#include <cstdarg>
#include <cstdio>
#include <ctime>

void Logger::Info(const char* format, ...) {
    va_list args;
    va_start(args, format);
    std::string formattedMessage = formatString(format, args);
    va_end(args);

    log(Level::INFO, formattedMessage);
}

void Logger::Warn(const char* format, ...) {
    va_list args;
    va_start(args, format);
    std::string formattedMessage = formatString(format, args);
    va_end(args);

    log(Level::WARN, formattedMessage);
}

void Logger::Error(const char* format, ...) {
    va_list args;
    va_start(args, format);
    std::string formattedMessage = formatString(format, args);
    va_end(args);

    log(Level::ERROR, formattedMessage);
}

void Logger::log(Level level, const std::string& message) {
    const std::string prefix = getCurrentTime() + " [" + levelToString(level) + "] ";
    std::cout << prefix << message << std::endl;
}

std::string Logger::levelToString(Level level) {
    switch (level) {
        case Level::INFO:
            return "INFO";
        case Level::WARN:
            return "WARN";
        case Level::ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

std::string Logger::getCurrentTime() {
    const std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return {buf};
}

std::string Logger::formatString(const char* format, va_list args) {
    char buffer[1024];  // 1KBのバッファ（必要に応じて調整可能）
    std::vsnprintf(buffer, sizeof(buffer), format, args);
    return std::string(buffer);
}
