#ifndef SYSTEM_H
#define SYSTEM_H

#include <glm/glm.hpp>
#include <memory>
#include <string>
#include <unordered_map>

class System {
public:
  System() = default;
  virtual ~System() = default;
  virtual void run() = 0;
  int id;
  std::unordered_map<std::string, std::unique_ptr<glm::vec4>> state;
};

#endif
