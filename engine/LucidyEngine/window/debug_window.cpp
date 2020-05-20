#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw_gl3.h>

#include "debug_window.hpp"
#include "../generic/logging.hpp"

namespace ly{

    DebugWindow::DebugWindow(Window& t_window):
        m_window( t_window )
    {}

    DebugWindow::~DebugWindow() {
        close();
    }

    void DebugWindow::open() {
        ImGui::CreateContext();
        m_window.claim( [](window_t* w){ ImGui_ImplGlfwGL3_Init(w, true); } );
        ImGui::StyleColorsDark();
    }

    void DebugWindow::close() {
        ImGui_ImplGlfwGL3_Shutdown();
        ImGui::DestroyContext();
        std::cout << "Sucessfully destroyed Debug Window" << std::endl;
    }

    void DebugWindow::clear() {
        ImGui_ImplGlfwGL3_NewFrame();
    }

    void DebugWindow::flush() {
        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void DebugWindow::drawStart(cstring_t t_menuName) {
        ImGui::Begin( t_menuName );
    }

    void DebugWindow::drawEnd() {
        ImGui::End();
    }

    void DebugWindow::drawText(cstring_t t_text) {
        ImGui::Text( t_text );
    }

    bool DebugWindow::drawButton(cstring_t t_name) {
        return ImGui::Button( t_name ) ;
    }

}
