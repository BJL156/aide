#include "Window.h"

namespace brayjl {
    Window::Window(const WindowOptions& windowOptions) {
        startup(windowOptions);
    }

    Window::~Window() {
        shutdown();
    }

    bool Window::shouldClose() {
        return glfwWindowShouldClose(m_window);
    }

    double Window::getTime() const {
        return glfwGetTime();
    }

    std::uint32_t Window::getWidth() const {
        return m_width;
    }

    std::uint32_t Window::getHeight() const {
        return m_height;
    }

    GLFWwindow* Window::getHandle() const {
        return m_window;
    }

    void Window::startup(const WindowOptions& windowOptions) {
        m_width = windowOptions.width;
        m_height = windowOptions.height;
        m_name = windowOptions.name;

        createGlfwWindow();
    }

    void Window::update() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::shutdown() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Window::createGlfwWindow() {
        if (!glfwInit()) {
            Logger::error("Failed to initialize GLFW.");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), nullptr, nullptr);
        if (m_window == nullptr) {
            Logger::error("Failed to create a GLFW window.");
            return;
        }

        glfwMakeContextCurrent(m_window);

        glfwSetWindowUserPointer(m_window, this);
        glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);

        initializeGlad();

        glViewport(0, 0, m_width, m_height);
        glEnable(GL_DEPTH_TEST);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }

    void Window::initializeGlad() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            Logger::error("Failed to initialize GLAD.");
            return;
        }
    }

    void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
        Window* p_window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        p_window->m_width = (width > 0) ? width : 1;
        p_window->m_height = (height > 0) ? height : 1;

        glViewport(0, 0, p_window->m_width, p_window->m_height);

        Logger::info("Window resized: " + std::to_string(p_window->m_width) + ", " + std::to_string(p_window->m_height));
    }
}