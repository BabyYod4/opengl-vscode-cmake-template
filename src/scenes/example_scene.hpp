#ifndef EXAMPLE_SCENE_HPP
#define EXAMPLE_SCENE_HPP

#include <LucidyEngine/scene/scene.hpp>
#include <LucidyEngine/window/debug_window.hpp>
#include <LucidyEngine/message_bus/bus_node.hpp>

namespace ly{

    class ExampleReceiverScene : public Scene, public BusNode {
    public:
        ExampleReceiverScene(DebugWindow& t_debugWindow, MessageBus* t_messageBus, cstring_t t_text);
        void onUpdate(const float_t& t_delta) override;
        void onEvent(Message& t_message) override;
    private:
        cstring_t m_text;
        std::string m_message;
        DebugWindow& m_debugWindow;

    };

    class ExampleSenderScene : public Scene, public BusNode {
    public:
        ExampleSenderScene(DebugWindow& t_debugWindow, MessageBus* t_messageBus, cstring_t t_text);
        void onUpdate(const float_t& t_delta) override;
    private:
        cstring_t m_text;
        DebugWindow& m_debugWindow;
    };

    class ExampleMouseScene : public Scene {
    public:
        ExampleMouseScene(Window& t_window, DebugWindow& t_debugWindow);
        void onUpdate(const float_t& t_delta) override;
    private:
        Window& m_window;
        DebugWindow& m_debugWindow;
    };

}

#endif // EXAMPLE_SCENE_HPP
