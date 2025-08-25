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

extern const unsigned int DEBUG_HEIGHT;
extern bool showDebugWindow;
extern glm::vec4 clearColor;
extern Tests tests;
extern Tests currentTest;

void runImGui() {
  ImGuiIO &io = ImGui::GetIO();
  if (showDebugWindow) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    SetNextWindowPos(ImVec2(0, 0));
    SetNextWindowSize(ImVec2(WIDTH, DEBUG_HEIGHT));
    if (Begin("Debug Window", nullptr, windowFlags)) {
      if (BeginMenuBar()) {
        if (BeginMenu("General")) {
          Text("Clear Color: ");
          ColorEdit4("", (float *)&clearColor, ImGuiColorEditFlags_Float);
          EndMenu();
        }
        if (BeginMenu("Tests")) {
          if (ImGui::MenuItem("Reset", NULL)) {
            currentTest = (Tests)0;
          }
          if (ImGui::MenuItem("Triangle", NULL)) {
            currentTest = Tests::Triangle;
          }
          EndMenu();
        }

        SameLine(WIDTH - 350);
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
