#include "lib/Triangle.hpp"
#include <iostream>

Triangle::Triangle() { std::cout << "Creating triangle" << std::endl; }
Triangle::~Triangle() { std::cout << "Destroying triangle" << std::endl; }
void Triangle::render() { std::cout << "Rendering triangle" << std::endl; }
