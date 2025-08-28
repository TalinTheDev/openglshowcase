#include "lib/Object.hpp"
#include <iostream>

Object::Object() { std::cout << "Created object" << std::endl; }
Object::~Object() { std::cout << "Destroyed object" << std::endl; }
void Object::render() { std::cout << "Rendering object" << std::endl; }
