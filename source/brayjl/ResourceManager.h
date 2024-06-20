#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Shader.h"
#include "Model.h"

#include <string>
#include <map>

namespace brayjl {
	class ResourceManager {
	public:
		static Shader loadShader(const std::string vertexFilepath, const std::string fragmentFilepath, const std::string name);
		static Shader getShader(const std::string name);

		static Model loadModel(const std::string filepath, const std::string name);
		static Model getModel(const std::string name);

		static std::map<std::string, Shader> shaders;
		static std::map<std::string, Model> models;
	};
}

#endif