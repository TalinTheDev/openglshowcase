#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Object.hpp"

class Triangle : public Object {
public:
  Triangle();
  ~Triangle();
  void render() override;
};

#endif
