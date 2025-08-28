#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Object.hpp"

class Rectangle : public Object {
public:
  Rectangle();
  ~Rectangle();
  void render() override;
};

#endif
