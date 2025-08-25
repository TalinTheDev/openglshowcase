#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace ImGui;

void runImGui() {
  ImGuiIO &io = ImGui::GetIO();
  if (showDebugWindow) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (Begin("Debug Window", nullptr, ImGuiWindowFlags_MenuBar)) {
      Text("Application average %.3f ms/frame (%.1f FPS)",
           1000.0f / io.Framerate, io.Framerate);
    }
    End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }
}
