#include "scene_controller.hpp"
#include "../generic/logging.hpp"

namespace ly {

#if SCENE_SELECTOR == ENABLE
    SceneController::SceneController(DebugWindow& t_debugWindow):
        m_delta(0.0f), m_currentTime(0.0f), m_lastTime(0.0f),
        m_currentSceneName(""),
        m_debugWindow(t_debugWindow)
    {}
#else
    SceneController::SceneController():
        m_delta(0.0f), m_currentTime(0.0f), m_lastTime(0.0f),
        m_currentSceneName("")
    {}
#endif


    SceneController::~SceneController() {

        for (auto scene : m_scenes){
            scene.second->onExit();
        }

    }

    void SceneController::add(const string_t& t_name, Scene* t_scene) {
        if (t_scene == nullptr){ 
             std::cerr << "Unable to add scene[" << t_name << "] because it is invalid (nullptr or similar)" << std::endl;
         }

        if ( sceneExists(t_name) ){
            std::cerr << "Unable to add scene[" << t_name << "] because it already exists" << std::endl;
            return;
        }
        m_scenes.insert( std::make_pair( t_name, t_scene) );
    }

    void SceneController::remove(const string_t& t_name) {
        if ( m_currentSceneName == t_name ){
            std::cerr << "Unable to remove scene[" << t_name << "] because it is currently active" << std::endl;
            return;
        }

        if ( !sceneExists(t_name) ){
            std::cerr << "Unable to remove scene[" << t_name << "] because it does not exists" << std::endl;
            return;
        }

        m_scenes[t_name]->onExit();
        m_scenes.erase( t_name );

    }

    void SceneController::select(const string_t& t_name) {

        if ( m_currentSceneName == t_name ){
            std::cerr << "Unable to re-select scene[" << t_name << "] because scene " << m_currentSceneName << "it is currently active" << std::endl;
            return;
        }
        
        if ( !sceneExists(t_name) ){
            std::cerr << "Unable to select scene[" << t_name << "] because it does not exists" << std::endl;
            return;
        }
        if ( m_scenes.size() > 1 && m_currentSceneName != "" ){ 
            m_scenes[m_currentSceneName]->onExit();
            m_scenes[t_name]->onEntry(); 
        }
        m_currentSceneName = t_name;
        m_currentScene = m_scenes[t_name];
    }

    std::string SceneController::getActiveScene() {
        return m_currentSceneName;
    }

    void SceneController::run() {
        if( m_currentSceneName != ""){
            m_currentTime = glfwGetTime();
            m_delta = m_currentTime - m_lastTime;
            m_lastTime = m_currentTime;

            m_currentScene->onUpdate(m_delta);
        }

    #if SCENE_SELECTOR == ENABLE
        drawSceneSelector();
    #endif

    }

    bool SceneController::sceneExists(const string_t& t_name) {
        for( const auto& scene: m_scenes ){
            if ( scene.first == t_name ) { return true; }
        }
        return false;
    }

#if SCENE_SELECTOR == ENABLE
    void SceneController::drawSceneSelector() {

        m_debugWindow.drawStart("Scene Selector");
        m_debugWindow.drawText("Select a Scene");
    
        for( const auto& scene: m_scenes ){
            bool pressed = m_debugWindow.drawButton( scene.first.c_str() );
            if ( pressed ){ select( scene.first ); } 
        }         

        m_debugWindow.drawEnd();
    }
#endif

}


