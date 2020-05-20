#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../generic/window_lib.hpp"
#include "../generic/data_types.hpp"

#include <functional>

namespace ly{

    typedef struct WindowSettings{
        uint_t width;
        uint_t height; 
        cstring_t windowName;
        int_t swapInterval;
        bool_t captureMouse;
    } WindowSettings;

    class Window{
    public:
        virtual void open() = 0;
        virtual void close() = 0;
        virtual bool isClosed() = 0;

        virtual void clear() = 0;
        virtual void flush() = 0;

        virtual void claim(const std::function<void(window_t*)>& task) {};

        vec2_t getMousePos(){ return m_mousePosition; }
        vec2_t getScrollLevel(){ return m_scrollLevel; }

    protected:
        void setMousePos(const vec2_t& t_mousePos){ m_mousePosition = t_mousePos; }
        void setScrollLevel(const vec2_t& t_scrollLevel){ m_scrollLevel += t_scrollLevel; }

    private:
        vec2_t m_mousePosition = {0.0f, 0.0f};
        vec2_t m_scrollLevel = {0.0f, 0.0f};
        
    };

}

#endif // WINDOW_HPP
