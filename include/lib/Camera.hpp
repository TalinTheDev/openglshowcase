#ifndef CAMERA_H
#define CAMERA_H
// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include "System.hpp"
#include <glm/glm.hpp>

class Camera : public System {
public:
  Camera(int id);
  ~Camera();
  void run() override;
};

#endif
