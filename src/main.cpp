#include "engine/window_context.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw_gl3.h>

int main(void)
{
 
    WindowContext window( WindowContextSettings{1280, 720, "The Wonders of Mazalt", 1, {4,5} } );

    ImGui::CreateContext();
    window.claim([](window_tp* w){ ImGui_ImplGlfwGL3_Init(w, true); });
    ImGui::StyleColorsDark();

    /* Loop until the user closes the window */
    while (!window.isClosed())
    {
        window.clear();
        ImGui_ImplGlfwGL3_NewFrame();

        ImGui::Text("Hello, world!");                           

        ImGui::Render();
	    ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

        window.flush();
    }

    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    return 0;
}


