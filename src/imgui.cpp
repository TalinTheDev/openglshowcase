#include "lib/types.hpp"
#include <glm/glm.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <memory>
#include <vector>

using namespace ImGui;

void runImGui() {
  ImGuiIO &io = ImGui::GetIO();
  if (ogs::showDebugWindow) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    SetNextWindowPos(ImVec2(0, 0));
    SetNextWindowSize(ImVec2(ogs::width, ogs::debugHeight));
    if (Begin("Debug Window", nullptr, ogs::windowFlags)) {
      if (BeginMenuBar()) {
        if (BeginMenu("General")) {
          Text("Clear Color: ");
          ColorEdit4("Clear Color", (float *)&ogs::clearColor,
                     ImGuiColorEditFlags_Float);
          EndMenu();
        }
        if (BeginMenu("Examples")) {
          if (ImGui::MenuItem("Reset", NULL)) {
          }
          if (BeginMenu("Triangle")) {
            if (MenuItem("Toggle", NULL)) {
            }
            EndMenu();
          }
          EndMenu();
        }

        SameLine(ogs::width - 350);
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
