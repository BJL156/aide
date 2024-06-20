#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <glad/glad.h>
#include <spdlog/spdlog.h>

#include "Logger.h"
#include "Window.h"
#include "Shader.h"

#include <cstdint>

namespace brayjl {
	class Framebuffer {
	public:
		Framebuffer(Window& appWindow);
		~Framebuffer();

		void startup();
		void shutdown();

		void bind();
		void unbind();

		void resize();

		void draw();
	private:
		unsigned int m_framebuffer;
		unsigned int m_texture;
		unsigned int m_renderbuffer;
		unsigned int m_quadVAO, m_quadVBO;

		Shader m_quadShader;

		Window& m_window;
		std::uint32_t m_width;
		std::uint32_t m_height;
	};
}

#endif