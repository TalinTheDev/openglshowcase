#ifndef TYPES_H
#define TYPES_H
#include "lib/Object.hpp"
#include <glm/glm.hpp>
#include <imgui.h>
#include <memory>
#include <vector>

namespace ogs {
extern unsigned int objectCounter;
extern unsigned int width;
extern unsigned int height;
extern unsigned int debugHeight;
extern unsigned int debugWidth;
extern bool showDebugWindow;
extern unsigned int debugShownTime;
extern glm::vec4 clearColor;
extern std::vector<std::unique_ptr<Object>> objects;
extern ImGuiWindowFlags windowFlags;
}; // namespace ogs

#endif
