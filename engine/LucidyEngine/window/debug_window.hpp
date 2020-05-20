#ifndef DEBUG_WINDOW_HPP
#define DEBUG_WINDOW_HPP

#include "window.hpp"

namespace ly{

    class DebugWindow{
    public:
        DebugWindow();
        DebugWindow(Window& t_window);
        ~DebugWindow();

        void open();
        void close();
        void clear();
        void flush();

        void drawStart( cstring_t t_menuName );
        void drawEnd();

        void drawText( cstring_t t_text );
        bool drawButton( cstring_t t_name );
    private:
        Window& m_window;
    };

}
#endif /* DEBUG_WINDOW_HPP */
