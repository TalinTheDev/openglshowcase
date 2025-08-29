// clang-format off
#include <GLFW/glfw3.h>
// clang-format on
#include "lib/input.hpp"
#include "lib/types.hpp"

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }

  if (glfwGetKey(window, GLFW_KEY_BACKSLASH) == GLFW_PRESS &&
      ogs::debugShownTime > 10) {
    ogs::showDebugWindow = !ogs::showDebugWindow;
    ogs::debugShownTime = 0;
  }
  ogs::debugShownTime++;
}
