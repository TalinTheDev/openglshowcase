// clang-format off
#include <GLFW/glfw3.h>
// clang-format on

extern bool showDebugWindow;
int debugShownTime = 0;

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }

  if (glfwGetKey(window, GLFW_KEY_BACKSLASH) == GLFW_PRESS &&
      debugShownTime > 10) {
    showDebugWindow = !showDebugWindow;
    debugShownTime = 0;
  }
  debugShownTime++;
}
