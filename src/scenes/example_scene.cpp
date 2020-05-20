#include "example_scene.hpp"
#include <LucidyEngine/generic/logging.hpp>
#include <LucidyEngine/generic/data_types.hpp>

namespace ly{

    /// ExampleReceiverScene
    ExampleReceiverScene::ExampleReceiverScene(
        DebugWindow& t_debugWindow, 
        MessageBus* t_messageBus, 
        cstring_t t_text
    ):
        BusNode( t_messageBus ),
        m_text(t_text),
        m_message("No Messages Received"),
        m_debugWindow(t_debugWindow)
    {}

    void ExampleReceiverScene::onUpdate(const float_t& t_delta) {
        m_debugWindow.drawStart( m_text );
        m_debugWindow.drawText( m_message.c_str() );
        m_debugWindow.drawEnd();                      
    }


    void ExampleReceiverScene::onEvent(Message& t_message) {
        m_message =  t_message.getEvent();
        std::cout << "ExampleReceiverScene[1] received: " << m_message << std::endl;
    }
    /// ===============================================================================

    /// ExampleSenderScene
    ExampleSenderScene::ExampleSenderScene(
        DebugWindow& t_debugWindow, 
        MessageBus* t_messageBus, 
        cstring_t t_text
    ):
        BusNode( t_messageBus ),
        m_text(t_text),
        m_debugWindow(t_debugWindow)
    {
        
    }

    void ExampleSenderScene::onUpdate(const float_t& t_delta) {
        m_debugWindow.drawStart( m_text );
        bool pressed = m_debugWindow.drawButton("Click ME to send time to Scene 1");
        if (pressed){ sendMessage( Message(t_delta) ); }
        m_debugWindow.drawEnd();    
    }
    /// ===============================================================================

    ExampleMouseScene::ExampleMouseScene(Window& t_window, DebugWindow& t_debugWindow):
        m_window(t_window),
        m_debugWindow(t_debugWindow)
    {}

    void ExampleMouseScene::onUpdate(const float_t& t_delta) {
        m_debugWindow.drawStart( "Mouse position Callback test" );
        m_debugWindow.drawText( vec2ToString( m_window.getMousePos() ).c_str() );
        m_debugWindow.drawText( vec2ToString( m_window.getScrollLevel() ).c_str() );
        m_debugWindow.drawEnd();    
    }


} // Namespace END

