// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "lib/general.cpp"
#include "lib/imgui.cpp"
#include "lib/input.cpp"
#include "lib/tests/triangle.cpp"
// clang-format on
#include <glm/glm.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

Tests currentTest;
glm::vec4 clearColor(0.0f, 0.0f, 0.0f, 1.0f);

int main() {
  GLFWwindow *window = setupApplication();
  if (window == NULL) {
    std::cout << "Issue setting up application" << std::endl;
    return -1;
  }

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    processInput(window);

    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    glClear(GL_COLOR_BUFFER_BIT);

    runImGui();
    switch (currentTest) {
    case Triangle:
      triangle();
      break;
    };

    glfwSwapBuffers(window);
  }

  shutdownApplication();
  return 0;
}
