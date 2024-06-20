#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Logger.h"
#include "Utils.h"

#include <string>

namespace brayjl {
	class Shader {
	public:
		Shader() = default;
		Shader(const std::string vertexFilepath, const std::string fragmentFilepath);
		~Shader();

		void startup(const std::string vertexFilepath, const std::string fragmentFilepath);
		void use();
		void shutdown();

		void setMat4(std::string uniformName, glm::mat4& mat4);
		void setMat3(std::string uniformName, glm::mat3& mat3);
		void setMat2(std::string uniformName, glm::mat2& mat2);

		void setVec4(std::string uniformName, glm::vec4& vec4);
		void setVec3(std::string uniformName, glm::vec3& vec3);
		void setVec2(std::string uniformName, glm::vec2& vec2);

		void setInt(std::string uniformName, int& integer);
		void setFloat(std::string uniformName, float& flt);
		void setDouble(std::string uniformName, double& dble);

		static bool isShaderCompiled(unsigned int& shader);
		static bool isProgramLinked(unsigned int& program);
	private:
		void createShaderProgram(const std::string vertexFilepath, const std::string fragmentFilepath);

		unsigned int m_id;
	};
}

#endif