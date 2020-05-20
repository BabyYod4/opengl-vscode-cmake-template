#ifndef SCENE_CONTROLLER_HPP
#define SCENE_CONTROLLER_HPP

#include "scene.hpp"
#include "../settings.hpp"
#include "../window/debug_window.hpp"

#include <unordered_map>

namespace ly {

    class SceneController{
    public:

    #if SCENE_SELECTOR == ENABLE
        SceneController(DebugWindow& t_debugWindow);
    #else  
        SceneController();
    #endif

        ~SceneController();
        void add( const string_t& t_name, Scene* t_scene );
        void remove( const string_t& t_name );
        void select( const string_t& t_name );
        void run();

        std::string getActiveScene();

    private:
        float_t m_delta, m_currentTime, m_lastTime;

    #if SCENE_SELECTOR == ENABLE
        DebugWindow& m_debugWindow;
    #endif

        string_t m_currentSceneName;
        Scene* m_currentScene;
        std::unordered_map<string_t, Scene*> m_scenes;

        bool sceneExists(const string_t& t_name);

    #if SCENE_SELECTOR == ENABLE
        void drawSceneSelector();
    #endif

    };

}

#endif /* SCENE_CONTROLLER_HPP */
