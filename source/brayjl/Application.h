#ifndef APPLICATION_H
#define APPLICATION_H

#include "Engine.h"

namespace brayjl {
	class Application {
	public:
		Application(const WindowOptions& windowOptions);
		~Application() = default;

		void run();
	private:
		void startup();
		void update();
		void shutdown();

		LoggerOptions m_loggerOptions;

		WindowOptions m_windowOptions;
		Window m_window;

		Framebuffer m_framebuffer{ m_window };

		Game m_game{ m_window };
	};
}

#endif