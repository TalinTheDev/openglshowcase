#ifndef TRIANGLE_H
#define TRIANGLE_H
// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include "Object.hpp"
#include <glm/glm.hpp>

class Triangle : public Object {
public:
  struct {
    glm::vec4 color;
  } state;

  Triangle();
  ~Triangle();
  void render() override;

private:
  GLuint shaderProgram;
  GLuint VBO, VAO;
};

#endif
