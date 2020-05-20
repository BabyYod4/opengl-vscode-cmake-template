#include "normal_window.hpp"
#include "../generic/logging.hpp"
#include <utility>

namespace ly{

    NormalWindow::NormalWindow() {}

    NormalWindow::NormalWindow(WindowSettings&& t_settings) {
        m_settings = std::move( t_settings );
    }

    NormalWindow::~NormalWindow(){
        close();
    }

    void NormalWindow::open() {
        /* Initialize the library */
        if (!glfwInit()){ ASSERT(false, "Unable to initalize NormalWindow Library"); } 

        /* Create a windowed mode window and its OpenGL context */
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR );
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR );
    #if OPENGL_VERSION_USE_COMPAT == ENABLE
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    #else
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif 
        m_window = glfwCreateWindow(m_settings.width, m_settings.height, m_settings.windowName, NULL, NULL);
        glfwSetWindowUserPointer(m_window, this);
        
        if (!m_window) {
            glfwTerminate();
            ASSERT(false, "Unable to create NormalWindow");
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(m_settings.swapInterval);

        glfwSetCursorPosCallback(m_window, mousePosDataGet);
        glfwSetScrollCallback(m_window, mouseScrollDataGet);
        if(m_settings.captureMouse){ glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }
        
        std::cout << "Sucessfully created NormalWindow" << std::endl;
    }

    void NormalWindow::clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void NormalWindow::flush(){
        /* Swap front and back buffers */
        glfwSwapBuffers(m_window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    void NormalWindow::close() {
        glfwTerminate();
        std::cout << "Sucessfully destroyed NormalWindow" << std::endl;
    }

    bool NormalWindow::isClosed() {
        return glfwWindowShouldClose(m_window);
    }

    void NormalWindow::claim(const std::function<void(window_t*)>& task) {
        task( m_window );
    }

    void NormalWindow::setSettings(WindowSettings&& t_settings) {
        m_settings = std::move( t_settings );
    }

    WindowSettings NormalWindow::getSettings() {
        return m_settings;
    }

}



