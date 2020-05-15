#ifndef WINDOW_CONTEXT_HPP
#define WINDOW_CONTEXT_HPP

#include "lib_base.hpp"
#include <glfw/glfw3.h>
#include <functional>
#include <utility>

typedef GLFWwindow window_tp;

struct WindowContextSettings{
    uint_tp width;
    uint_tp height; 
    string_tp windowName;
    int_tp swapInterval;
    vec2_tp openglVersion;
};

class WindowContext{

public:
    WindowContext();
    WindowContext(WindowContextSettings&& t_settings);
    ~WindowContext();

    void init();
    void clear();
    void flush();
    void close();
    bool isClosed();

    void claim(const std::function<void(window_tp*)>& task);
    void setSettings(WindowContextSettings&& t_settings);
    WindowContextSettings getSettings();

private: 
    WindowContextSettings m_settings;
    window_tp* m_window;

    void initGraphicLib();

};

#endif // !WINDOW_CONTEXT_HPP