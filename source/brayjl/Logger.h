#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <stdexcept>
#include <string>
#include <memory>

namespace brayjl {
	enum class LoggerLevel {
		Info,
		Warn,
		Error,
	};

	struct LoggerOptions {
		std::string name;
		std::string outputFile;
		LoggerLevel level;
		LoggerLevel flushLevel;
	};

	class Logger {
	public:
		static void startup(const LoggerOptions& loggerOptions);

		static void info(const std::string& message);
		static void warn(const std::string& message);
		static void error(const std::string& message);
	private:
		static spdlog::level::level_enum convertLogLevel(const LoggerLevel& loggerLevel);
	};
}

#endif