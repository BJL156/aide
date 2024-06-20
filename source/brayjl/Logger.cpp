#include "Logger.h"

namespace brayjl {
	void Logger::startup(const LoggerOptions& loggerOptions) {
		std::shared_ptr<spdlog::logger> fileLogger = spdlog::basic_logger_mt(loggerOptions.name, loggerOptions.outputFile);
		spdlog::set_default_logger(fileLogger);
		spdlog::set_level(convertLogLevel(loggerOptions.level));
		spdlog::flush_on(convertLogLevel(loggerOptions.flushLevel));
	}

	void Logger::info(const std::string& message) {
		spdlog::info(message);
	}

	void Logger::warn(const std::string& message) {
		spdlog::warn(message);
	}

	void Logger::error(const std::string& message) {
		spdlog::error(message);
		throw std::runtime_error(message);
	}

	spdlog::level::level_enum Logger::convertLogLevel(const LoggerLevel& loggerLevel) {
		switch (loggerLevel) {
		case LoggerLevel::Info:
			return spdlog::level::info;
		case LoggerLevel::Warn:
			return spdlog::level::warn;
		case LoggerLevel::Error:
			return spdlog::level::err;
		default:
			return spdlog::level::info;
		}
	}
}