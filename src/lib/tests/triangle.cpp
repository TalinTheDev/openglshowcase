#ifndef TRIANGLE_H
#define TRIANGLE_H

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <glm/ext.hpp>
#include <glm/glm.hpp>

bool first = true;
GLuint shaderProgram;
GLuint VBO, VAO;
struct {
  glm::vec4 color = glm::vec4(0.9f, 0.4f, 0.3f, 1.0f);
} triangleState;

void setupTriangle() {
  if (first) {
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
    float vertices[] = {0.0f, 0.5f, 0.0f,  -0.5f, -0.5f,
                        0.0f, 0.5f, -0.5f, 0.0f};

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Vertex position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)0);
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
    first = false;
  }
}

void triangle() {
  setupTriangle();
  glUseProgram(shaderProgram);

  glUniform4f(glGetUniformLocation(shaderProgram, "color"),
              triangleState.color.r, triangleState.color.g,
              triangleState.color.b, triangleState.color.a);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

#endif
