#ifndef UTILS_H
#define UTILS_H

#include "Logger.h"

#include <fstream>
#include <string>

namespace brayjl {
	class Utils {
	public:
		static std::string getFileContents(const std::string filepath);
	};
}

#endif