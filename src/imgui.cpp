#include "lib/Triangle.hpp"
#include "lib/types.hpp"
#include <format>
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
              ogs::objects.push_back(
                  std::make_unique<Triangle>(ogs::objectCounter++));
            }
            EndMenu();
          }
          EndMenu();
        }
        if (BeginMenu("Debug")) {
          if (BeginTable("Objects", 3, 0)) {
            TableSetupColumn("ID");
            TableSetupColumn("Color");
            TableSetupColumn("Delete");
            TableHeadersRow();
            for (auto &object : ogs::objects) {
              TableNextRow();
              TableSetColumnIndex(0);
              TextUnformatted(std::format("#{}", object->id).c_str());
              TableSetColumnIndex(1);
              ColorEdit4(std::format("#{} Color", object->id).c_str(),
                         (float *)&object->state.color,
                         ImGuiColorEditFlags_Float);
              TableSetColumnIndex(2);
              if (Button(std::format("Delete #{}", object->id).c_str())) {
                ogs::objects.erase(ogs::objects.begin() + object->id);
              }
            }
            EndTable();
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
