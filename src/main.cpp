#include <LucidyEngine/generic/graphic_lib.hpp>

#include <LucidyEngine/scene/scene_controller.hpp>
#include <LucidyEngine/window/normal_window.hpp>
#include <scenes/example_scene.hpp>

int main(void)
{
    ly::MessageBus messageBus;

    ly::NormalWindow window( ly::WindowSettings{1280, 720, "The Wonders of Mazalt", 1, false} );
    ly::DebugWindow debugWindow( window );

    window.open();
    ly::initGraphicLib();
    debugWindow.open();

    ly::SceneController controller( debugWindow );
    ly::ExampleReceiverScene scene1( debugWindow, &messageBus, "Scene text 1" );
    ly::ExampleSenderScene scene2( debugWindow, &messageBus, "Scene text 2" );
    ly::ExampleMouseScene scene3( window, debugWindow );

    controller.add( "scene1", &scene1 );
    controller.add( "scene2", &scene2 );
    controller.add( "scene3", &scene3 );
    controller.select( "scene2" );

    while (!window.isClosed())
    {
        window.clear();
        debugWindow.clear();

        controller.run();

        debugWindow.flush();
        window.flush();

        messageBus.notify();
    }

    return 0;
}