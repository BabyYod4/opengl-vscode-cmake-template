#include "window_context.hpp"

WindowContext::WindowContext() {}

WindowContext::WindowContext(WindowContextSettings&& t_settings) {
    m_settings = std::move( t_settings );
    init();
}

WindowContext::~WindowContext(){
    close();
}

void WindowContext::init() {
    /* Initialize the library */
    if (!glfwInit())
        ASSERT(false, "Unable to initalize WindowContext Library");

    /* Create a windowed mode window and its OpenGL context */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_settings.openglVersion.x);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_settings.openglVersion.y);
    m_window = glfwCreateWindow(m_settings.width, m_settings.height, m_settings.windowName.c_str(), NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        ASSERT(false, "Unable to create Window");
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(m_settings.swapInterval);
    std::cout << "WindowContext library initalized succesfully! " << std::endl;
    initGraphicLib();
}

void WindowContext::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void WindowContext::flush(){
    /* Swap front and back buffers */
    glfwSwapBuffers(m_window);

    /* Poll for and process events */
    glfwPollEvents();
}

void WindowContext::close() {
    glfwTerminate();
}

bool WindowContext::isClosed() {
    return glfwWindowShouldClose(m_window);
}

void WindowContext::claim(const std::function<void(window_tp*)>& task) {
    task(m_window);
}

void WindowContext::setSettings(WindowContextSettings&& t_settings) {
    m_settings = std::move( t_settings );
}

WindowContextSettings WindowContext::getSettings() {
    return m_settings;
}

void WindowContext::initGraphicLib() {
    enum_tp err = glewInit();
    if (err != GLEW_OK){
      ASSERT(false, "Could not initalize Graphics Library");
    }

    std::cout << "Graphics library initialized succesfully with OpenGL version" << glGetString(GL_VERSION) << std::endl;
}
