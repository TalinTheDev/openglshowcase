#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
  Object() = default;
  virtual ~Object() = default;
  virtual void render() = 0;
};

#endif
