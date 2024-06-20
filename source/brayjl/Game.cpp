#include "Game.h"


namespace brayjl {
	void brayjl::Game::startup() {
		ResourceManager::loadShader("resources/shaders/model.vert", "resources/shaders/model.frag", "model");
		ResourceManager::loadShader("resources/shaders/framebuffer.vert", "resources/shaders/framebuffer.frag", "framebuffer");
		ResourceManager::loadModel("resources/models/chunli/mesh.obj", "chunli");
	}

	void brayjl::Game::update() {
        Shader modelShader = ResourceManager::getShader("model");
        Model chunli = ResourceManager::getModel("chunli");

        modelShader.use();
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 proj = glm::perspective(glm::radians(90.0f), static_cast<float>(window.getWidth()) / window.getHeight(), 0.1f, 100.0f);

        model = glm::translate(model, glm::vec3(-1.0f, -3.5f, -5.0f));
        model = glm::rotate(model, glm::radians(static_cast<float>(window.getTime()) * 100.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.5f));

        modelShader.setMat4("model", model);
        modelShader.setMat4("view", view);
        modelShader.setMat4("proj", proj);

        chunli.draw(modelShader);

        // again
        model = glm::mat4(1.0f);
        view = glm::mat4(1.0f);
        proj = glm::perspective(glm::radians(90.0f), static_cast<float>(window.getWidth()) / window.getHeight(), 0.1f, 100.0f);

        model = glm::translate(model, glm::vec3(1.0f, -3.5f, -5.0f));
        model = glm::rotate(model, glm::radians(static_cast<float>(-window.getTime()) * 100.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.5f));

        modelShader.setMat4("model", model);
        modelShader.setMat4("view", view);
        modelShader.setMat4("proj", proj);

        chunli.draw(modelShader);
	}

	void brayjl::Game::shutdown() {
		
	}
}