#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include <memory>
#include <string>
#include <unordered_map>

class Object {
public:
  Object() = default;
  virtual ~Object() = default;
  virtual void render() = 0;
  int id;
  std::unordered_map<std::string, std::unique_ptr<glm::vec4>> state;
};

#endif
