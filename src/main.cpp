// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include "lib/general.hpp"
#include "lib/imgui.hpp"
#include "lib/input.hpp"
#include "lib/types.hpp"
#include <glm/glm.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>
#include <memory>

int main() {
  GLFWwindow *window = setupApplication();
  if (window == NULL) {
    std::cout << "Issue setting up application" << std::endl;
    return -1;
  }

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    processInput(window);

    glClearColor(ogs::clearColor.r, ogs::clearColor.g, ogs::clearColor.b,
                 ogs::clearColor.a);
    glClear(GL_COLOR_BUFFER_BIT);

    runImGui();
    for (auto &object : ogs::objects) {
      object->render();
    }

    glfwSwapBuffers(window);
  }

  shutdownApplication();
  return 0;
}
