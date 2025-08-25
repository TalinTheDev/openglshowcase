#include "tests/triangle.cpp"
#include "types.hpp"
#include <glm/glm.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace ImGui;

ImGuiWindowFlags windowFlags =
    ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoMove | ImGuiWindowFlags_MenuBar |
    ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoDocking |
    ImGuiWindowFlags_NoBackground;

void runImGui() {
  ImGuiIO &io = ImGui::GetIO();
  if (state.showDebugWindow) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    SetNextWindowPos(ImVec2(0, 0));
    SetNextWindowSize(ImVec2(state.width, state.debugHeight));
    if (Begin("Debug Window", nullptr, windowFlags)) {
      if (BeginMenuBar()) {
        if (BeginMenu("General")) {
          Text("Clear Color: ");
          ColorEdit4("Clear Color", (float *)&state.clearColor,
                     ImGuiColorEditFlags_Float);
          EndMenu();
        }
        if (BeginMenu("Examples")) {
          if (ImGui::MenuItem("Reset", NULL)) {
            state.currentExample = None;
          }
          if (BeginMenu("Triangle")) {
            if (MenuItem("Toggle", NULL)) {
              if (state.currentExample == Triangle) {
                state.currentExample = None;
              } else {
                state.currentExample = Triangle;
              }
            }
            ColorEdit4("Triangle Color", (float *)&triangleState.color,
                       ImGuiColorEditFlags_Float);
            EndMenu();
          }
          EndMenu();
        }

        SameLine(state.width - 350);
        Text("Application average %.3f ms/frame (%.1f FPS)",
             1000.0f / io.Framerate, io.Framerate);
        EndMenuBar();
      }
    }
    End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }
}
