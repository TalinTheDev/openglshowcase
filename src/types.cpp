#include "lib/types.hpp"
#include <imgui.h>

unsigned int ogs::objectCounter = 0;
unsigned int ogs::width = 1200;
unsigned int ogs::height = 700;
unsigned int ogs::debugHeight = 19;
unsigned int ogs::debugWidth = 300;
bool ogs::showDebugWindow = true;
unsigned int ogs::debugShownTime = 0;
glm::vec4 ogs::clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
std::vector<std::unique_ptr<Object>> ogs::objects = {};
ImGuiWindowFlags ogs::windowFlags =
    ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_NoDocking;
