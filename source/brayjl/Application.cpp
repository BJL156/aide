#include "Application.h"

namespace brayjl {
	Application::Application(const WindowOptions& windowOptions)
		: m_windowOptions(windowOptions) {

	}

	void Application::run() {
		startup();

		while (!m_window.shouldClose()) {
            update();
		}

		shutdown();
	}

	void Application::startup() {
		m_window.startup(m_windowOptions);
		m_framebuffer.startup();
		m_game.startup();
	}

	void Application::update() {
        m_window.update();

		m_framebuffer.bind();
		m_game.update();
		m_framebuffer.unbind();

		m_framebuffer.draw();
	}

	void Application::shutdown() {
		m_framebuffer.shutdown();
		m_window.shutdown();
		m_game.shutdown();
	}
}