#include "brayjl/Engine.h"

int main() {
	brayjl::LoggerOptions loggerOptions = {};
	loggerOptions.name = "fileLogger";
	loggerOptions.outputFile = "logs/logFile.log";
	loggerOptions.level = brayjl::LoggerLevel::Info;
	loggerOptions.flushLevel = brayjl::LoggerLevel::Info;
	brayjl::Logger::startup(loggerOptions);

	brayjl::WindowOptions winOptions = {};
	winOptions.name = "aide";
	winOptions.width = 1920;
	winOptions.height = 1080;
	brayjl::Application app(winOptions);

	try {
		app.run();
	} catch (std::exception& exception) {
		std::cerr << exception.what() << '\n';
		std::cin.get();

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}