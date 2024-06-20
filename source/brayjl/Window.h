#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Logger.h"

#include <cstdint>
#include <string>
#include <iostream>

namespace brayjl {
	struct WindowOptions {
		std::string name;
		std::uint32_t width;
		std::uint32_t height;
	};

	class Window {
	public:
		Window() = default;
		Window(const WindowOptions& windowOptions);

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		~Window();

		void startup(const WindowOptions& windowOptions);
		void update();
		void shutdown();

		bool shouldClose();

		double getTime() const;
		std::uint32_t getWidth() const;
		std::uint32_t getHeight() const;
		GLFWwindow* getHandle() const;
	private:
		void createGlfwWindow();
		void initializeGlad();

		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

		std::uint32_t m_width;
		std::uint32_t m_height;
		std::string m_name;
		GLFWwindow* m_window;
	};
}

#endif