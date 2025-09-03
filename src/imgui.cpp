#include "lib/Triangle.hpp"
#include "lib/types.hpp"
#include <format>
#include <glm/glm.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <memory>

using namespace ImGui;

void runImGui() {
  ImGuiIO &io = ImGui::GetIO();
  if (ogs::showDebugWindow) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    SetNextWindowPos(ImVec2(0, 0));
    SetNextWindowSize(ImVec2(ogs::debugWidth, ogs::height));
    if (Begin("Debug Window", nullptr, ogs::windowFlags)) {
      SeparatorText("General");
      Text("Clear Color: ");
      ColorEdit4("Clear Color", (float *)&ogs::clearColor,
                 ImGuiColorEditFlags_Float);

      SeparatorText("Examples");
      if (MenuItem("Add Triangle", NULL)) {
        unsigned int id = ++ogs::objectCounter;
        ogs::objects.insert({id, std::make_unique<Triangle>(id)});
      }

      SeparatorText("Objects");
      if (ogs::objects.empty()) {
        Text("Zero Objects in Scene");
      }
      if (!ogs::objects.empty()) {
        if (BeginTable("Objects", 3, 0)) {
          TableSetupColumn("ID");
          TableSetupColumn("Color");
          TableSetupColumn("Delete");
          TableHeadersRow();
          for (auto object = ogs::objects.begin();
               object != ogs::objects.end();) {
            TableNextRow();
            TableSetColumnIndex(0);
            TextUnformatted(std::format("#{}", object->first).c_str());
            TableSetColumnIndex(1);
            ColorEdit4(std::format("#{} Color", object->first).c_str(),
                       (float *)object->second->state["color"].get(),
                       ImGuiColorEditFlags_Float);
            TableSetColumnIndex(2);
            if (Button(std::format("Delete #{}", object->first).c_str())) {
              object = ogs::objects.erase(object);
            } else {
              ++object;
            }
          }
          EndTable();
        }
      }

      SeparatorText("Debug Info");
      Text(" %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    }
    End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }
}
