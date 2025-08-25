#ifndef TYPES_H
#define TYPES_H
#include <glm/glm.hpp>

enum Examples {
  None,
  Triangle,
};

struct {
  unsigned int width = 1200;
  unsigned int height = 700;
  unsigned int debugHeight = 19;
  bool showDebugWindow = true;
  Examples currentExample = None;
  glm::vec4 clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
} state;

#endif
