#include "ResourceManager.h"

namespace brayjl {
	std::map<std::string, Shader> ResourceManager::shaders;
	std::map<std::string, Model> ResourceManager::models;

	Shader ResourceManager::loadShader(const std::string vertexFilepath, const std::string fragmentFilepath, const std::string name) {
		Shader shader(vertexFilepath, fragmentFilepath);

		shaders[name] = shader;

		return shaders[name];
	}

	Shader ResourceManager::getShader(const std::string name) {
		return shaders[name];
	}

	Model ResourceManager::loadModel(const std::string filepath, const std::string name) {
		Model model(filepath);

		models[name] = model;

		return models[name];
	}

	Model ResourceManager::getModel(const std::string name) {
		return models[name];
	}
}