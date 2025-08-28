#include "lib/Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle() { std::cout << "Creating rectangle" << std::endl; }
Rectangle::~Rectangle() { std::cout << "Destroying rectangle" << std::endl; }
void Rectangle::render() { std::cout << "Rendering rectangle" << std::endl; }
