#ifndef GAME_H
#define GAME_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Logger.h"
#include "Window.h"
#include "Shader.h"
#include "Model.h"
#include "ResourceManager.h"
#include "Framebuffer.h"

namespace brayjl {
	class Game {
	public:
		Game(Window& appWindow)
			: window(appWindow) {
		}

		void startup();
		void update();
		void shutdown();

		Window& window;

		Shader shader;
		unsigned int quadVAO, quadVBO;
		unsigned int framebuffer;
		unsigned int textureColorbuffer;
		unsigned int rbo;
	};
}

#endif