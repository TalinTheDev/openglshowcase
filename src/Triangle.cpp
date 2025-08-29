#include "lib/Triangle.hpp"
#include <iostream>

Triangle::Triangle(int id) {
  this->id = id;
  state.color = glm::vec4(1.0, 1.0, 1.0, 1.0);
  // Vertex shader source
  const char *vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;

void main() {
    gl_Position = vec4(aPos, 1.0);
}
)";

  // Fragment shader source
  const char *fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;

uniform vec4 color;

void main() {
    FragColor = color;
}
)";
  // Triangle vertex data
  float vertices[] = {0.0f, 0.5f, 0.0f, -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f};

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Vertex position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Compile shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);

  // Link shaders
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // Cleanup
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

Triangle::~Triangle() {
  std::cout << "Destroying triangle #" << id << std::endl;
}

void Triangle::render() {
  glUseProgram(shaderProgram);
  glUniform4f(glGetUniformLocation(shaderProgram, "color"), state.color.r,
              state.color.g, state.color.b, state.color.a);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
