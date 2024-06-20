#ifndef MODEL_H
#define MODEL_H

#include <ASSIMP/Importer.hpp>
#include <ASSIMP/scene.h>
#include <ASSIMP/postprocess.h>
#include <STB/stb_image.h>

#include "Shader.h"
#include "Mesh.h"

#include <vector>
#include <string>
#include <string>
#include <iostream>

namespace brayjl {
	unsigned int textureFromFile(const char* path, const std::string& directory, bool gamma);

	class Model {
	public:
		Model() = default;
		Model(const std::string& filepath);

		void draw(Shader& shader);
	private:
		void loadModel(std::string path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);

		std::vector<Mesh> m_meshes;
		std::string m_directory;

		std::vector<Texture> m_texturesLoaded;
	};
}

#endif