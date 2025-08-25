// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "lib/general.cpp"
#include "lib/input.cpp"
#include "lib/imgui.cpp"
// clang-format on
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

int main() {
  GLFWwindow *window = setupApplication();
  if (window == NULL) {
    std::cout << "Issue setting up application" << std::endl;
    return -1;
  }

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    processInput(window);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    runImGui();

    glfwSwapBuffers(window);
  }

  shutdownApplication();
  return 0;
}
