#ifndef NORMAL_WINDOW_HPP
#define NORMAL_WINDOW_HPP

#include "../settings.hpp"
#include "window.hpp"

namespace ly{

    class NormalWindow: public Window{

    public:
        NormalWindow();
        NormalWindow(WindowSettings&& t_settings);
        ~NormalWindow();

        void open() override;
        void close() override;
        bool isClosed() override;

        void clear() override;
        void flush() override;

        void claim(const std::function<void(window_t*)>& task);
        void setSettings(WindowSettings&& t_settings);
        WindowSettings getSettings();

    private: 
        WindowSettings m_settings;
        window_t* m_window;


        static void mousePosDataGet( window_t* t_window, double_t t_xPos, double_t t_yPos){
            void* self = glfwGetWindowUserPointer(t_window);
            NormalWindow* pSelf = static_cast<NormalWindow* >(self);
            pSelf->setMousePos( vec2_t( float_t(t_xPos), float_t(t_yPos) )  );
        }

        static void mouseScrollDataGet( window_t* t_window, double_t t_xOffset, double_t t_yOffset){
            void* self = glfwGetWindowUserPointer(t_window);
            NormalWindow* pSelf = static_cast<NormalWindow* >(self);
            pSelf->setScrollLevel( 
                vec2_t( 
                    ( (float_t(t_xOffset) * 0.1f) ) , 
                    ( (float_t(t_yOffset) * 0.1f) )
                ) 
            );
        }

    };

}


#endif // !NORMAL_WINDOW_HPP