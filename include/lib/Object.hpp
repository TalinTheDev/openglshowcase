#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>

class Object {
public:
  Object() = default;
  virtual ~Object() = default;
  virtual void render() = 0;
  int id;
  struct {
    glm::vec4 color;
  } state;
};

#endif
